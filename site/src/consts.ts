/** 站点级常量。 */

/** 站点仓库（public），页脚「源码」链接指向它。 */
export const REPO_URL = 'https://github.com/VenusHui/VenusHui';

/** 站点作者，用于页脚版权。 */
export const AUTHOR = 'VenusHui';

/** 作者的 GitHub 主页，首页 hero 的社交链接指向它。 */
export const GITHUB_PROFILE = 'https://github.com/venushui';

/** 作者的 LeetCode 主页。 */
export const LEETCODE_PROFILE = 'https://leetcode.cn/u/venushui/';

/** 作者的 Codeforces 主页。 */
export const CODEFORCES_PROFILE = 'https://codeforces.com/profile/VenusHui';

/**
 * 作者在公开平台的主页，供 JSON-LD 的 `sameAs` 使用 —— 告诉搜索引擎
 * 「这些账号是同一个人」，是 Person 结构化数据里最有价值的一项。
 * 这三个地址取自仓库根 README 的 Profile 小节，已是公开信息。
 */
export const PROFILE_LINKS = [GITHUB_PROFILE, LEETCODE_PROFILE, CODEFORCES_PROFILE];

/**
 * 全站默认 OG 分享图：`public/` 下的文件名，位图（1200x630），
 * 由 `src/assets/og.svg` 经 `scripts/generate-og.mjs` 渲染产出。
 * BaseLayout 统一把它拼成带 base 的绝对地址输出 `og:image`。
 */
export const OG_IMAGE = 'og.png';

/** OG 分享图尺寸（1.91:1）。与 `scripts/generate-og.mjs` 里的输出尺寸保持一致。 */
export const OG_IMAGE_WIDTH = 1200;
export const OG_IMAGE_HEIGHT = 630;

/** RSS 每个语言源输出的最大条目数，避免订阅文件随博文增长无限变大。 */
export const RSS_ITEM_LIMIT = 20;
