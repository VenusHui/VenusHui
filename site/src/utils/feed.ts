// RSS 按语言各出一份：中文 /rss.xml，英文 /en/rss.xml。
// 条目链接用绝对地址，频道链接指向该语言首页，因此 site 传语言首页而不是站点根。
import rss from '@astrojs/rss';
import type { APIRoute } from 'astro';
import { RSS_ITEM_LIMIT } from '../consts';
import type { Locale } from '../i18n/ui';
import { localePath, t } from '../i18n/utils';
import { getPosts, postPath } from '../utils/posts';

export function buildFeed(locale: Locale): APIRoute {
  return async (context) => {
    const origin = context.site ?? new URL('https://venushui.github.io');
    const posts = (await getPosts(locale)).slice(0, RSS_ITEM_LIMIT);

    return rss({
      title: t(locale, 'site.title'),
      description: t(locale, 'site.description'),
      site: new URL(localePath(locale), origin),
      items: posts.map((post) => ({
        title: post.data.title,
        description: post.data.summary,
        pubDate: post.data.date,
        categories: post.data.tags,
        link: new URL(postPath(post), origin).href,
      })),
      customData: `<language>${locale === 'zh' ? 'zh-cn' : 'en'}</language>`,
    });
  };
}
