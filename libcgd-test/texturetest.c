//
// Created by ANDREAS WESTMAN
// on 2019-07-16.
//

#include "texturetest.h"

static float vertices[] = {
    // positions          // colors           // texture coords
    0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
    0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left
};
static unsigned int indices[] = {
    0, 1, 3, // first triangle
    1, 2, 3  // second triangle
};
static unsigned int vbo, vao, ebo;

static CGD_ShaderProgram *shader;
static CGD_Texture *texture1;
static CGD_Texture *texture2;


void init()
{
    char vert_buff[4096];
    char frag_buff[4096];

    cgd_file_to_str("shader/tests/texture_test.vs", vert_buff);
    cgd_file_to_str("shader/tests/texture_test.fs", frag_buff);
    shader = cgd_shader_create(vert_buff, frag_buff);

    texture1 = cgd_texture_create("res/test/container.jpg", CGD_DIFFUSE);
    texture2 = cgd_texture_create("res/test/awesomeface.png", CGD_DIFFUSE);

    cgd_shader_start(shader);
    cgd_shader_setint(shader, "texture1", 0);
    cgd_shader_setint(shader, "texture2", 1);

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

}

void render(float delta)
{
    // ------
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // bind textures on corresponding texture units
    cgd_texture_bind(texture1, GL_TEXTURE0);
    cgd_texture_bind(texture2, GL_TEXTURE1);

    // render container
    cgd_shader_start(shader);
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}

void dispose()
{

}
