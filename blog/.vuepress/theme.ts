import { hopeTheme } from 'vuepress-theme-hope';
import navbar from './navbar.js';

export default hopeTheme({
  hostname: 'https://github.io/zihanhu/blog',
  navbar,
  sidebar: false,
  editLink: false,
  blog: {
    name: '胡梓晗',
    description: '全栈业余编程爱好者',
    medias: {
      Email: 'mailto:zihan-hu@foxmail.com',
      GitHub: 'https://github.com/ZihanHu',
    },
  },
  plugins: {
    blog: true,
    mdEnhance: {
      include: true,
      katex: true,
    },
    copyCode: {},
    photoSwipe: {},
  },
  pageInfo: ['Date', 'Category', 'Tag'],
  copyright: 'Under CC-BY-SA-4.0 | Copyright © 2023 Zihan Hu',
  contributors: false,
  lastUpdated: false,
});
