#ifndef CGD_WINDOW_H
#define CGD_WINDOW_H

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <stdio.h>
#include <stdlib.h>
#include "input.h"

typedef struct 
{
	SDL_Window* sdl_window;
    SDL_GLContext* gl_context;

    float delta;
    short quit;
} CGD_Window;

CGD_Window* cgd_window_create(const char *title, int width, int height);

void cgd_window_update(CGD_Window *window);

void cgd_window_scene_loop(CGD_Window *window);

void cgd_window_destroy(CGD_Window *window);

#endif
