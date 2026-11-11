#ifndef MORSE_H
#define MORSE_H

/* Encode text like "HELLO WORLD" into ".... . .-.. .-.. --- / .-- --- .-. .-.. -..".
   Space separates symbols, '/' separates words. Unknown chars and output
   overflow return -1. out_size must include room for '\0'. */
int morse_encode_text(const char *text, char *out, int out_size);

/* Decode text like ".... . .-.. .-.. --- / .-- --- .-. .-.. -..".
   Space separates symbols, '/' separates words (space in output).
   out_size must include room for '\0'. Returns length or -1 on error
   (unknown symbol, malformed input, or output too small). */
int morse_decode_text(const char *text, char *out, int out_size);

#endif
