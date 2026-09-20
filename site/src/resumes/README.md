# 简历内容

简历以 Markdown 为唯一事实来源，站点侧只读渲染，不复制、不硬编码。约定：

- 一个目录一篇简历，目录名即 handle：`site/src/resumes/<handle>/README.md`。
- 字段**全部可选**，按实际内容填写即可；站点在正文上方展示 `updated`（若有）。
- **结构化字段与正文的关系**：正文保留叙述式 Markdown（项目经历等用 MD 小节写），
  结构化字段（见下表）只驱动站点侧的卡片 / 时间轴 / 联系方式头等排版；
  未填的字段站点侧跳过渲染，逐步迁入、不阻塞上线。
- **内容迁入前需由站点 owner 确认公开范围** —— 本仓库是公开仓库，简历内容一旦提交即公开并留在 git 历史中；
  学校 / 实习 / 公司细节必须经成员本人确认并脱敏后再迁入。本期只定义字段契约，不写入真实个人信息。

当前该目录尚未放入简历内容，简历页会渲染「内容尚未迁入」的空状态。

## frontmatter 字段

| 字段         | 类型                | 说明                                                            |
| ------------ | ------------------- | --------------------------------------------------------------- |
| `name`       | string              | 姓名                                                            |
| `title`      | string              | 头衔 / 一句话身份                                               |
| `summary`    | string              | 简介（供页首展示）                                              |
| `updated`    | date (`YYYY-MM-DD`) | 最后更新日期，展示在页首                                        |
| `draft`      | boolean             | `true` 时只在本地 dev 可见，不进构建产物                        |
| `contact`    | object              | 联系方式头：`{ email?, location? }`                             |
| `links`      | array               | 社交链接：`[{ label, url }]`（GitHub / LinkedIn …）             |
| `education`  | array               | 教育经历：`[{ school, degree?, period?, highlight? }]`          |
| `experience` | array               | 工作 / 实习经历：`[{ company, role?, period?, bullets?[] }]`    |
| `skills`     | array               | 专业技能：`[{ category, items[] }]`（熟悉 / 掌握 / 了解等分组） |
| `honors`     | array               | 荣誉 / 奖项：`[{ name, detail?, date? }]`                       |
| `languages`  | array               | 语言能力：`[{ name, level? }]`                                  |

字段定义以 `site/src/content.config.ts` 中 resumes 集合的 schema 为准。
