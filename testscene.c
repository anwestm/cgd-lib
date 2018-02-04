//
// Created by andreas on 2018-01-28.
//

#include "testscene.h"

float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
};

unsigned int VBO;
unsigned int VAO;

CGD_ShaderProgram* shader;


void init()
{
    printf("init\n");

    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, 1920, 1080);

    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);


    char vertBuff[256];
    cgd_file_to_str("shader/pass.vert", vertBuff);

    char fragBuff[256];
    cgd_file_to_str("shader/pass.frag", fragBuff);

    shader = cgd_shader_create(vertBuff,fragBuff);
    cgd_shader_start(shader);

}

void render(const float delta)
{
    glClearColor(0.1f, 0.1f, 0.1f, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void dispose()
{
    printf("dispose");
}
