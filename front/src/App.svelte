<script>
// @ts-nocheck

  import createWasmModule from './lib/wasm.js';
  import wasmUrl from './lib/wasm.wasm?url';
  import { fade, fly } from 'svelte/transition';

  import Home from './pages/Home.svelte';
	import About from './pages/About.svelte';
  let pagePromise = $state(loadPage('Home'));

  async function loadPage(pageName, props = {}) {
    const module = await import(`./pages/${pageName}.svelte`);
    return {
      Component: module.default,
      props: props
    };
  }

  async function initWASM() {
    const wasm = await createWasmModule({
      locateFile: (path) => path.endsWith('.wasm') ? wasmUrl : path
    });

    return wasm;
  }

  const wasmPromise = initWASM();
</script>

{#await wasmPromise}
  <div class="loader" transition:fade>
    <p>WebAssembly is loading...</p>
  </div>
{:then wasm}
  <header>
    <span class="logo">VisuCodec</span>
    <svg class="satellite" viewBox="0 0 40 40" stroke-width="0.7" aria-hidden="true">
      <circle cx="25" cy="15" r="5" stroke-width="1.5"/>
      <line x1="22" y1="11" x2="6" y2="3" />
      <line x1="20.5" y1="14" x2="3" y2="10" />
      <line x1="22" y1="19" x2="6" y2="27" />
      <line x1="20.5" y1="16" x2="3" y2="20" />
    </svg>
    <nav>
      <button onclick={() => pagePromise = loadPage('Home')}>Main</button>
      <button onclick={() => pagePromise = loadPage('About', { title: 'This is about page!!!' })}>About</button>
    </nav>
  </header>
  {#await pagePromise}
    <div class="loader" transition:fade>
      <p>Page is loading...</p>
    </div>
  {:then { Component, props }}
  <svg class="signal" viewBox="0 0 100 300" aria-hidden="true">
      <path d="M 10 0 C 50 70, 42 90, 58 130 C 72 165, 42 190, 50 230 C 56 260, 48 280, 52 300" />
  </svg>
  <main transition:fade>
    <Component {...props} />
  </main>
  <footer>
    footer content
  </footer>
  {:catch error}
    <p style="color: red;">Page loading error: {error.message}</p>
  {/await}
{:catch error}
  <p style="color: red;">WASM error: {error.message}</p>
{/await}
