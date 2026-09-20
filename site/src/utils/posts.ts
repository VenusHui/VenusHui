import { getCollection, render, type CollectionEntry } from 'astro:content';
import type { Locale } from '../i18n/ui';
import { localePath } from '../i18n/utils';
import { includeDrafts } from './drafts';

export type Post = CollectionEntry<'posts'>;

/**
 * 渲染后的正文组件类型。从 `render()` 的返回类型推导，不写死 Astro 内部的组件类型名，
 * 这样升级 Astro 大版本时不会因为类型改名而编译失败。
 */
export type RenderedContent = Awaited<ReturnType<typeof render>>['Content'];

export interface TagGroup {
  /** 标签原文，来自 frontmatter。 */
  tag: string;
  /** 进 URL 的归一化片段。 */
  slug: string;
  posts: Post[];
}

export interface YearGroup {
  year: number;
  posts: Post[];
}

/**
 * 取某个语言下的博文，按日期倒序。
 *
 * **这是取博文的唯一入口**：语言过滤与草稿闸门都在这里，任何需要博文的地方
 * —— 列表 / 归档 / 标签 / RSS / **详情页的 getStaticPaths** —— 都必须调它，
 * 不要再自己写 `getCollection('posts', ...)`，否则会漏掉草稿闸门。
 *
 * 集合的产出顺序不确定，必须自己排序；同日再按 id 兜底，
 * 否则同一天的多篇博文在构建产物里顺序可能漂移。
 */
export async function getPosts(locale: Locale): Promise<Post[]> {
  const posts = await getCollection(
    'posts',
    ({ data }) => data.lang === locale && (includeDrafts || !data.draft),
  );
  return posts.sort(
    (a, b) => b.data.date.valueOf() - a.data.date.valueOf() || a.id.localeCompare(b.id),
  );
}

/** 博文详情页路径（带 base 与语言前缀），列表 / RSS / 详情页共用同一处拼接。 */
export function postPath(post: Post): string {
  return localePath(post.data.lang, `posts/${post.id}/`);
}

/**
 * 标签 → URL 片段。标签原文可能含 `+`、`#`、空格等不适合直接进 URL 的字符，统一归一化。
 * 中日韩字符属于 `\p{L}`，会被保留。
 */
export function tagSlug(tag: string): string {
  return tag
    .trim()
    .toLowerCase()
    .replace(/[^\p{L}\p{N}]+/gu, '-')
    .replace(/^-+|-+$/g, '');
}

/**
 * 按标签聚合，标签名排序。
 *
 * 不同标签归一化后可能撞成同一个 slug（例如 `C++` 与 `C#`），那会生成两条相同路由：
 * 这里直接报错让人改标签，而不是静默合并成一条。
 */
export function groupByTag(posts: Post[]): TagGroup[] {
  const bySlug = new Map<string, TagGroup>();
  for (const post of posts) {
    for (const tag of post.data.tags) {
      const slug = tagSlug(tag);
      if (!slug) continue;
      const existing = bySlug.get(slug);
      if (!existing) {
        bySlug.set(slug, { tag, slug, posts: [post] });
        continue;
      }
      if (existing.tag !== tag) {
        throw new Error(
          `标签「${tag}」与「${existing.tag}」归一化后同为「${slug}」，会产生冲突路由，请改用不冲突的标签名。`,
        );
      }
      existing.posts.push(post);
    }
  }
  return [...bySlug.values()].sort((a, b) => a.tag.localeCompare(b.tag));
}

/** 按年份归档：年份倒序，年内沿用传入顺序（已按日期倒序）。 */
export function groupByYear(posts: Post[]): YearGroup[] {
  const byYear = new Map<number, Post[]>();
  for (const post of posts) {
    // 用 UTC 年份，避免构建机时区把跨年边界的博文分到不同年份。
    const year = post.data.date.getUTCFullYear();
    const bucket = byYear.get(year);
    if (bucket) bucket.push(post);
    else byYear.set(year, [post]);
  }
  return [...byYear.entries()]
    .map(([year, yearPosts]) => ({ year, posts: yearPosts }))
    .sort((a, b) => b.year - a.year);
}

/** 日期展示格式。显式指定 UTC 时区，保证产物与构建机时区无关。 */
export function formatDate(date: Date, locale: Locale): string {
  return new Intl.DateTimeFormat(locale === 'zh' ? 'zh-CN' : 'en-US', {
    year: 'numeric',
    month: 'long',
    day: 'numeric',
    timeZone: 'UTC',
  }).format(date);
}

/**
 * 估算阅读时长（分钟）。中英文混排时按各自语速折算：
 * 中日韩字符按 500 字/分钟，其余按 200 词/分钟（英文常规语速）。
 * 下限 1 分钟，短篇也不会显示 0 分钟。基于 Markdown 原文统计，
 * 标点与代码符号占比不计，偏保守但足够当「阅读时长」标签用。
 */
export function readingTime(body: string | undefined): number {
  const text = body ?? '';
  const cjk = (text.match(/[぀-ヿ㐀-䶿一-鿿豈-﫿]/g) ?? []).length;
  const other = text
    .replace(/[぀-ヿ㐀-䶿一-鿿豈-﫿]/g, ' ')
    .trim()
    .split(/\s+/)
    .filter(Boolean).length;
  const minutes = cjk / 500 + other / 200;
  return Math.max(1, Math.round(minutes));
}
