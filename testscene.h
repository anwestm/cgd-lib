//
// Created by andreas on 2018-01-28.
//

#ifndef CGD_LIB_TESTSCENE_H
#define CGD_LIB_TESTSCENE_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <cglm/cglm.h>
#include "libcgd/util.h"
#include "libcgd/window.h"
#include "libcgd/shaderprogram.h"
#include "libcgd/files.h"
#include "libcgd/camera.h"
#include "libcgd/texture.h"
#include "libcgd/light.h"

void init();
void handle_input(float delta);
void render(float delta);
void dispose();

#endif //CGD_LIB_TESTSCENE_H
