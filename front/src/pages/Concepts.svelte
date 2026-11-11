<script>
  import { getContext } from "svelte";
  const { wasm, loadPage } = getContext('context');
</script>

<h1>Encryption, compression, coding</h1>

<p>
  Three words that sound alike but solve different problems.
  Here is the simplest way to tell them apart.
</p>

<div class="cards">
  <section class="card">
    <h2>Encryption</h2>
    <p class="goal">Hide the information.</p>
    <p>
      The meaning is deliberately concealed.
      To anyone without the right knowledge, the message looks like noise;
      with it, the message returns exactly as it was.
      Unlike coding, the point is not to reformat the data
      but to keep it away from the wrong hands.
    </p>
    <code>cat → fdw</code>
  </section>

  <section class="card">
    <h2>Compression</h2>
    <p class="goal">Take less space.</p>
    <p>
      The same content, stored or sent in fewer bits.
      Lossy compression throws away what is not critical to perception.
      Lossless compression keeps everything and restores it perfectly,
      bit for bit, with no loss of meaning at all.
    </p>
    <code>aaaaabbb → 5a3b</code>
  </section>

  <section class="card">
    <h2>Coding</h2>
    <p class="goal">Change the form, keep the meaning.</p>
    <p>
      Encoding is reversible by everyone — no key needed.
      It rewrites information into another representation,
      and anyone with the same rules can read it back.
      And here is the quiet twist: lossless compression
      is also a form of coding.
    </p>
    <code>cat → 01100011 01100001 01110100</code>
  </section>
</div>

<p class="bridge">
  So encryption hides, compression shrinks, and coding rewrites.
  Lossless compression lives on both sides of the line:
  it is coding that also happens to shrink.
</p>

<div class="actions">
  <button class="pill-button" onclick={() => loadPage('About')}>Back</button>
  <button class="pill-button" onclick={() => loadPage('WhyCoding')}>Why coding?</button>
</div>

<style>
  .cards {
    display: flex;
    flex-wrap: wrap;
    align-items: stretch;
    justify-content: center;
    gap: 1.5rem;
    margin: 2rem auto;
    max-width: 1100px;
  }

  .card h2 {
    font-size: 24px;
    font-weight: 300;
    color: #ffffff;
    margin: 0 0 0.5rem;
  }

  .card .goal {
    font-size: 16px;
    font-weight: 500;
    color: var(--green);
    margin-bottom: 1rem;
  }

  .card p {
    max-width: none;
    font-size: 16px;
    margin-bottom: 1rem;
  }

  .card code {
    margin-top: auto;
    display: block;
    font-size: 12px;
    padding: 0.4rem 0.5rem;
    white-space: nowrap;
    overflow: hidden;
    text-overflow: ellipsis;
  }

  .bridge {
    margin-top: 1rem;
  }

  .actions {
    display: flex;
    justify-content: center;
    gap: 1rem;
  }

  .actions .pill-button {
    margin: 1.5rem 0 0;
  }
</style>
