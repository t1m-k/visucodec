import { svelte } from '@sveltejs/vite-plugin-svelte'
import { defineConfig } from 'vite'
import path from 'path';

// https://vite.dev/config/
export default defineConfig({
  plugins: [svelte()],
  server: {
    watch: {
      usePolling: true,
    },
  },
  base: '/visucodec/',
})
