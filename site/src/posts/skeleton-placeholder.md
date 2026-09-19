---
title: 站点骨架占位博文
date: 2026-09-19
tags: [站点, Astro]
summary: 这是搭建 Astro 骨架时放入的占位博文，用于验证内容集合、列表、标签与详情页能正常构建；内容迁移开始后会被真实博文替换。
draft: false
lang: zh
---

这是 `site/` 骨架的**占位博文**，只用来验证构建链路，不是真实内容。

它验证的东西：

- 内容集合 `posts` 的 frontmatter 契约（`title` / `date` / `tags` / `summary` / `draft` / `lang`）
- 博文列表、标签聚合、归档、RSS 与详情页的渲染
- base path `/VenusHui/` 下的站内链接与静态资源引用

## 代码块与中文排版

行内代码 `npm run build`，以及一个代码块：

```bash
cd site
npm install
npm run build
```

> 引用块用于确认深色模式下的对比度。

内容迁移（后续任务）开始后，这篇占位文件会被删除。
