import { defineUserConfig } from 'vuepress';
import theme from './theme.js';

export default defineUserConfig({
  base: '/blog/',
  lang: 'zh-CN',
  title: '胡梓晗的博客',
  theme,
});
