#define SDL_MAIN_HANDLED

#include <stdio.h>
#include "window.h"


int main(int argc, char* args[])
{
	CGD_Window* window = cgd_create_window("test", 1280, 720);
	int c;
	scanf("%d", &c);
	return 0;
}