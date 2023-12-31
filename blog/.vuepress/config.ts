import path from 'path';
import { defineUserConfig } from 'vuepress';
import { registerComponentsPlugin } from '@vuepress/plugin-register-components';
import theme from './theme.js';

export default defineUserConfig({
  base: '/blog/',
  lang: 'zh-CN',
  title: '胡梓晗的博客',
  head: [
    ['meta', { name: 'referer', content: 'never' }],
  ],
  theme,
  plugins: [
    registerComponentsPlugin({
      componentsDir: path.resolve(__dirname, './components'),
    }),
  ],
});
