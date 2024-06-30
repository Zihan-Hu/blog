import { hopeTheme } from 'vuepress-theme-hope'
import navbar from './navbar.js'

export default hopeTheme({
  hostname: 'https://blog.typed-sigterm.me/',
  favicon: '/favicon.ico',
  iconAssets: 'iconify',
  navbar,
  sidebar: false,
  repo: 'typed-sigterm/blog',
  toc: false,
  blog: {
    avatar: '/avatar.png',
    name: 'typed-sigterm',
    description: '全栈业余编程爱好者（实为 OIer）',
    medias: {
      Email: 'mailto:typed-sigterm@gmail.com',
      GitHub: 'https://github.com/typed-sigterm',
    },
  },
  plugins: {
    blog: {
      filter({ filePathRelative }) {
        return !!filePathRelative?.startsWith('article')
      },
    },
    mdEnhance: {
      align: true,
      include: true,
      katex: true,
    },
    comment: {
      provider: 'Giscus',
      repo: 'typed-sigterm/blog',
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
  copyright: 'Under CC-BY-4.0 | Copyright © 2023-present typed-sigterm',
  displayFooter: true,
  contributors: false,
  lastUpdated: false,
})
