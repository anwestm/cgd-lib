#define SDL_MAIN_HANDLED

#include <stdio.h>
#include "window.h"
#include "util.h"

void render(float delta) {
    log_fps();
}

int main(int argc, char* args[])
{
	CGD_Window* window = cgd_create_window("test", 1280, 720);

    void (*render_ptr)(float) = &render;
	cgd_main_loop(window, render_ptr);

	return 0;
}