//
// Created by ANDREAS WESTMAN
// on 2019-07-16.
//

#ifndef _TEXTURETEST_H_
#define _TEXTURETEST_H_

#include <stdio.h>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <cglm/cglm.h>
#include "../libcgd/util.h"
#include "../libcgd/window.h"
#include "../libcgd/shaderprogram.h"
#include "../libcgd/texture.h"
#include "../libcgd/files.h"

void init();
void handle_input(float delta);
void render(float delta);
void dispose();

#endif //_TEXTURETEST_H_
