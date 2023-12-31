import { hopeTheme } from 'vuepress-theme-hope';
import navbar from './navbar.js';

const DIARY_PATH = /^article\/\d{4}-\d{2}-\d{2}\.md$/;

export default hopeTheme({
  hostname: 'https://github.io/Zihan-Hu/blog',
  favicon: 'https://zihan-hu.github.io/blog/favicon.ico',
  iconAssets: 'iconfont',
  navbar,
  sidebar: false,
  editLink: false,
  blog: {
    name: '胡梓晗',
    description: '全栈业余编程爱好者（实为 OIer）',
    medias: {
      Email: 'mailto:hu-zihan@foxmail.com',
      GitHub: 'https://github.com/Zihan-Hu',
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
      repo: 'Zihan-Hu/blog',
      repoId: 'R_kgDOKYKFkw',
      category: '文章评论',
      categoryId: 'DIC_kwDOKYKFk84CZm_U',
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
