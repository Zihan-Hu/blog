import { hopeTheme } from 'vuepress-theme-hope'
import navbar from './navbar.js'

export default hopeTheme({
  hostname: 'https://zihan-hu.netlify.app/',
  favicon: '/favicon.ico',
  iconAssets: 'iconfont',
  navbar,
  sidebar: false,
  repo: 'Zihan-Hu/blog',
  toc: false,
  blog: {
    avatar: '/avatar.png',
    name: 'Zihan Hu',
    description: '全栈业余编程爱好者（实为 OIer）',
    medias: {
      Email: 'mailto:hu-zihan@foxmail.com',
      GitHub: 'https://github.com/Zihan-Hu',
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
  copyright: 'Under CC-BY-4.0 | Copyright © 2023-present Zihan Hu',
  displayFooter: true,
  contributors: false,
  lastUpdated: false,
})
