import path from 'node:path'
import { defineUserConfig } from 'vuepress'
import { viteBundler } from '@vuepress/bundler-vite'
import { registerComponentsPlugin } from '@vuepress/plugin-register-components'
import theme from './theme.js'

export default defineUserConfig({
  lang: 'zh-CN',
  title: 'Zihan-Hu\'s Blog',
  head: [
    ['meta', { name: 'referer', content: 'never' }],
  ],
  bundler: viteBundler(),
  theme,
  plugins: [
    registerComponentsPlugin({
      componentsDir: path.resolve(__dirname, './components'),
    }),
  ],
})
