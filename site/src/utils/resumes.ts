import { getCollection, type CollectionEntry } from 'astro:content';
import { includeDrafts } from './drafts';
import type { Locale } from '../i18n/ui';

export type Resume = CollectionEntry<'resumes'>;

/**
 * 取简历：`site/src/resumes/<handle>/README.md`（中文版）或 `README.en.md`（英文版），
 * 按语言取该语言的第一篇（非草稿）。站点侧不硬编码简历内容。
 * 日后若有多份 handle，再改造成 /resume/[handle]/。
 *
 * 语言由文件名推导（`.en.md` → en），与 content.config.ts 里 resumes 集合的
 * pattern + generateId 一一对应：中文版 `README.md`（无后缀）、英文版 `README.en.md`；
 * 不存在该语言的简历时返回 undefined（走空状态）。
 *
 * 简历尚未迁入时目录是空的，而内容层对空集合每次都会打一条「collection is empty」警告，
 * 所以先用 Vite 的 glob 探一下有没有文件，没有就直接返回 undefined。
 * 注意：这里的匹配式必须与 content.config.ts 里 resumes 集合的 base + pattern 保持一致。
 *
 * 草稿闸门与博文侧共用 utils/drafts.ts 的同一套语义。
 */
export async function getPrimaryResume(locale: Locale): Promise<Resume | undefined> {
  const hasFiles =
    Object.keys(import.meta.glob(['../resumes/*/README.md', '../resumes/*/README.en.md'])).length >
    0;
  if (!hasFiles) return undefined;

  const resumes = (await getCollection('resumes', ({ data }) => includeDrafts || !data.draft)).sort(
    (a, b) => a.id.localeCompare(b.id),
  );

  return resumes.find((resume) => isResumeLocale(resume, locale));
}

/** 简历文件是否属于某语言：文件名带 `.en.md` 后缀是英文版，否则是中文版（与 loader pattern + generateId 对应）。 */
function isResumeLocale(resume: Resume, locale: Locale): boolean {
  const isEn = resume.id.endsWith('.en.md');
  return locale === 'en' ? isEn : !isEn;
}
