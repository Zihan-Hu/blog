<script lang="ts" setup>
import { capitalize, computed } from 'vue'

export type Rank = 'unrated' | 'newbie' | 'pupil' | 'specialist' | 'expert' | 'candidate-master' | 'master' | 'international-master' | 'grandmaster' | 'international-grandmaster' | 'legendary-grandmaster' | 'headquarters'

const props = defineProps<{
  rank: Rank
}>()

const Ratings: Record<Exclude<Rank, 'unrated' | 'newbie' | 'headquarters'>, number> = {
  'pupil': 1200,
  'specialist': 1400,
  'expert': 1600,
  'candidate-master': 1900,
  'master': 2200,
  'international-master': 2300,
  'grandmaster': 2400,
  'international-grandmaster': 2600,
  'legendary-grandmaster': 2900,
}

const shownRank = computed(() => {
  return props.rank.split('-').map(v => capitalize(v)).join(' ')
})

const tip = computed(() => {
  let ans = shownRank.value
  switch (props.rank) {
    case 'unrated':
      ans += ', rating = 0'
      break
    case 'newbie':
      ans += `, rating < ${Ratings.pupil} and ≠ 0`
      break
    case 'headquarters':
      break
    default:
      ans += `, rating ${Ratings[props.rank]}`
  }
  return ans
})
</script>

<template>
  <span class="rank" :class="[rank]" :rank="tip">
    <a href="https://codeforces.com/" target="_blank" />
    {{ shownRank }}
  </span>
</template>

<style lang="scss" scoped>
.rank {
  font-weight: bold;
  &.unrated { color: #000000; font-weight: initial; }
  &.newbie { color: #808080; }
  &.pupil { color: #008000; }
  &.specialist { color: #03a89e; }
  &.expert { color: #0000ff; }
  &.candidate-master { color: #aa00aa; }
  &.master { color: #ff8c00; }
  &.international-master { color: #ff8c00; }
  &.grandmaster { color: #ff0000; }
  &.international-grandmaster { color: #ff0000; }
  &.legendary-grandmaster { color: #ff0000; }
  &.headquarters { color: #000000; }

  a {
    display: inline-block;
    width: 16px;
    height: 16px;
    background-image: url("https://codeforces.org/s/0/favicon-96x96.png");
    background-size: 100% 100%;
  }
}
</style>
