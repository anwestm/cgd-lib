#include "window.h"


CGD_Window* cgd_create_window(const char* title, const int width, const int height)
{

	if(SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("SDL2 INIT ERROR: %s\n", SDL_GetError());
		exit(-1);
	}
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	SDL_Window* sdl_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_HIDDEN);
	
	if (!sdl_window)
	{
		printf("SDL WINDOW CREATION FAILED %s\n", SDL_GetError());
		SDL_Quit();
		exit(-1);
	}
	SDL_GLContext* gl_context = SDL_GL_CreateContext(sdl_window);
	SDL_GL_SetSwapInterval(0);
	SDL_ShowWindow(sdl_window);

    // Init GLEW
    glewExperimental = GL_TRUE;
    const GLenum error = glewInit();
    if (error != GLEW_OK)
    {
        printf("GLEW ERROR:%s\n", glewGetErrorString(error));
        exit(-1);
    }

	CGD_Window* cgd_window = malloc(sizeof(CGD_Window));
    cgd_window->sdl_window = sdl_window;
    cgd_window->gl_context = gl_context;

	return cgd_window;
}

void cgd_destroy_window(CGD_Window *window)
{

}

void cgd_main_loop(CGD_Window *window, void(*render_func)(float delta))
{
    int quit = 0;
    Uint32 lastTime = SDL_GetTicks();
    while (!quit)
    {
        SDL_Event event;
        while( SDL_PollEvent(&event) ) {
            if(event.type == SDL_QUIT) {
                quit = 1;
            }
        }
        render_func((SDL_GetTicks() - lastTime) / 1000.0f);
        SDL_GL_SwapWindow(window->sdl_window);
    }
}
