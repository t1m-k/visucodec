<script>
  import { getContext } from "svelte";
  const { wasm, loadPage } = getContext('context');
</script>

<h1>About the project</h1>

<p>
  Every message that reaches you is a story that survived a journey.
  VisuCodec lets you follow that journey with your own eyes.
</p>

<p>
  Here you can learn how information is encoded, protect that knowledge from noise,
  and see every idea come alive on screen — clear, visual, and hands-on.
</p>

<p>
  We start with the classic Caesar cipher, move through the ideas of Fano and Shannon,
  and finish with modern coding theory, such as LDPC codes.
  Step by step, you go from a simple to the codes that keep our world connected.
</p>

<p>
  The project is only at its beginning, and that is the best part:
  there is still so much left to explore.
</p>

<button class="pill-button" onclick={() => loadPage('Concepts')}>
  go further
</button>
