# 项目内容

项目集合的约定文档。项目条目放在 `site/src/projects/`，承接仓库根目录的三条内容线
（ACM-ICPC / Learning / TongjiClasses）与其他 GitHub 项目。

约定：

- **一个目录一个项目，目录名即 slug**：`site/src/projects/<slug>/README.md`，
  布局与简历集合一致（本文件在顶层，不被内容 glob 命中）。
- 条目只存**元信息**（frontmatter），正文以仓库既有内容为单一事实来源，
  站点侧不复制正文 —— 仓库目录 / GitHub 本身就是内容源。
- `title` 与 `summary` 必填（项目卡片的最小门面）；`repo` / `tech` / `highlight` 可选。
- 内容迁入同样受公开范围门禁约束：仓库是公开仓库，项目条目一旦提交即公开。

## frontmatter 字段

| 字段        | 类型     | 说明                                                     |
| ----------- | -------- | -------------------------------------------------------- |
| `title`     | string   | **必填**。项目名                                         |
| `summary`   | string   | **必填**。一句话摘要（列表 / 卡片用）                    |
| `repo`      | string   | 仓库链接：仓库内相对路径（如 `/ACM-ICPC/`）或 GitHub URL |
| `tech`      | string[] | 技术栈，缺省为空                                         |
| `highlight` | boolean  | 精选标记，`true` 时进入首页「精选项目」等聚合位置        |

字段定义以 `site/src/content.config.ts` 中 projects 集合的 schema 为准。

## 三条内容线拆分建议

- 算法训练：ACM-ICPC（LeetCode / Codeforces / AtCoder / AcWing 等），`AlgorithmTemplates.md` 可单列「算法模板」参考项。
- 学习笔记：Learning（DS / DB / Language / Linux / Network / OS）。
- 课程项目：TongjiClasses（移动分析竞教、分布式系统等）。

具体条目与摘要内容待后续 issue 迁入（需确认公开范围与仓库相对链接）。
