import { getCollection, type CollectionEntry } from 'astro:content';
import { REPO_URL } from '../consts';

export type Project = CollectionEntry<'projects'>;

/**
 * 取全部项目，按目录名（slug）排序。
 *
 * **取项目的唯一入口**：与 posts / resumes 一样，任何需要项目的地方都调它，
 * 不直接写 `getCollection('projects', ...)`，未来加草稿 / 语言字段时不用改调用方。
 */
export async function getProjects(): Promise<Project[]> {
  const projects = await getCollection('projects');
  return projects.sort((a, b) => a.id.localeCompare(b.id));
}

/**
 * 项目卡片链接：把 `repo` 字段转成可点击的 GitHub 链接。
 *
 * `repo` 约定为「仓库内相对路径」（如 `/ACM-ICPC/`）或完整 GitHub URL
 * （见 `site/src/projects/README.md`）。相对路径要转成仓库内的 blob / tree 链接，
 * 而不是站内路由 —— 注意与站点 base path `/VenusHui/` 区分：这是仓库内容源，
 * 卡片点击去 GitHub 看正文，站点侧不复制内容。
 */
export function projectRepoUrl(project: Project): string {
  const repo = project.data.repo;
  if (!repo) return REPO_URL;
  if (repo.startsWith('http://') || repo.startsWith('https://')) return repo;
  const path = repo.replace(/^\/+/, '');
  // 目录用 tree、单文件用 blob；带尾部斜杠或没有文件扩展名的视为目录。
  const kind = path.endsWith('/') || !/\.[a-z0-9]+$/i.test(path) ? 'tree' : 'blob';
  return `${REPO_URL}/${kind}/main/${path}`;
}
