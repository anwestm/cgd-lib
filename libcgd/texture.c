//
// Created by andreas on 2018-02-04.
//

#include <crtdbg.h>
#include "texture.h"


CGD_Texture *cgd_texture_create(const char *path, CGD_TEXTURE_TYPE type)
{
    CGD_Texture *texture = malloc(sizeof(CGD_Texture));

    glGenTextures(1, &texture->id);
    glBindTexture(GL_TEXTURE_2D, texture->id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    unsigned char *data = stbi_load(path, &texture->width, &texture->height, &texture->channels, 3);
    if (data)
    {

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture->width, texture->height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        //GenerateMipmap(GL_TEXTURE_2D);
    } else
    {
        printf("CGD_TEXTURE_ERROR:\n"
                       "Failed to load image %s.\n", path);
    }
    stbi_image_free(data);

    return texture;
}

void cgd_texture_bind(CGD_Texture *texture)
{
    glBindTexture(GL_TEXTURE_2D, texture->id);
}
