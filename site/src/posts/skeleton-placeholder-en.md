---
title: Skeleton placeholder post
date: 2026-09-18
tags: [site, Astro]
summary: A placeholder post added while scaffolding the Astro site, used to verify that collections, lists, tags and detail pages build; it will be replaced by real content once migration starts.
draft: false
lang: en
---

This is a **placeholder post** in the `site/` skeleton, used only to verify the build pipeline. It is not real content.

It exercises:

- the `posts` collection frontmatter contract (`title` / `date` / `tags` / `summary` / `draft` / `lang`)
- post list, tag aggregation, archive, RSS and detail page rendering
- internal links and static asset references under the `/VenusHui/` base path

## Code and layout

Inline code such as `npm run build`, and a fenced block:

```bash
cd site
npm install
npm run build
```

> A blockquote, to check contrast in dark mode.

This placeholder will be removed once content migration begins.
