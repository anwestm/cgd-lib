//
// Created by andreas on 2018-01-28.
//

#ifndef CGD_LIB_MESH_H
#define CGD_LIB_MESH_H

#include <cglm/cglm.h>
#include "texture.h"
#include "shaderprogram.h"
#include "linkedlist.h"
#include "array.h"

typedef struct {
    vec3 position;
    vec3 normal;
    vec2 texCoords;
} CGD_Vertex;

typedef struct {

    CGD_Vertex *vertices;
    unsigned int *indices;
    CGD_Texture *textures;

    size_t vert_len;
    size_t index_len;
    size_t tex_len;

    unsigned int vao_U16, _VBO, _EBO;

} CGD_Mesh;

CGD_Mesh *cgd_mesh_create(CGD_Vertex *vertices, unsigned int *indices, CGD_Texture *textures, size_t vert_len, size_t ind_len, size_t tex_len);
void cgd_mesh_draw(CGD_Mesh *mesh, CGD_ShaderProgram *shader);
void cgd_mesh_dispose();

void cgd_mesh_setup (CGD_Mesh *mesh);


#endif //CGD_LIB_MESH_H
