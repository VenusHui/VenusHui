import { stripBase, withBase } from '../utils/url';
import { defaultLocale, locales, ui, type Locale, type UIKey } from './ui';

/** 类型守卫：把任意字符串收窄成受支持的 Locale。 */
export function isLocale(value: string): value is Locale {
  return (locales as readonly string[]).includes(value);
}

/**
 * 去掉 base 与语言前缀，得到「相对站点根、且不含语言前缀」的路径。
 * `/VenusHui/en/posts/` → `posts/`；`/VenusHui/` → `''`。
 *
 * hreflang 备用链接与语言切换都基于这个值构路径，因此它必须同时处理 base 与语言前缀。
 */
export function localeRelativePath(pathname: string): string {
  return stripBase(pathname).replace(/^en(\/|$)/, '');
}

/** 从 `Astro.url.pathname` 判断当前页面语言。走 base 与语言前缀的收口逻辑，不直接切字符串。 */
export function getLocaleFromPath(pathname: string): Locale {
  const [first] = stripBase(pathname).split('/');
  return first && isLocale(first) ? first : defaultLocale;
}

/**
 * 构造某个语言下某个页面带 base 的路径（统一带尾斜杠，与构建产物的目录格式一致）。
 *
 * @param locale 目标语言。
 * @param path 不含语言前缀的相对路径，例如 `posts/hello-world/`；空串表示该语言首页。
 */
export function localePath(locale: Locale, path = ''): string {
  const clean = path.replace(/^\/+/, '').replace(/\/+$/, '');
  const segments = locale === defaultLocale ? [clean] : [locale, clean];
  return withBase(`${segments.filter(Boolean).join('/')}/`);
}

/** 同一页面在另一种语言下的路径，用于语言切换。只对两种语言都存在的页面使用。 */
export function swapLocalePath(pathname: string): string {
  const locale = getLocaleFromPath(pathname);
  const target: Locale = locale === defaultLocale ? 'en' : defaultLocale;
  return localePath(target, localeRelativePath(pathname));
}

/** 取某个语言下的文案；缺键时回退到默认语言（正常情况由类型检查挡住）。 */
export function t(locale: Locale, key: UIKey): string {
  return ui[locale][key] ?? ui[defaultLocale][key];
}

/** 绑定语言后的取词函数，页面里写 `const tr = useTranslations(locale); tr('nav.posts')`。 */
export function useTranslations(locale: Locale): (key: UIKey) => string {
  return (key) => t(locale, key);
}
