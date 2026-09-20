#!/usr/bin/env node
/**
 * 站内链接与静态资源引用检查 —— 在 `astro build` 之后运行。
 *
 * 存在的理由：站点发布在 GitHub Pages 的**项目子路径** `/VenusHui/` 下，
 * 写死根路径 `/` 的链接与资源在线上会 404，而构建本身不会报错。
 * 这个脚本把「base path 写错」和「链接指向不存在的页面」变成可自动检测的失败。
 *
 * 检查三件事：
 *   1. 任何站内绝对引用（`/...`）必须以 base 开头；
 *   2. 每个站内引用都要能在 dist/ 里解析到真实文件；
 *   3. 构建产物中的 CSS `url(...)` 同样受检。
 *
 * base 与 site 直接读 astro.config.mjs，不在这里重复写死。
 *
 * 用法：node scripts/check-links.mjs [dist 目录]
 */
import { readdir, readFile, stat } from 'node:fs/promises';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

const siteRoot = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
const { default: config } = await import(path.join(siteRoot, 'astro.config.mjs'));

/** astro.config 的 base 恒为「以 / 开头且以 / 结尾」，这里按该约定使用。 */
const base = config.base ?? '/';
const origin = config.site ? new URL(config.site).origin : null;
const distDir = path.resolve(siteRoot, process.argv[2] ?? 'dist');

const ATTR = /(?:href|src)\s*=\s*"([^"]*)"/gi;
const URL_FUNC = /url\(\s*['"]?([^'")]+)['"]?\s*\)/gi;
/** 外部链接、锚点、数据 URI 等一律跳过。 */
const SKIP = ['http://', 'https://', '//', 'mailto:', 'data:', 'javascript:', '#'];

async function isFile(target) {
  try {
    return (await stat(target)).isFile();
  } catch {
    return false;
  }
}

/** 把「带 base 的站内路径」映射到 dist/ 里的文件，判断是否存在。 */
async function resolves(refPath) {
  // 锚点片段不参与文件解析：`posts/#daily-coding` 与 `posts/` 是同一个页面。
  const pathOnly = refPath.split('#')[0];
  let rel;
  try {
    rel = decodeURIComponent(pathOnly.slice(base.length));
  } catch {
    return false; // 畸形百分号编码
  }
  const target = path.join(distDir, rel);
  if (rel === '' || pathOnly.endsWith('/')) return isFile(path.join(target, 'index.html'));
  // 无扩展名的引用按目录索引处理，与 GitHub Pages 的行为一致
  return (await isFile(target)) || isFile(path.join(target, 'index.html'));
}

async function walk(dir) {
  const out = [];
  for (const entry of await readdir(dir, { withFileTypes: true })) {
    const full = path.join(dir, entry.name);
    if (entry.isDirectory()) out.push(...(await walk(full)));
    else out.push(full);
  }
  return out;
}

const files = await walk(distDir);
const problems = [];
let checked = 0;

for (const file of files) {
  const rel = path.relative(distDir, file);
  const isHtml = file.endsWith('.html');
  const isCss = file.endsWith('.css');
  if (!isHtml && !isCss) continue;

  const content = await readFile(file, 'utf8');
  const refs = isHtml
    ? [...content.matchAll(ATTR)].map((m) => m[1])
    : [...content.matchAll(URL_FUNC)].map((m) => m[1]);

  for (const ref of refs) {
    if (!ref || SKIP.some((prefix) => ref.startsWith(prefix))) continue;
    checked += 1;

    // 指向本站 origin 的绝对地址：去掉 origin 后同样必须带 base
    if (origin && ref.startsWith(origin)) {
      const rest = ref.slice(origin.length);
      if (!rest.startsWith(base)) {
        problems.push(`${rel}: 站内绝对地址缺少 base -> ${ref}`);
      } else if (!(await resolves(rest))) {
        problems.push(`${rel}: 站内绝对地址指向不存在的页面 -> ${ref}`);
      }
      continue;
    }

    // 根路径绝对引用：最常见的 base path 事故
    if (ref.startsWith('/')) {
      if (!ref.startsWith(base)) {
        problems.push(`${rel}: 站内引用缺少 base -> ${ref}`);
      } else if (!(await resolves(ref))) {
        problems.push(`${rel}: 链接指向不存在的页面 -> ${ref}`);
      }
      continue;
    }

    // 相对引用：相对当前文件所在目录解析（锚点片段同样忽略，不参与文件解析）
    if (ref.startsWith('?')) continue;
    let decoded;
    try {
      decoded = decodeURIComponent(ref);
    } catch {
      problems.push(`${rel}: 相对引用编码异常 -> ${ref}`);
      continue;
    }
    const target = path.resolve(path.dirname(file), decoded.split('#')[0]);
    if (!(await isFile(target)) && !(await isFile(path.join(target, 'index.html')))) {
      problems.push(`${rel}: 相对引用指向不存在的文件 -> ${ref}`);
    }
  }
}

console.log(`check-links: base=${base} 检查了 dist/ 下 ${checked} 个站内引用`);

if (problems.length > 0) {
  console.error(`\n发现 ${problems.length} 个问题：`);
  for (const problem of problems) console.error(`  - ${problem}`);
  process.exit(1);
}

console.log('check-links: 无死链，无 base path 违规');
