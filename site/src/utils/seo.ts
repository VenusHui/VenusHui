/**
 * JSON-LD（schema.org 结构化数据）构造。
 *
 * 输出格式固定在 `BaseLayout` 的 `jsonLd` prop：这里只负责「页面语义 → 对象」，
 * 序列化与 `<script>` 注入由布局层做，页面侧不直接写 `<script>` 标签。
 *
 * 为什么值得做：Google 用这些字段生成富结果（作者卡片、文章时间线），
 * `sameAs` 还能把站点与 GitHub / LeetCode / Codeforces 账号判为同一实体，
 * 是「个人品牌站点」里性价比最高的一项 SEO 标注。
 */
import { AUTHOR, GITHUB_PROFILE, PROFILE_LINKS } from '../consts';
import type { Locale } from '../i18n/ui';
import type { Post } from './posts';

/**
 * `Person`：站点作者本人。用于首页与简历页 —— 这两页回答的是
 * 「这是谁」，而不是「这是哪篇文章」。
 *
 * @param name 姓名；简历有 `name` 字段时用简历里的，否则回退站点作者名。
 * @param url 本页 canonical 地址（由 `canonicalUrl()` 得到）。
 */
export function personJsonLd({ name, url }: { name?: string; url: string }) {
  return {
    '@context': 'https://schema.org',
    '@type': 'Person',
    name: name ?? AUTHOR,
    url,
    /** GitHub / LeetCode / Codeforces 账号，声明「这些主页是同一个人」。 */
    sameAs: PROFILE_LINKS,
  };
}

/**
 * `BlogPosting`：博文详情页。
 *
 * @param post 博文条目，字段全部取自 frontmatter（Markdown 是唯一事实来源）。
 * @param url 本页 canonical 地址。
 * @param image 分享图绝对地址（全站默认 OG 图）。
 */
export function blogPostingJsonLd({
  post,
  url,
  image,
  locale,
}: {
  post: Post;
  url: string;
  image: string;
  locale: Locale;
}) {
  const { title, summary, date, tags } = post.data;
  return {
    '@context': 'https://schema.org',
    '@type': 'BlogPosting',
    headline: title,
    description: summary,
    datePublished: date.toISOString(),
    keywords: tags,
    image,
    url,
    mainEntityOfPage: { '@type': 'WebPage', '@id': url },
    inLanguage: locale === 'zh' ? 'zh-CN' : 'en',
    author: { '@type': 'Person', name: AUTHOR, url: GITHUB_PROFILE },
  };
}
