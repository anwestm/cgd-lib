//
// Created by andreas on 2018-02-04.
//

#ifndef CGD_LIB_TEXTURE_H
#define CGD_LIB_TEXTURE_H

#include <GL\glew.h>
#include <stdlib.h>
#include "stb_image.h"

typedef enum {
    DIFFUSE, SPECULAR
} CGD_TEXTURE_TYPE;

typedef struct {
    CGD_TEXTURE_TYPE type;
    unsigned int id;

    int width, height, channels;
} CGD_Texture;

CGD_Texture* cgd_texture_create(const char *path, CGD_TEXTURE_TYPE type);
void cgd_texture_bind(CGD_Texture *texture);

#endif //CGD_LIB_TEXTURE_H
