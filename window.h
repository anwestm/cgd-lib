#ifndef CGD_WINDOW_H
#define CGD_WINDOW_H

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <stdio.h>

typedef struct 
{
	SDL_Window *sdl_window;
} CGD_Window;

CGD_Window* cgd_create_window(const char* title, int width, int height);

#endif
