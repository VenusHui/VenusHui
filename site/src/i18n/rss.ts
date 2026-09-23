import { withBase } from '../utils/url';
import type { Locale } from './ui';

/** RSS 是文件而不是目录，不能走 `localePath`（那个会补尾斜杠），单独收口。 */
export function rssPath(locale: Locale): string {
  return withBase(locale === 'zh' ? 'rss.xml' : `${locale}/rss.xml`);
}
