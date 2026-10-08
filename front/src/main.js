import { mount } from 'svelte'
import './app.css'
import '@fontsource/ibm-plex-sans/200.css';
import '@fontsource/ibm-plex-sans/300.css';
import '@fontsource/ibm-plex-sans/400.css';
import '@fontsource/ibm-plex-sans/500.css';
import App from './App.svelte'

const app = mount(App, {
  target: document.getElementById('app'),
})

export default app
