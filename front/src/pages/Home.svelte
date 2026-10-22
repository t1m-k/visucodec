<script>
    import { getContext } from "svelte";
    const { wasm, loadPage } = getContext('context');
</script>

<h1 id="home-1">Information travels</h1>
<h1 id="home-2">It must be encoded</h1>
<button id="home-explore" onclick={() => loadPage('About', { title: 'Exploring!' })}>Explore</button>
