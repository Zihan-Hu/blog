<script lang="ts" setup>
export interface Props {
  /** 图片地址，插槽优先。 */
  image?: string | string[];
  /**
   * 展示模式。
   *
   * @default 'image-right'
   */
  mode?: 'image-left' | 'image-right';
}
export interface Slots {
  /** 描述。 */
  default: () => any;
  /** 图片。 */
  image?: () => any;
}

withDefaults(defineProps<Props>(), {
  mode: 'image-right',
});
defineSlots<Slots>();
</script>

<template>
  <figure :style='{ "flex-direction": mode === "image-left" ? "row-reverse" : "row" }'>
    <div><slot /></div>
    <slot v-if='$slots.image' name='image' />
    <img v-else-if='!Array.isArray(image)' style='max-width: 20vw; margin: 4px;' :src='image' />
    <img v-else v-for='src in image' style='max-width: 20vw; margin: 4px;' :src='src' />
  </figure>
</template>

<style lang="scss" scoped>
figure {
  display: flex;
  justify-content: space-between;
  margin: 0;
}
</style>
