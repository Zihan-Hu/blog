import path from 'node:path'
import { defineUserConfig } from 'vuepress'
import { viteBundler } from '@vuepress/bundler-vite'
import { registerComponentsPlugin } from '@vuepress/plugin-register-components'
import { baiduAnalyticsPlugin } from '@vuepress/plugin-baidu-analytics'
import theme from './theme.js'

export default defineUserConfig({
  lang: 'zh-CN',
  title: 'typed-sigterm\'s Blog',
  head: [
    ['meta', { name: 'referer', content: 'never' }],
  ],
  bundler: viteBundler(),
  theme,
  plugins: [
    registerComponentsPlugin({
      componentsDir: path.resolve(__dirname, './components'),
    }),
    baiduAnalyticsPlugin({
      id: 'a422ce3c9c57f5aa480ce77e4069d4bf',
    }),
  ],
})
