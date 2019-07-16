//
// Created by ANDREAS WESTMAN
// on 2019-07-16.
//

#include "shadertest.h"

static float vertices[] = {
    // positions         // colors
    0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  // bottom left
    0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f   // top
};

static unsigned int vbo, vao;

static CGD_ShaderProgram *shader;

void init()
{
    char vert_buff[4096];
    char frag_buff[4096];

    cgd_file_to_str("shader/tests/shader_test.vs", vert_buff);
    cgd_file_to_str("shader/tests/shader_test.fs", frag_buff);
    shader = cgd_shader_create(vert_buff, frag_buff);

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

}

void render(float delta)
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // render the triangle
    cgd_shader_start(shader);
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void dispose()
{

}
