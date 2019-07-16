#define SDL_MAIN_HANDLED

#include <stdio.h>
#include "libcgd/window.h"
#include "libcgd-test/texturetest.h"
#include "libcgd/util.h"

int main(int argc, char** args)
{
    CGD_Window* window = cgd_window_create("test title", 1920, 1080);

    int curr_time;
    int last_time;
    float delta;

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