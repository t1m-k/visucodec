<script>
// @ts-nocheck

  import createWasmModule from './lib/wasm.js';
  import wasmUrl from './lib/wasm.wasm?url';
  import { fade, fly } from 'svelte/transition';
  import githubLogo from './assets/GitHub_Lockup_White.svg';
  import satelliteIcon from './assets/satellite.svg?url';

  import Home from './pages/Home.svelte';
	import About from './pages/About.svelte';
  let pagePromise = $state(loadPage('Home', { loadPage: loadPage }));

  async function loadPage(pageName, props = {}) {
    const module = await import(`./pages/${pageName}.svelte`);
    pagePromise = {
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
    <button class="logo" onclick={() => loadPage('Home', { loadPage: loadPage })}>VisuCodec</button>
    <a href="https://t1m-k.github.io/visucodec/" target="_blank" rel="noopener noreferrer" aria-label="Satellite icon">
      <img class="satellite" src={satelliteIcon} alt="Satellite icon" aria-hidden="true" />
    </a>
    <nav>
      <button onclick={() => loadPage('About', { title: 'This is about page!!!' })}>About</button>
    </nav>
  </header>
  {#await pagePromise}
    <div class="loader" transition:fade>
      <p>Page is loading...</p>
    </div>
  {:then { Component, props }}
  {#if Component === Home}
    <svg class="signal" viewBox="0 0 100 200" aria-hidden="true" preserveAspectRatio="none">
       <path d="M 53 2 L 0 112 L 86 83 L 33 200 L 100 72 L 9 104 L 53 2 Z" />
    </svg>
  {/if}
  <main>
    <Component {...props} />
  </main>
  <footer>
    <a href="https://t1m-k.github.io/visucodec/" target="_blank" rel="noopener noreferrer" aria-label="Satellite icon">
      <img src={satelliteIcon} alt="Satellite icon" aria-hidden="true" style="height: 3em"/>
    </a>
    <p>Made with love.</p>
    <a href="https://github.com/t1m-k/visucodec/" target="_blank" rel="noopener noreferrer" aria-label="GitHub">
      <img src={githubLogo} alt="GitHub" style="height: 1em; display: block" />
    </a>
  </footer>
  {:catch error}
    <p style="color: red;">Page loading error: {error.message}</p>
  {/await}
{:catch error}
  <p style="color: red;">WASM error: {error.message}</p>
{/await}
