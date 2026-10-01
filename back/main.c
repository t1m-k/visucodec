#include <emscripten.h>
#include <stddef.h>

// ui callback gets id of needed state and changes js var currentState to it

typedef void (*ui_callback_t)(int);

static ui_callback_t uicb = NULL;

EMSCRIPTEN_KEEPALIVE
void register_ui_callback(ui_callback_t cb) {
    uicb = cb;
}

const int N = 10;

EMSCRIPTEN_KEEPALIVE
void handle(int state) {
    if (uicb != NULL) {
        switch (state)
        {
        case 0:
            /* code */
            uicb(3);
            break;
        default:
            if (state < N) ++state;
            uicb(state);
        }
    }
}
