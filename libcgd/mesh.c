//
// Created by andreas on 2018-01-28.
//

#include "mesh.h"
#include "texture.h"
#include <stddef.h>

CGD_Mesh *cgd_mesh_create(CGD_Vertex *vertices, unsigned int *indices, CGD_Texture *textures, size_t vert_len, size_t ind_len, size_t tex_len)
{
    CGD_Mesh *mesh = (CGD_Mesh*) malloc(sizeof(CGD_Mesh));
    if (mesh == NULL) {
        perror("CGD_ERROR cgd_mesh_create: COULD NOT MALLOC MESH");
        return NULL;
    }

    mesh->vert_len = vert_len;
    mesh->index_len = ind_len;
    mesh->tex_len = tex_len;

    mesh->vertices = vertices;
    mesh->indices = indices;
    mesh->textures = textures;

    for (int i = 0; i < vert_len; i++)
        printf("%f ", mesh->vertices[i].position[1]);

  cgd_mesh_setup (mesh);

    return mesh;
}

void cgd_mesh_draw(CGD_Mesh *mesh, CGD_ShaderProgram *shader)
{
    unsigned int diff_count = 1;
    unsigned int spec_count = 0;

    for (unsigned int i = 0; i < mesh->tex_len; i++)
    {
        glActiveTexture(GL_TEXTURE0+i);
        char var_name[32];

        if (mesh->textures[i].type == CGD_DIFFUSE)
        {
            sprintf(var_name, "texture_diffuse%d", diff_count++);
        }
        else if (mesh->textures[i].type == CGD_SPECULAR)
        {
            sprintf(var_name, "texture_specular%d", spec_count++);
        }
        cgd_shader_setfloat(shader, var_name, i);
        glBindTexture(GL_TEXTURE_2D, mesh->textures[i].id);
    }

    glBindVertexArray(mesh->vao_U16);
    glDrawElements(GL_TRIANGLES, mesh->index_len, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

    glActiveTexture(GL_TEXTURE0);

}

void cgd_mesh_setup (CGD_Mesh *mesh)
{
    glGenVertexArrays(1, &mesh->vao_U16);
    glGenBuffers(1, &mesh->_VBO);
    glGenBuffers(1, &mesh->_EBO);

    glBindVertexArray(mesh->vao_U16);

    glBindBuffer(GL_ARRAY_BUFFER, mesh->_VBO);
    glBufferData(GL_ARRAY_BUFFER, mesh->vert_len * sizeof(CGD_Vertex), mesh->vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->index_len * sizeof(unsigned int), mesh->indices, GL_STATIC_DRAW);

    // vertex positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(CGD_Vertex), (void*)0);
    // vertex normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(CGD_Vertex), (void*)offsetof(CGD_Vertex, normal));
    // vertex texture coords
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(CGD_Vertex), (void*)offsetof(CGD_Vertex, texCoords));

    glBindVertexArray(0);
}
