import { hopeTheme } from 'vuepress-theme-hope';
import navbar from './navbar.js';

const DIARY_PATH = /article\/\d{4}-\d{2}-\d{2}\.md/g;

export default hopeTheme({
  hostname: 'https://github.io/zihanhu/blog',
  favicon: 'https://github.io/zihanhu/blog/favicon.ico',
  navbar,
  sidebar: false,
  editLink: false,
  blog: {
    name: '胡梓晗',
    description: '全栈业余编程爱好者（实为 OIer）',
    medias: {
      Email: 'mailto:zihan-hu@foxmail.com',
      GitHub: 'https://github.com/ZihanHu',
    },
  },
  plugins: {
    blog: {
      filter: (page) => {
        const path = page.filePathRelative;
        return (
          !!path?.startsWith('article')
          && !page.frontmatter.home
          && !DIARY_PATH.test(path)
        );
      },
    },
    mdEnhance: {
      align: true,
      include: true,
      katex: true,
    },
    comment: {
      provider: 'Giscus',
      repo: 'ZihanHu/blog',
      repoId: 'R_kgDOJtj28Q',
      category: '博客评论',
      categoryId: 'DIC_kwDOJtj28c4CYG9j',
    },
    components: {
      components: [
        'BiliBili',
      ],
    },
  },
  pageInfo: ['Date', 'Category', 'Tag'],
  copyright: 'Under CC-BY-SA-4.0 | Copyright © 2023 Zihan Hu',
  contributors: false,
  lastUpdated: false,
});
