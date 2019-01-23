#define SDL_MAIN_HANDLED

#include <stdio.h>
#include "libcgd/window.h"
#include "testscene.h"
#include "libcgd/util.h"

int main(int argc, char** args)
{
    CGD_Window* window = cgd_window_create("test", 1920, 1080);

    Uint64 curr_time = 0;
    Uint64 last_time = 0;
    float delta = 0;

    init();
    while(!window->quit)
    {
        curr_time = SDL_GetPerformanceCounter();

        delta = ((curr_time - last_time) * 1000.0f / SDL_GetPerformanceFrequency());

        render(delta);
        cgd_window_update(window);

        last_time = curr_time;
        log_fps();
    }
    dispose();

	return 0;
}