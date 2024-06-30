import { navbar } from 'vuepress-theme-hope'

export default navbar([
  { text: '主页', icon: 'material-symbols:home-rounded', link: '/' },
  { text: '文章', icon: 'material-symbols:article', link: '/article/' },
  { text: '分类', icon: 'tabler:category-filled', link: '/category/' },
  { text: '标签', icon: 'tabler:tag-filled', link: '/tag/' },
])
