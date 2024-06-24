import { defineClientConfig } from 'vuepress/client'
import mixpanel from 'mixpanel-browser'

function initMixpanel() {
  const token = import.meta.env.BLOG_MIXPANEL_TOKEN
  if (__VUEPRESS_DEV__ || !token)
    return
  mixpanel.init(token, {
    track_pageview: 'url-with-path',
    persistence: 'localStorage',
  })
}

export default defineClientConfig({
  setup() {
    if (__VUEPRESS_SSR__)
      return
    initMixpanel()
  },
})
