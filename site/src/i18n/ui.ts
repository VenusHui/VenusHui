/**
 * 站点文案表。默认中文（zh），英文（en）为第二语言。
 *
 * 组织方式：按语言分组、用扁平的 `域.键` 命名，页面侧一律通过 `t(locale, key)` 取值，
 * 不在组件里写死文案。新增语言时在 `languages` 与 `ui` 里各加一份即可；
 * `en` 的类型是 `Record<UIKey, string>`，缺键会在 `astro check` 阶段报错。
 */
export const languages = {
  zh: '中文',
  en: 'English',
} as const;

export const locales = ['zh', 'en'] as const;

export type Locale = (typeof locales)[number];

export const defaultLocale: Locale = 'zh';

const zh = {
  'site.title': 'VenusHui',
  'site.tagline': '软件工程师 · 云原生与大数据',
  'site.description':
    '软件工程学士，曾在自动驾驶出行公司 Data-Infra 团队实习，做分布式大数据基础设施；现在专注云原生与分布式系统，平时在 Codeforces / LeetCode 上刷题。这里沉淀 ACM-ICPC 题解、CS 学习笔记与项目代码。',

  'nav.home': '首页',
  'nav.posts': '博文',
  'nav.projects': '项目',
  'nav.tags': '标签',
  'nav.archive': '归档',
  'nav.resume': '简历',
  'nav.skipToContent': '跳到正文',
  'nav.toggleTheme': '切换深浅色主题',
  'nav.themeToDark': '切换到深色模式',
  'nav.themeToLight': '切换到浅色模式',
  'nav.switchLanguage': '切换语言',
  'nav.main': '主导航',

  'home.latestPosts': '最新博文',
  'home.allPosts': '全部博文',
  'home.viewResume': '查看简历',
  'home.empty': '博文还在迁移中，稍后回来看看。',
  'home.series': '按系列浏览',
  'home.projects': '最近在做 / 项目',
  'home.viewProjects': '全部项目',
  'home.blocks.posts': '刷题题解、CS 学习笔记与论文阅读。',
  'home.blocks.resume': '教育背景、实习经历与技能栈。',
  'home.blocks.archive': '按年份回顾全部博文。',

  'posts.title': '博文',
  'posts.description': '按系列分组的全部博文。',
  'posts.empty': '还没有已发布的博文。',
  'posts.backToList': '← 返回博文列表',
  'posts.readMore': '阅读全文',
  'posts.publishedOn': '发布于',
  'posts.readingTime': '分钟阅读',
  'posts.prevInSeries': '上一篇',
  'posts.nextInSeries': '下一篇',
  'posts.seriesNav': '同系列导航',

  'tags.title': '标签',
  'tags.description': '按标签浏览博文。',
  'tags.empty': '还没有标签。',
  'tags.count': '篇',
  'tags.postsTagged': '带有标签',

  'archive.title': '归档',
  'archive.description': '按系列归档的全部博文。',
  'archive.empty': '还没有可归档的博文。',
  'archive.count': '篇',

  'projects.title': '项目',
  'projects.description': '算法训练、CS 学习笔记与课程项目的索引。',
  'projects.empty': '项目内容还在整理中，稍后回来看看。',
  'projects.viewRepo': '查看仓库',
  'series.daily-coding': '刷题日志',
  'series.contest-solution': '周赛题解',
  'series.paper-reading': '论文阅读',
  'series.uncategorized': '其他',
  'series.count': '篇',

  'resume.title': '简历',
  'resume.description': 'VenusHui 的简历。',
  'resume.empty': '简历内容尚未迁入，稍后回来看看。',
  'resume.updated': '最后更新：',

  'notFound.title': '页面不存在',
  'notFound.description': '没有找到这个页面，可能是链接过期或地址写错了。',
  'notFound.backHome': '回到首页',
  'notFound.browsePosts': '浏览博文',

  'footer.rights': '保留所有权利。',
  'footer.source': '源码',
  'footer.rss': 'RSS',
} as const;

export type UIKey = keyof typeof zh;

const en: Record<UIKey, string> = {
  'site.title': 'VenusHui',
  'site.tagline': 'Software Engineer · Cloud-Native & Big Data',
  'site.description':
    'I hold a bachelor’s in Software Engineering and interned on the Data-Infra team at a self-driving mobility company, building distributed big-data infrastructure. Now I focus on cloud-native and distributed systems, and keep practicing on Codeforces / LeetCode. This site holds my ACM-ICPC solutions, CS study notes and projects.',

  'nav.home': 'Home',
  'nav.posts': 'Blog',
  'nav.projects': 'Projects',
  'nav.tags': 'Tags',
  'nav.archive': 'Archive',
  'nav.resume': 'Resume',
  'nav.skipToContent': 'Skip to content',
  'nav.toggleTheme': 'Toggle color theme',
  'nav.themeToDark': 'Switch to dark mode',
  'nav.themeToLight': 'Switch to light mode',
  'nav.switchLanguage': 'Switch language',
  'nav.main': 'Main navigation',

  'home.latestPosts': 'Latest posts',
  'home.allPosts': 'All posts',
  'home.viewResume': 'View resume',
  'home.empty': 'Posts are still being migrated. Check back soon.',
  'home.series': 'Browse by series',
  'home.projects': 'Now working on',
  'home.viewProjects': 'All projects',
  'home.blocks.posts': 'Contest solutions, CS study notes and paper readings.',
  'home.blocks.resume': 'Education, experience and skills.',
  'home.blocks.archive': 'Browse every post by year.',

  'posts.title': 'Blog',
  'posts.description': 'All posts, grouped by series.',
  'posts.empty': 'No published posts yet.',
  'posts.backToList': '← Back to all posts',
  'posts.readMore': 'Read more',
  'posts.publishedOn': 'Published on',
  'posts.readingTime': 'min read',
  'posts.prevInSeries': 'Previous',
  'posts.nextInSeries': 'Next',
  'posts.seriesNav': 'Series navigation',

  'tags.title': 'Tags',
  'tags.description': 'Browse posts by tag.',
  'tags.empty': 'No tags yet.',
  'tags.count': 'posts',
  'tags.postsTagged': 'Posts tagged',

  'archive.title': 'Archive',
  'archive.description': 'All posts grouped by series.',
  'archive.empty': 'Nothing to archive yet.',
  'archive.count': 'posts',

  'projects.title': 'Projects',
  'projects.description': 'Algorithm practice, CS study notes and coursework projects.',
  'projects.empty': 'Projects are still being organized. Check back soon.',
  'projects.viewRepo': 'View repo',
  'series.daily-coding': 'Daily Coding',
  'series.contest-solution': 'Contest Solutions',
  'series.paper-reading': 'Paper Reading',
  'series.uncategorized': 'Other',
  'series.count': 'posts',

  'resume.title': 'Resume',
  'resume.description': "VenusHui's resume.",
  'resume.empty': 'The resume has not been migrated yet. Check back soon.',
  'resume.updated': 'Last updated: ',

  'notFound.title': 'Page not found',
  'notFound.description': 'This page does not exist — the link may be outdated or mistyped.',
  'notFound.backHome': 'Back to home',
  'notFound.browsePosts': 'Browse posts',

  'footer.rights': 'All rights reserved.',
  'footer.source': 'Source',
  'footer.rss': 'RSS',
};

export const ui = { zh, en } satisfies Record<Locale, Record<UIKey, string>>;
