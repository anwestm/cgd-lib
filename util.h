#ifndef CGD_LIB_UTIL_H
#define CGD_LIB_UTIL_H

#include <stdio.h>
#include <SDL2/SDL.h>

void log_fps() {
    static Uint32 lastTime;
    static int fps;
    fps++;
    Uint32 currentTime = SDL_GetTicks();
    if (currentTime - lastTime >= 1000)
    {
        printf("FPS: %d\n", fps);
        lastTime = currentTime;
        fps = 0;
    }

}

#endif //CGD_LIB_UTIL_H
