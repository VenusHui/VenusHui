#!/usr/bin/env node
/**
 * 由 `src/assets/og.svg` 生成全站默认 OG 分享图 `public/og.png`（1200x630）。
 *
 * 为什么要把 PNG 提交进仓库、而不是构建时生成：
 * og:image 必须是位图 —— Twitter / Facebook / LinkedIn / 微信等平台的抓取器
 * 不渲染 SVG，只认 PNG / JPEG。构建时生成会为了「一张不会变的图」给 CI 引入
 * 图形栈依赖；这里改为**一次性生成、产物入库**，线上产物不依赖本脚本。
 *
 * 只有在改分享图文案 / 配色时才需要重跑：
 *
 *   npm install --no-save sharp   # sharp 只是本脚本的工具，不进 package.json
 *   node scripts/generate-og.mjs
 *
 * 注意：渲染结果取决于构建机字体。脚本内不嵌入字体，SVG 里按
 * DejaVu Sans / DejaVu Sans Mono 回退，Linux 上字体缺失时字形会退化 ——
 * 重跑后请打开 public/og.png 目视确认，再提交。
 */
import { readFile, writeFile } from 'node:fs/promises';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

const siteRoot = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
const svgPath = path.join(siteRoot, 'src/assets/og.svg');
const pngPath = path.join(siteRoot, 'public/og.png');

/** OG 分享图的标准尺寸（1.91:1，Facebook / Twitter 大图卡片通用）。 */
const WIDTH = 1200;
const HEIGHT = 630;

let sharp;
try {
  ({ default: sharp } = await import('sharp'));
} catch {
  console.error('缺少 sharp：先跑 `npm install --no-save sharp` 再执行本脚本。');
  process.exit(1);
}

const svg = await readFile(svgPath, 'utf8');
const png = await sharp(Buffer.from(svg), { density: 96 })
  .resize(WIDTH, HEIGHT, { fit: 'cover' })
  .png({ compressionLevel: 9 })
  .toBuffer();

await writeFile(pngPath, png);
console.log(
  `generate-og: ${path.relative(siteRoot, svgPath)} → ${path.relative(siteRoot, pngPath)} (${WIDTH}x${HEIGHT}, ${png.length} bytes)`,
);
