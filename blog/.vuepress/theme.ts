import { hopeTheme } from 'vuepress-theme-hope';
import navbar from './navbar.js';
import sidebar from './sidebar.js';

export default hopeTheme({
  hostname: 'https://github.io/zihanhu/blog',
  navbar,
  sidebar,
  editLink: false,
  blog: {
    avatar: '',
    name: '胡梓晗',
    description: '全栈业余编程爱好者',
    intro: '/me.html',
    medias: {
      Email: 'mailto:zihan-hu@foxmail.com',
      GitHub: 'https://github.com/ZihanHu',
    },
  },
  plugins: {
    blog: true,
    mdEnhance: {
      align: true,
      codetabs: true,
      figure: true,
      imgLazyload: true,
      imgSize: true,
      katex: true,
      sub: true,
      sup: true,
      tabs: true,
      footnote: true,
    },
    copyCode: {},
    photoSwipe: {},
  },
  pageInfo: ['Date', 'Category', 'Tag'],
  copyright: 'Under CC-BY-SA-4.0 | Copyright © 2023 Zihan Hu',
});
