#include <string.h>
#include "morse.h"

static const char *morse_table[36] = {
    ".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",  "....", /* A-H */
    "..",   ".---", "-.-",  ".-..", "--",   "-.",   "---",  ".--.", /* I-P */
    "--.-", ".-.",  "...",  "-",    "..-",  "...-", ".--",  "-..-", /* Q-X */
    "-.--", "--..",                                                 /* Y-Z */
    "-----", ".----", "..---", "...--", "....-",                    /* 0-4 */
    ".....", "-....", "--...", "---..", "----."                     /* 5-9 */
};

/* Return table entry for c, or NULL if unsupported. */
static const char *morse_lookup(char c)
{
    if (c >= 'a' && c <= 'z') c -= 32; // to A-Z
    if (c >= 'A' && c <= 'Z') return morse_table[c - 'A'];
    if (c >= '0' && c <= '9') return morse_table[26 + (c - '0')];
    return NULL;
}

/* Decode code[0..len) like ".-". Returns char or '\0' if unknown. */
static char morse_decode_symbol(const char *code, size_t len)
{
    if (!code || !len) return '\0';

    for (int i = 0; i < 36; i++) {
        if (strlen(morse_table[i]) == len &&
            memcmp(morse_table[i], code, len) == 0)
            return i < 26 ? (char)('A' + i) : (char)('0' + (i - 26));
    }
    return '\0';
}

int morse_encode_text(const char *text, char *out, int out_size)
{
    if (!text || !out || out_size < 1) return -1;

    int written = 0, pending_slash = 0;

    for (int i = 0; text[i]; i++) {
        char c = text[i];

        if (c == ' ') {
            if (written > 0) pending_slash = 1;
            continue;
        }

        const char *sym = morse_lookup(c);
        if (!sym) return -1;

        size_t tl = strlen(sym);

        if (written > 0) {
            int need = 1 + (pending_slash ? 2 : 0);
            if (written + need >= out_size) return -1;
            out[written++] = ' ';
            if (pending_slash) {
                out[written++] = '/';
                out[written++] = ' ';
            }
        }

        if ((size_t)(out_size - written) < tl + 1) return -1;
        memcpy(out + written, sym, tl);
        written += (int)tl;

        pending_slash = 0;
    }

    out[written] = '\0';
    return written;
}

int morse_decode_text(const char *text, char *out, int out_size)
{
    if (!text || !out || out_size < 1) return -1;

    int written = 0;
    size_t start = 0, sl = 0;

    for (size_t i = 0;; i++) {
        char c = text[i];
        if (c && c != ' ' && c != '/') {
            if (sl == 0) start = i;
            sl++;
            continue;
        }

        if (sl > 0) {
            char d = morse_decode_symbol(text + start, sl);
            if (d == '\0') return -1;
            if (written + 1 >= out_size) return -1;
            out[written++] = d;
            sl = 0;
        }

        if (c == '\0') break;

        if (c == '/') {
            if (written + 1 >= out_size) return -1;
            out[written++] = ' ';
        }
    }

    out[written] = '\0';
    return written;
}
