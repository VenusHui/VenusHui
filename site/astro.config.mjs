// @ts-check
import { defineConfig } from 'astro/config';
import sitemap from '@astrojs/sitemap';
import tailwindcss from '@tailwindcss/vite';

// 站点发布在 GitHub Pages 的项目子路径下，`site` 与 `base` 必须成对配置。
// 关键约定：站内链接与静态资源引用一律经过 src/utils/url.ts 的 withBase()，
// 组件里禁止写死根路径 `/`（写死会在 /VenusHui/ 下 404，是本项目最容易踩的坑）。
export default defineConfig({
  site: 'https://venushui.github.io',
  base: '/VenusHui/',
  i18n: {
    locales: ['zh', 'en'],
    // 默认中文：中文页面不带语言前缀，英文页面在 /en/ 下。
    defaultLocale: 'zh',
    routing: {
      prefixDefaultLocale: false,
      redirectToDefaultLocale: false,
    },
  },
  integrations: [sitemap()],
  markdown: {
    shikiConfig: {
      // 代码块跟随站点主题，而不是恒用深色：浅色 github-light、深色 github-dark。
      // 双主题会输出 --shiki-light / --shiki-dark 变量，切换规则在 global.css 里。
      themes: { light: 'github-light', dark: 'github-dark' },
    },
  },
  vite: {
    plugins: [tailwindcss()],
  },
});
