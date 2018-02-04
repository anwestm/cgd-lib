//
// Created by andreas on 2018-01-28.
//

#include "util.h"

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
