<script>
// @ts-nocheck

  import { fade, fly } from 'svelte/transition';
  import createWasmModule from './lib/wasm.js';

  let currentState = 0;

  async function initWASM() {
    const wasm = await createWasmModule({
      locateFile: (path) => path.endsWith('.wasm') ? '/wasm.wasm' : path
    });

    const jsCallbackPtr = wasm.addFunction((state) => {
      currentState = state; 
    }, 'vi'); // get int, return void - uicb(int state) func;

    wasm._register_ui_callback(jsCallbackPtr);

    return wasm;
  }

  const wasmPromise = initWASM();
</script>

<main>
  <h1>-- VisuCodec --</h1>
  {#await wasmPromise}
    <div class="loader" transition:fade>
      <p>WebAssembly is loading...</p>
    </div>
  {:then wasm}
    <div class="app-container" transition:fade>
      <h3>Current state: {currentState}.</h3>

      <button on:click={() => wasm._handle(currentState)}>Next</button>

      <button on:click={() => wasm._handle(0)}>To state 3</button>

      <div class="screen-view">
        {#if currentState === 0}
          <div class="screen" in:fade>
            <h3>Hello world!</h3>
            <p>Press "Next" button!</p>
          </div>
        {:else if currentState === 3}
          <div class="screen" in:fade={{ duration: 500 }}>
            <h3>Hey!</h3>
            <p>As you see, states 1 and 2 were skipped!</p>
          </div>
        {:else if currentState >= 4 && currentState <= 8}
          <div class="screen">
            <h3>Hey-hey-hey!</h3>
            <p>Now between state 4 and 8!</p>
          </div>
        {:else if currentState === 9}
          <div class="screen" in:fade out:fly={{ x: 500, duration: 500 }}>
            <h3>Hey!</h3>
            <p>It is state 9, did you know?</p>
          </div>
        {:else}
          <div class="screen" in:fly={{ y: 100, duration: 2000 }}>
            <h3>Bye!</h3>
            <p>State 10 is the last!</p>
          </div>
        {/if}
      </div>
    </div>
  {:catch error}
    <p style="color: red;">WASM error: {error.message}</p>
  {/await}
</main>
