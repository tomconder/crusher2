#ifdef EMSCRIPTEN
#include <emscripten/emscripten.h>
#endif
#include <SDL.h>

#include "easylogging++.h"
#include "crusher2.h"

INITIALIZE_EASYLOGGINGPP

std::unique_ptr<Crusher2> crusher2;

// loop iteration is broken out like this for emscripten
bool iterateLoop() {
    return crusher2->iterateLoop();
}

extern "C"
int main(int argc, char *args[]) {
    START_EASYLOGGINGPP(argc, args);

    crusher2 = std::make_unique<Crusher2>();

    if (crusher2->construct(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT) == globals::Retcode::FAIL) {
        return 1;
    }

    if (crusher2->start() == globals::Retcode::FAIL) {
        return 1;
    }

#ifdef EMSCRIPTEN
    emscripten_set_main_loop((em_callback_func) iterateLoop, 60, true);
#else
    bool quit = false;
    while (!quit) {
        quit = iterateLoop();
    }
#endif

    return 0;
}
