//
// Created by ANDREAS WESTMAN
// on 2019-07-16.
//

#include "lamptest.h"

float vertices[] = {
    -0.5f, -0.5f, -0.5f,
    0.5f, -0.5f, -0.5f,
    0.5f,  0.5f, -0.5f,
    0.5f,  0.5f, -0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,

    -0.5f, -0.5f,  0.5f,
    0.5f, -0.5f,  0.5f,
    0.5f,  0.5f,  0.5f,
    0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,

    -0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,

    0.5f,  0.5f,  0.5f,
    0.5f,  0.5f, -0.5f,
    0.5f, -0.5f, -0.5f,
    0.5f, -0.5f, -0.5f,
    0.5f, -0.5f,  0.5f,
    0.5f,  0.5f,  0.5f,

    -0.5f, -0.5f, -0.5f,
    0.5f, -0.5f, -0.5f,
    0.5f, -0.5f,  0.5f,
    0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f, -0.5f,

    -0.5f,  0.5f, -0.5f,
    0.5f,  0.5f, -0.5f,
    0.5f,  0.5f,  0.5f,
    0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
};

static CGD_ShaderProgram *lamp_shader;
static CGD_ShaderProgram *light_shader;
static CGD_Camera *camera;

static unsigned int light_vao, cube_vao;
static unsigned int vbo;

void init()
{
    camera = cgd_camera_create((vec3){0.0f, 0.0f, 3.0f}, 1920, 1080);

    char vert_buff[4096];
    char frag_buff[4096];

    cgd_file_to_str("shader/tests/lamp_test.vs", vert_buff);
    cgd_file_to_str("shader/tests/lamp_test.fs", frag_buff);
    lamp_shader = cgd_shader_create(vert_buff, frag_buff);

    cgd_file_to_str("shader/tests/color_test.vs", vert_buff);
    cgd_file_to_str("shader/tests/color_test.fs", frag_buff);
    light_shader = cgd_shader_create(vert_buff, frag_buff);



    glEnable(GL_DEPTH_TEST);

    glGenVertexArrays(1, &cube_vao);
    glGenBuffers(1, &vbo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(cube_vao);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glGenVertexArrays(1, &light_vao);
    glBindVertexArray(light_vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

}

void render(float delta)
{
    // ------
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   //handle_input(delta);


    cgd_shader_start(light_shader);
    cgd_shader_setvec3(light_shader, "objectColor", (vec3){1.0f, 0.5f, 0.31f});
    cgd_shader_setvec3(light_shader, "lightColor", (vec3){1.0f, 1.0f, 1.0f});

    // view/projection transformations
    cgd_camera_update(camera);
    cgd_shader_setmat4(light_shader, "projection", camera->projection);
    cgd_shader_setmat4(light_shader, "view", camera->view);

    // world transformation
    mat4 model = GLM_MAT4_IDENTITY_INIT;
    cgd_shader_setmat4(light_shader, "model", model);

    // render the cube
    glBindVertexArray(cube_vao);
    glDrawArrays(GL_TRIANGLES, 0, 36);


    // also draw the lamp object
    cgd_shader_start(lamp_shader);
    cgd_shader_setmat4(lamp_shader, "projection", camera->projection);
    cgd_shader_setmat4(lamp_shader, "view", camera->view);

    glm_mat4_copy(GLM_MAT4_IDENTITY, model);
    glm_translate(model, (vec3){1.2f, 1.0f, 2.0f});
    glm_scale(model, (vec3){0.2f, 0.2f, 0.2f});
    cgd_shader_setmat4(lamp_shader, "model", model);

    glBindVertexArray(light_vao);
    glDrawArrays(GL_TRIANGLES, 0, 36);


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