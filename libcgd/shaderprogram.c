#include "shaderprogram.h"

#define LOG_SIZE 512

CGD_ShaderProgram *cgd_shader_create(const char *vertexCode, const char *fragmentCode)
{
    unsigned int vertex, fragment;
    int success;
    char log[LOG_SIZE];

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertexCode, NULL);
    glCompileShader(vertex);
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertex, LOG_SIZE, NULL, log);
        printf("CGD_SHADER_ERROR:\n%s\n", log);
    }

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragmentCode, NULL);
    glCompileShader(fragment);
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragment, LOG_SIZE, NULL, log);
        printf("CGD_SHADER_ERROR:\n%s\n", log);
    }

    const unsigned int ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(ID, LOG_SIZE, NULL, log);
        printf("CGD_SHADER_ERROR:\n%s\n", log);
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);

    CGD_ShaderProgram *shader = malloc(sizeof(CGD_ShaderProgram));
    shader->id = ID;
    return shader;
}

void cgd_shader_start(CGD_ShaderProgram *shader)
{
    glUseProgram(shader->id);
}

void cgd_shader_setint(CGD_ShaderProgram *shader, const char *name, int val)
{
    glUniform1i(glGetUniformLocation(shader->id, name), val);
}

void cgd_shader_setfloat(CGD_ShaderProgram *shader, const char *name, float val)
{
    glUniform1f(glGetUniformLocation(shader->id, name), val);
}

void cgd_shader_setvec3(CGD_ShaderProgram *shader, const char *name, vec3 val)
{
    glUniform3f(glGetUniformLocation(shader->id, name), val[0], val[1], val[2]);
}

void cgd_shader_setmat4(CGD_ShaderProgram *shader, const char *name, mat4 val)
{
    GLfloat mat[16];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            mat[i + j * 4] = val[i][j];

    glUniformMatrix4fv(glGetUniformLocation(shader->id, name), 1, GL_FALSE, mat);
}
