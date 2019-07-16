//
// Created by ANDREAS WESTMAN
// on 2019-07-16.
//

#ifndef _CAMERATEST_H_
#define _CAMERATEST_H_

#include <stdio.h>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <cglm/cglm.h>
#include "../libcgd/util.h"
#include "../libcgd/window.h"
#include "../libcgd/shaderprogram.h"
#include "../libcgd/texture.h"
#include "../libcgd/files.h"
#include "../libcgd/input.h"
#include "../libcgd/camera.h"

void init();
void handle_input(float delta);
void render(float delta);
void dispose();

#endif //_CAMERATEST_H_
