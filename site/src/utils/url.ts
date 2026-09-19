/**
 * base path 收口点。
 *
 * 站点发布在 https://venushui.github.io/VenusHui/ —— 项目站点，构建带 base `/VenusHui/`。
 * `import.meta.env.BASE_URL` 由 astro.config 的 `base` 注入，恒为「以 / 开头且以 / 结尾」
 * （构建与本地 dev 一致）。站内一切链接、静态资源引用都必须经由本模块，
 * 不要在任何组件里拼接根路径 `/`。
 */
const BASE = import.meta.env.BASE_URL;

/**
 * 把站内路径转成带 base 的绝对路径。
 *
 * @param path 相对站点根的路径，前导 `/` 可有可无，例如 `posts/`、`/favicon.svg`。
 * @returns 带 base 的路径，例如 `/VenusHui/posts/`；传空串得到站点根 `/VenusHui/`。
 */
export function withBase(path = ''): string {
  const clean = path.replace(/^\/+/, '');
  return clean ? `${BASE}${clean}` : BASE;
}

/**
 * 去掉路径上的 base 前缀，得到相对站点根的路径。
 *
 * @param pathname `Astro.url.pathname`，例如 `/VenusHui/en/posts/`。
 * @returns 例如 `en/posts/`。
 */
export function stripBase(pathname: string): string {
  if (pathname.startsWith(BASE)) return pathname.slice(BASE.length);
  // base 为 `/` 时（例如未配置 base 的兜底场景）退化为去掉前导斜杠。
  return pathname.replace(/^\/+/, '');
}
