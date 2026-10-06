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

<h1>Header</h1>
{#await wasmPromise}
  <div class="loader" transition:fade>
    <p>WebAssembly is loading...</p>
  </div>
{:then wasm}
  <nav>
    <button onclick={() => pagePromise = loadPage('Home')}>Main page</button>
    <button onclick={() => pagePromise = loadPage('About', { title: 'This is about page!!!' })}>about page</button>
  </nav>
  {#await pagePromise}
    <div class="loader" transition:fade>
      <p>Page is loading...</p>
    </div>
  {:then { Component, props }}
  <main transition:fade>
    <Component {...props} />
  </main>
  {:catch error}
    <p style="color: red;">Page loading error: {error.message}</p>
  {/await}
{:catch error}
  <p style="color: red;">WASM error: {error.message}</p>
{/await}
