//
// Created by ANDREAS WESTMAN
// on 2019-07-16.
//

#include "cameratest.h"

float vertices[] = {
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
    0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
    0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

    0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
    0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
};
// world space positions of our cubes
vec3 cubePositions[] = {
    { 0.0f,  0.0f,  0.0f},
    { 2.0f,  5.0f, -15.0f},
    {-1.5f, -2.2f, -2.5f},
    {-3.8f, -2.0f, -12.3f},
    { 2.4f, -0.4f, -3.5f},
    {-1.7f,  3.0f, -7.5f},
    { 1.3f, -2.0f, -2.5f},
    { 1.5f,  2.0f, -2.5f},
    { 1.5f,  0.2f, -1.5f},
    {-1.3f,  1.0f, -1.5f}
};
static unsigned int vbo, vao;

static CGD_ShaderProgram *shader;
static CGD_Texture *texture1;
static CGD_Texture *texture2;
static CGD_Camera *camera;


void init()
{
    float pos[] = {0.0f, 0.0f, 3.0f};
    camera = cgd_camera_create(pos, 1920, 1080);

    char vert_buff[4096];
    char frag_buff[4096];

    cgd_file_to_str("shader/tests/camera_test.vs", vert_buff);
    cgd_file_to_str("shader/tests/camera_test.fs", frag_buff);
    shader = cgd_shader_create(vert_buff, frag_buff);

    texture1 = cgd_texture_create("res/test/container.jpg", CGD_DIFFUSE);
    texture2 = cgd_texture_create("res/test/awesomeface.png", CGD_DIFFUSE);

    cgd_shader_start(shader);
    cgd_shader_setint(shader, "texture1", 0);
    cgd_shader_setint(shader, "texture2", 1);

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glEnable(GL_DEPTH_TEST);

}

void render(float delta)
{
    // ------
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    handle_input(delta);

    // bind textures on corresponding texture units

    cgd_texture_bind(texture1, GL_TEXTURE0);
    cgd_texture_bind(texture2, GL_TEXTURE1);


    // render container
    cgd_shader_start(shader);
    cgd_camera_update(camera);

    cgd_shader_setmat4(shader, "projection", camera->projection);
    cgd_shader_setmat4(shader, "view", camera->view);

    glBindVertexArray(vao);
    for (unsigned int i = 0; i < 10; i++)
        {
            // calculate the model matrix for each object and pass it to shader before drawing
            mat4 model = GLM_MAT4_IDENTITY_INIT; // make sure to initialize matrix to identity matrix first
            glm_translate(model, cubePositions[i]);
            float angle = 20.0f * i;
            glm_rotate(model, glm_rad(angle), (vec3){1.0f, 0.3f, 0.5f});
            cgd_shader_setmat4(shader, "model", model);
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }

}

void handle_input(float delta)
{

    float camera_speed = 0.01 * delta;

    if (cgd_input_key_down(CGD_KEY_W))
        camera->position[2] -= camera_speed;
    if (cgd_input_key_down(CGD_KEY_S))
        camera->position[2] += camera_speed;

    if (cgd_input_key_down(CGD_KEY_A))
        camera->position[0] -= camera_speed;
    if (cgd_input_key_down(CGD_KEY_D))
        camera->position[0] += camera_speed;

    static int last_x = 1920/2;
    static int last_y = 1080/2;
    int mouse_x;
    int mouse_y;

    SDL_GetMouseState(&mouse_x, &mouse_y);

    float offset_x = -(last_x - mouse_x);
    float offset_y = last_y - mouse_y;

    camera->rotation[0] = offset_y * 0.2f;
    camera->rotation[1] = offset_x * 0.2f;

    if (camera->rotation[0] > 89.0f)
        camera->rotation[0] = 89.0f;
    if (camera->rotation[0] < -89.0f)
        camera->rotation[0] = -89.0f;

    cgd_camera_update(camera);




}



void dispose()
{

}
