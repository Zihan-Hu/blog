import path from 'path';
import { defineUserConfig } from 'vuepress';
import { viteBundler } from '@vuepress/bundler-vite'
import { registerComponentsPlugin } from '@vuepress/plugin-register-components';
import theme from './theme.js';

export default defineUserConfig({
  lang: 'zh-CN',
  title: '胡梓晗的博客',
  head: [
    ['meta', { name: 'referer', content: 'never' }],
  ],
  bundler: viteBundler({
    viteOptions: {},
    vuePluginOptions: {},
  }),
  theme,
  plugins: [
    registerComponentsPlugin({
      componentsDir: path.resolve(__dirname, './components'),
    }),
  ],
});
