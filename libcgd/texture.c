//
// Created by andreas on 2018-02-04.
//

#include "texture.h"


CGD_Texture *cgd_texture_create(const char *path, CGD_TEXTURE_TYPE type)
{
    CGD_Texture *texture = malloc(sizeof(CGD_Texture));
    texture->type = type;

    stbi_set_flip_vertically_on_load(GL_TRUE);
    unsigned char *data = stbi_load(path, &texture->width, &texture->height, &texture->channels, 0);
    if (data)
    {
        GLenum format;
        switch (texture->channels)
        {
            case 1:
                format = GL_RED;
                break;
            case 3:
                format = GL_RGB;
                break;
            case 4:
                format = GL_RGBA;
                break;
            default:
                format = GL_NONE;
        }

        printf("%s, %d\n", path, texture->channels);

        glGenTextures(1, &texture->id);
        glBindTexture(GL_TEXTURE_2D, texture->id);

        glTexImage2D(GL_TEXTURE_2D, 0, format, texture->width, texture->height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    } else
    {
        printf("CGD_TEXTURE_ERROR:\n"
                       "Failed to load image %s.\n", path);
    }
    stbi_image_free(data);

    return texture;
}

void cgd_texture_bind(CGD_Texture *texture, int texture_unit)
{
    glActiveTexture(texture_unit);
    glBindTexture(GL_TEXTURE_2D, texture->id);
}
