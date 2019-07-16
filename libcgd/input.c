//
// Created by ANDREAS WESTMAN
// on 2019-02-02.
//

#include "input.h"

static char key_down[512];

void cgd_input_handle_event(SDL_Event event)
{
    switch(event.type)
    {
        case SDL_KEYDOWN:
            key_down[event.key.keysym.scancode] = 1;
            break;
        case SDL_KEYUP:
            key_down[event.key.keysym.scancode] = 0;
            break;
    }
}

char cgd_input_key_down(const cgd_keycode code)
{
    return key_down[code] == 1;
}

char cgd_input_key_pressed(const cgd_keycode code)
{
    return key_down[code] == 1;
}
