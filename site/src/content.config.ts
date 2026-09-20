import { defineCollection } from 'astro:content';
import { glob } from 'astro/loaders';
import { z } from 'astro/zod';

/**
 * 博文系列（内容类型维度），与主题标签区分：
 * 系列回答「这是哪种内容」（刷题日志 / 周赛题解 / 论文阅读），
 * 标签回答「讲什么主题」（leetcode / network / react …）。
 * 非所有博文都归属系列（如未来的英文随笔），故可选。
 */
export const POST_SERIES = ['daily-coding', 'contest-solution', 'paper-reading'] as const;

/**
 * 博文集合。
 *
 * 内容源是 `site/src/posts/` 下的 Markdown —— Markdown 是唯一事实来源，
 * 站点侧只读渲染，不复制、不硬编码正文。
 *
 * frontmatter 字段与内容侧约定一致：`title` / `date` / `tags` / `series` / `summary` / `draft`。
 * 另外有一个 `lang` 字段用于双语站点分流：双语各自成篇（不做同篇翻译对齐），
 * 中文与英文博文是两份独立文件，靠 `lang` 归属到对应语言的列表/归档/RSS。
 */
const posts = defineCollection({
  loader: glob({ base: './src/posts', pattern: '**/*.{md,mdx}' }),
  schema: z.object({
    title: z.string(),
    date: z.coerce.date(),
    tags: z.array(z.string()).default([]),
    /** 系列（内容类型），仅 POST_SERIES 中的值；不属于任何系列可省略。 */
    series: z.enum(POST_SERIES).optional(),
    summary: z.string(),
    draft: z.boolean().default(false),
    /** 缺省按默认语言（中文）处理。 */
    lang: z.enum(['zh', 'en']).default('zh'),
  }),
});

/**
 * 简历集合。
 *
 * 唯一事实来源是 `site/src/resumes/<handle>/README.md`（中文版）与 `README.en.md`（英文版）：
 * 一个 handle 目录一位成员的一份简历，目录名即 handle，双语各自成篇（与博文一致，不做同篇翻译对齐）。
 * 语言由文件名推导 —— `README.md` 是中文版（默认，由 `/resume/` 渲染），
 * `README.en.md` 是英文版（由 `/en/resume/` 渲染），不需要也不依赖 frontmatter 里的 lang 字段。
 * 两种版本都可独立成篇，也可只放一种语言（该语言路由走空状态）。
 *
 * 基础字段（name / title / summary / updated / draft）之外，
 * 结构化字段（contact / links / education / experience / skills / honors / languages）
 * 全部可选、逐步迁入 —— 未填的字段站点侧跳过渲染，卡片/时间轴排版由已填字段驱动。
 * 站点侧不硬编码简历内容。
 *
 * ⚠️ 公开范围门禁：本仓库是公开仓库，简历个人信息（学校 / 实习 / 公司细节）
 * 进公开仓库前必须由成员本人确认并脱敏。结构化字段只定义契约，内容迁入另行执行。
 */
const resumes = defineCollection({
  // 只认 README.md 与 README.en.md 两个文件名，其余（README.backup.md 等）不进集合。
  // 默认的 id 生成会对文件名做 slug 归一（README.en.md → readmeen，丢掉语言信息），
  // 所以用「相对 base 的路径」原样做 id，utils 侧才能靠 `.en.md` 后缀判语言。
  loader: glob({
    base: './src/resumes',
    pattern: ['*/README.md', '*/README.en.md'],
    generateId: ({ entry }) => entry,
  }),
  schema: z.object({
    name: z.string().optional(),
    title: z.string().optional(),
    summary: z.string().optional(),
    updated: z.coerce.date().optional(),
    draft: z.boolean().default(false),
    /** 联系方式头（供简历页顶部渲染）：邮箱、常驻地等，全部可选。 */
    contact: z
      .object({
        email: z.string().optional(),
        location: z.string().optional(),
      })
      .optional(),
    /** 社交链接（GitHub / LinkedIn / LeetCode …）：label + url 成对。 */
    links: z
      .array(
        z.object({
          label: z.string(),
          url: z.string(),
        }),
      )
      .optional(),
    /** 教育经历。 */
    education: z
      .array(
        z.object({
          school: z.string(),
          degree: z.string().optional(),
          period: z.string().optional(),
          highlight: z.string().optional(),
        }),
      )
      .optional(),
    /** 工作 / 实习经历。 */
    experience: z
      .array(
        z.object({
          company: z.string(),
          role: z.string().optional(),
          period: z.string().optional(),
          bullets: z.array(z.string()).optional(),
        }),
      )
      .optional(),
    /** 专业技能，按类别分组（熟悉 / 掌握 / 了解等）。 */
    skills: z
      .array(
        z.object({
          category: z.string(),
          items: z.array(z.string()),
        }),
      )
      .optional(),
    /** 荣誉 / 奖项。 */
    honors: z
      .array(
        z.object({
          name: z.string(),
          detail: z.string().optional(),
          date: z.coerce.date().optional(),
        }),
      )
      .optional(),
    /** 语言能力。 */
    languages: z
      .array(
        z.object({
          name: z.string(),
          level: z.string().optional(),
        }),
      )
      .optional(),
  }),
});

/**
 * 项目集合。
 *
 * 内容源是 `site/src/projects/<slug>/README.md` —— 一个目录一个项目，目录名即 slug，
 * 布局与简历集合一致（顶层 `README.md` 是约定文档，不被 glob 命中）。
 * 承接仓库根目录的三条内容线（ACM-ICPC / Learning / TongjiClasses）。
 *
 * 条目只存元信息（title / summary / repo / tech / highlight），
 * 正文以仓库既有内容为单一事实来源，站点侧不复制正文。
 * 约定见 `site/src/projects/README.md`。
 */
const projects = defineCollection({
  loader: glob({ base: './src/projects', pattern: '*/README.md' }),
  schema: z.object({
    title: z.string(),
    summary: z.string(),
    /** 仓库链接：仓库内相对路径（如 /ACM-ICPC/）或 GitHub URL；无仓库可省略。 */
    repo: z.string().optional(),
    tech: z.array(z.string()).default([]),
    /** 精选标记：true 时进入首页「精选项目」等聚合位置。 */
    highlight: z.boolean().default(false),
  }),
});

export const collections = { posts, resumes, projects };
