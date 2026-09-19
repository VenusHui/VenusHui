import { defineCollection } from 'astro:content';
import { glob } from 'astro/loaders';
import { z } from 'astro/zod';

/**
 * 博文集合。
 *
 * 内容源是 `site/src/posts/` 下的 Markdown —— Markdown 是唯一事实来源，
 * 站点侧只读渲染，不复制、不硬编码正文。
 *
 * frontmatter 字段与内容侧约定一致：`title` / `date` / `tags` / `summary` / `draft`。
 * 另外有一个 `lang` 字段用于双语站点分流：双语各自成篇（不做同篇翻译对齐），
 * 中文与英文博文是两份独立文件，靠 `lang` 归属到对应语言的列表/归档/RSS。
 */
const posts = defineCollection({
  loader: glob({ base: './src/posts', pattern: '**/*.{md,mdx}' }),
  schema: z.object({
    title: z.string(),
    date: z.coerce.date(),
    tags: z.array(z.string()).default([]),
    summary: z.string(),
    draft: z.boolean().default(false),
    /** 缺省按默认语言（中文）处理。 */
    lang: z.enum(['zh', 'en']).default('zh'),
  }),
});

/**
 * 简历集合。
 *
 * 唯一事实来源是 `site/src/resumes/<handle>/README.md`：一个目录一篇简历，目录名即 handle。
 * 字段全部可选 —— 简历 frontmatter 由内容侧确定，这里先保证「有什么都能过」，
 * 待内容迁入后再按实际字段收紧。站点侧不硬编码简历内容。
 */
const resumes = defineCollection({
  loader: glob({ base: './src/resumes', pattern: '*/README.md' }),
  schema: z.object({
    name: z.string().optional(),
    title: z.string().optional(),
    summary: z.string().optional(),
    updated: z.coerce.date().optional(),
    draft: z.boolean().default(false),
  }),
});

export const collections = { posts, resumes };
