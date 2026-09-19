import { getCollection, type CollectionEntry } from 'astro:content';
import { includeDrafts } from './drafts';

export type Resume = CollectionEntry<'resumes'>;

/**
 * 取简历：`site/src/resumes/<handle>/README.md`，按 id 取第一篇（非草稿）。
 * 站点侧不硬编码简历内容。日后若有多份 handle，再改造成 /resume/[handle]/。
 *
 * 简历尚未迁入时目录是空的，而内容层对空集合每次都会打一条「collection is empty」警告，
 * 所以先用 Vite 的 glob 探一下有没有文件，没有就直接返回 undefined。
 * 注意：这里的匹配式必须与 content.config.ts 里 resumes 集合的 base + pattern 保持一致。
 *
 * 草稿闸门与博文侧共用 utils/drafts.ts 的同一套语义。
 */
export async function getPrimaryResume(): Promise<Resume | undefined> {
  const hasFiles = Object.keys(import.meta.glob('../resumes/*/README.md')).length > 0;
  if (!hasFiles) return undefined;

  const resumes = (await getCollection('resumes', ({ data }) => includeDrafts || !data.draft)).sort(
    (a, b) => a.id.localeCompare(b.id),
  );
  return resumes[0];
}
