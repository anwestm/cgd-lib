//
// Created by andreas on 2018-01-28.
//

#ifndef CGD_LIB_TESTSCENE_H
#define CGD_LIB_TESTSCENE_H

#include "libcgd/util.h"
#include "libcgd/window.h"
#include <stdio.h>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "libcgd/shaderprogram.h"
#include "libcgd/files.h"

void init();
void render(float delta);
void dispose();

#endif //CGD_LIB_TESTSCENE_H
