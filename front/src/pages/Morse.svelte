<script>
// @ts-nocheck

  import { getContext } from "svelte";
  const { wasm, loadPage } = getContext('context');

  let input = 'SOS';
  let result = '';
  let error = '';

  async function run(fn, failMessage) {
    error = '';
    const mod = await wasm;
    const ok = mod.ccall(fn, 'number', ['string'], [input]);
    if (!ok) {
      result = '';
      error = failMessage;
      return;
    }
    result = mod.UTF8ToString(mod._morse_out_js());
  }

  const encode = () => run('morse_encode_js', 'Unsupported character or output too long.');
  const decode = () => run('morse_decode_js', 'Invalid morse code.');
</script>

<h1>Morse code</h1>

<p>
  A letter becomes a short rhythm of dots and dashes.
  Space separates symbols, a slash separates words.
</p>

<div class="panel">
  <label for="morse-input">Input</label>
  <textarea id="morse-input" bind:value={input} rows="3"></textarea>

  <div class="actions">
    <button class="pill-button" onclick={encode}>Text → morse</button>
    <button class="pill-button" onclick={decode}>Morse → text</button>
  </div>

  {#if error}
    <p class="error">{error}</p>
  {/if}

  {#if result}
    <label for="morse-output">Result</label>
    <output id="morse-output">{result}</output>
  {/if}
</div>

<div class="actions">
  <button class="pill-button" onclick={() => loadPage('Home')}>Back</button>
</div>

<style>
  .panel {
    display: flex;
    flex-direction: column;
    gap: 0.75rem;
    width: 100%;
    max-width: 710px;
    margin: 1.5rem auto;
  }

  .panel label {
    font-size: 14px;
    color: var(--green);
    font-weight: 500;
  }

  .panel textarea {
    font-family: "IBM Plex Mono", monospace;
    font-size: 16px;
    color: #ffffff;
    background: #111111;
    border: 1px solid var(--green);
    border-radius: 8px;
    padding: 0.6rem 0.75rem;
    resize: vertical;
  }

  .panel output {
    display: block;
    font-family: "IBM Plex Mono", monospace;
    font-size: 16px;
    color: #ffffff;
    background: #111111;
    border-radius: 8px;
    padding: 0.6rem 0.75rem;
    word-break: break-all;
  }

  .panel .error {
    color: #ff5252;
    font-size: 14px;
    margin: 0;
  }

  .actions {
    display: flex;
    flex-wrap: wrap;
    justify-content: center;
    gap: 1rem;
  }

  .actions .pill-button {
    margin: 0.5rem 0 0;
  }
</style>
