#include <emscripten.h>
#include <stddef.h>

#include "codecs/morse.h"

/* Shared output buffer; read it only after a call returned 1. */
static char js_out[4096];

EMSCRIPTEN_KEEPALIVE
const char *morse_out_js(void)
{
    return js_out;
}

EMSCRIPTEN_KEEPALIVE
int morse_encode_js(const char *text)
{
    return morse_encode_text(text, js_out, sizeof js_out) < 0 ? 0 : 1;
}

EMSCRIPTEN_KEEPALIVE
int morse_decode_js(const char *text)
{
    return morse_decode_text(text, js_out, sizeof js_out) < 0 ? 0 : 1;
}
