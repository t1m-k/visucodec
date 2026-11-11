<script>
  import { getContext } from "svelte";
  const { wasm, loadPage } = getContext('context');
</script>

<h1>Why do we need coding?</h1>

<p>
  Picture a satellite photographing the stars and sending the image down.
  Everything between the camera and your screen is a channel,
  and every channel imposes its own rules.
  Coding is how the picture survives the trip.
</p>

<p>
  A channel is rarely generous. It has a limited rate, it adds noise,
  and it does not care whether the bits it carries mean anything.
  Left alone, raw measurements arrive either too slowly, too damaged,
  or in a language the receiver cannot read.
  Coding is the set of decisions that makes the journey possible anyway.
</p>

<div class="cards">
  <section class="card">
    <h2>Agreeing on meaning</h2>
    <p class="goal">Both sides must speak the same language.</p>
    <p>
      A satellite and a ground station cannot negotiate on the fly.
      The code is a contract fixed in advance: this pattern means this value,
      this header names this image, this marker ends the frame.
      Break the contract and the data arrives, but says nothing.
    </p>
    <code>header | payload | checksum</code>
  </section>

  <section class="card">
    <h2>Living on a tight budget</h2>
    <p class="goal">Bandwidth and power are scarce in orbit.</p>
    <p>
      A satellite has limited power and a short window above the station.
      Fewer bits mean faster downlink and less energy spent.
      A compact code lets more images fit into the same pass over the horizon.
    </p>
    <code>image → fewer bits → same picture</code>
  </section>

  <section class="card">
    <h2>Surviving the atmosphere</h2>
    <p class="goal">The signal arrives damaged.</p>
    <p>
      Over thousands of kilometres the signal weakens and picks up noise.
      Bits flip. Some codes add redundancy so the station can detect
      a corrupted frame and correct it, instead of losing the whole image.
    </p>
    <code>10110 → 101?? → 10110</code>
  </section>
</div>

<p>
  These three demands pull in different directions.
  A compact code saves bandwidth but leaves less room for protection;
  a robust code survives noise but spends bits on redundancy.
  Good engineering is the art of choosing where on that scale
  a particular mission can afford to stand.
</p>

<p>
  The same reasoning appears far beyond orbit.
  A photo on your phone, a message on the network, a file on disk —
  each is encoded, compressed and protected before it reaches you.
  The satellite story is simply the clearest place to see the trade-offs at work.
</p>

<p class="bridge">
  The picture is only as good as its journey.
  Coding turns a fragile signal into information that arrives intact —
  and that is the whole point of everything that follows.
</p>

<div class="actions">
  <button class="pill-button" onclick={() => loadPage('Concepts')}>Back</button>
  <button class="pill-button" onclick={() => loadPage('Morse')}>Lesson 1</button>
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
