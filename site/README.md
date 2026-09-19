# VenusHui 站点

VenusHui 个人站点的前端工程：简历（resume）、个人网站（portfolio）、博文（blog）三合一。
Astro + Tailwind CSS + TypeScript，输出纯静态资源，部署在 GitHub Pages 的项目子路径下。

- 线上地址：https://venushui.github.io/VenusHui/
- **base path 是 `/VenusHui/`** —— 站内链接与静态资源引用必须走 base，见下文。

## 命令

```bash
cd site
npm install
npm run dev          # 本地开发，http://localhost:4321/VenusHui/
npm run build        # 构建静态产物到 site/dist/
npm run preview      # 预览构建产物
npm run check        # astro check：类型与 .astro 诊断
npm run format       # prettier 写入
npm run format:check # prettier 校验（CI 用）
```

本地 dev 也带 base，所以本地路径同样是 `http://localhost:4321/VenusHui/`。

## 目录结构

```text
site/
├── astro.config.mjs        # site / base / i18n / tailwind / sitemap
├── src/
│   ├── consts.ts           # 站点级常量
│   ├── content.config.ts   # 内容集合 schema（posts / resumes）
│   ├── i18n/               # 文案表、语言工具、RSS 路径
│   ├── utils/url.ts        # base path 收口点（withBase / stripBase）
│   ├── utils/posts.ts      # 博文查询、排序、标签与年份聚合、日期格式化
│   ├── layouts/BaseLayout.astro
│   ├── components/         # Header / Footer / 主题与语言切换 / 列表卡片
│   ├── components/views/   # 页面级视图，两种语言的路由共用
│   ├── pages/              # 中文路由（默认语言，不带前缀）
│   │   └── en/             # 英文路由（/en/...）
│   ├── posts/              # 博文 Markdown（唯一事实来源）
│   ├── resumes/            # 简历 Markdown，<handle>/README.md
│   └── styles/global.css   # Tailwind 入口与主题变量
└── public/                 # 原样拷贝的静态资源
```

## base path 约定（最重要的坑）

站点是**项目站点**，发布在 `/VenusHui/` 子路径下，写死根路径 `/` 的资源在线上必然 404。

- 站内页面链接：用 `localePath(locale, 'posts/')`（`src/i18n/utils.ts`）。
- 静态资源 / 文件：用 `withBase('favicon.svg')`（`src/utils/url.ts`）。
- **不要在组件里写 `href="/..."` 或 `src="/..."`。**

`import.meta.env.BASE_URL` 由 `astro.config.mjs` 的 `base` 注入，构建与本地 dev 一致。

## 多语言

- 默认中文：中文页面在站点根（`/posts/`），英文页面在 `/en/` 下（`/en/posts/`）。
- 文案集中在 `src/i18n/ui.ts`，页面侧一律 `t(locale, key)`，不写死文案；
  新增语言时补一份文案表即可，缺键会在 `npm run check` 报错。
- 路由按语言各写一份薄壳（`src/pages/**` 与 `src/pages/en/**`），页面主体放在
  `src/components/views/` 里由两种语言共用，不在路由层复制逻辑。
- 博文不做同篇翻译对齐：中英各是独立文件，靠 frontmatter 的 `lang` 归属语言。

## 内容

博文与简历都以 Markdown 为唯一事实来源，站点侧只读渲染，不复制、不硬编码。

博文 frontmatter（`src/posts/*.md`）：

| 字段      | 必填 | 说明                                        |
| --------- | ---- | ------------------------------------------- |
| `title`   | 是   | 标题                                        |
| `date`    | 是   | 发布日期，`YYYY-MM-DD`                      |
| `tags`    | 否   | 标签数组，缺省为空                          |
| `summary` | 是   | 摘要，用于列表与 SEO description            |
| `draft`   | 否   | `true` 时只在本地 dev 可见，不进构建产物    |
| `lang`    | 否   | `zh`（默认）或 `en`，决定归入哪种语言的列表 |

简历（`src/resumes/<handle>/README.md`）一个目录一篇，字段全部可选，待内容迁入后按实际字段收紧。

## 主题

浅色 / 深色由 `<html>` 上的 `dark` 类驱动（Tailwind v4 的 `@custom-variant dark`），
首屏绘制前的内联脚本负责防闪烁，偏好存在 `localStorage.theme`，未设置时跟随系统。

全站唯一的 JS 就是这个主题切换脚本（约 15 行，`is:inline`）。其余均为静态 HTML + CSS，没有任何框架运行时。
