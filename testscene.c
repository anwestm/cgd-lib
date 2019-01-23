//
// Created by andreas on 2018-01-28.
//

#include "testscene.h"
#include "libcgd/camera.h"

vec3 cube_pos[] = {
        {0.0f,  0.0f,  0.0f},
        {2.0f,  5.0f,  -15.0f},
        {-1.5f, -2.2f, -2.5f},
        {-3.8f, -2.0f, -12.3f},
        {2.4f,  -0.4f, -3.5f},
        {-1.7f, 3.0f,  -7.5f},
        {1.3f,  -2.0f, -2.5f},
        {1.5f,  2.0f,  -2.5f},
        {1.5f,  0.2f,  -1.5f},
        {-1.3f, 1.0f,  -1.5f}
};

vec3 plight_pos[] = {
        {0.7f, 0.2f, 2.0f},
        {2.3f, -3.3f, -4.0f},
        {-4.0f, 2.0f, -12.0f},
        {0.0f, 0.0f, -3.0f}
};

float vertices[] = {
        // positions          // normals           // texture coords
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
        0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
};

unsigned int EBO;
unsigned int VBO;
unsigned int cube_VAO;

unsigned int light_VAO;

CGD_ShaderProgram* shader;
CGD_ShaderProgram* lamp_shader;
CGD_Camera *camera;
CGD_Texture *box_diff;
CGD_Texture *box_spec;

CGD_DirectionalLight *dir_light;
CGD_PointLight *point_lights[4];


void init()
{
    printf("init\n");

    char vertBuff[4096];
    char fragBuff[4096];

    cgd_file_to_str("shader/superShader.vs", vertBuff);
    cgd_file_to_str("shader/superShader.fs", fragBuff);
    shader = cgd_shader_create(vertBuff, fragBuff);

    cgd_shader_start(shader);

    cgd_file_to_str("shader/lampShader.vs", vertBuff);
    cgd_file_to_str("shader/lampShader.fs", fragBuff);
    lamp_shader = cgd_shader_create(vertBuff,fragBuff);

    box_diff = cgd_texture_create("res/box.png", DIFFUSE);
    box_spec = cgd_texture_create("res/box_spec.png", SPECULAR);

    camera = cgd_camera_create((vec3){0.0f, 0.0f, 0.0f}, 1920, 1080);


    dir_light = malloc(sizeof(CGD_DirectionalLight));
    glm_vec3_copy((vec3){-0.2f, -1.0f, -0.3f}, dir_light->direction);
    glm_vec3_copy((vec3){0.05f, 0.05f, 0.05f}, dir_light->ambient);
    glm_vec3_copy((vec3){0.4f, 0.4f, 0.4f}, dir_light->diffuse);
    glm_vec3_copy((vec3){0.5f, 0.5f, 0.5f}, dir_light->specular);

    for (int i = 0; i < 4; i++)
    {
        point_lights[i] = malloc(sizeof(CGD_PointLight));
        glm_vec3_copy(plight_pos[i], point_lights[i]->position);
        glm_vec3_copy((vec3){0.05f, 0.05f, 0.05f}, point_lights[i]->ambient);
        glm_vec3_copy((vec3){0.8f, 0.8f, 0.8f}, point_lights[i]->diffuse);
        glm_vec3_copy((vec3){1.0f, 1.0f, 1.0f}, point_lights[i]->specular);
        point_lights[i]->linear = 0.09f;
        point_lights[i]->quadratic = 0.032f;
    }

    glEnable(GL_DEPTH_TEST);

    glViewport(0, 0, 1920, 1090);

    glGenVertexArrays(1, &cube_VAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(cube_VAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glGenVertexArrays(1, &light_VAO);
    glBindVertexArray(light_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

}

void render(const float delta)
{
    //handle_input(delta);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    mat4 model_mat;
    glm_mat4_copy((mat4)GLM_MAT4_IDENTITY_INIT, model_mat);

    cgd_camera_update(camera);

    cgd_shader_start(shader);
    glm_translate(model_mat, (vec3) {0.0f, 0.0f, 3.0f});
    //glm_scale(model_mat, (vec3){0.2f, 0.2f, 0.2f});

    cgd_shader_setmat4(shader, "model", model_mat);
    cgd_shader_setmat4(shader, "projection", camera->projection);
    cgd_shader_setmat4(shader, "view", camera->view);
    cgd_shader_setvec3(shader, "viewPos", camera->position);

    //printf("cam");
    //glm_vec3_print(camera->position, stdout);

    cgd_shader_setint(shader, "material.diffuse", 0);
    cgd_shader_setint(shader, "material.specular", 1);
    cgd_shader_setfloat(shader, "material.shininess", 16.0f);

    cgd_shader_setvec3(shader, "dirLight.direction", dir_light->direction);
    cgd_shader_setvec3(shader, "dirLight.ambient", dir_light->ambient);
    cgd_shader_setvec3(shader, "dirLight.diffuse", dir_light->diffuse);
    cgd_shader_setvec3(shader, "dirLight.specular", dir_light->specular);

    for (int i = 0; i < 4; i++)
    {
        char out[32] ;

        sprintf(out, "pointLights[%d].position", i);
        cgd_shader_setvec3(shader, out, point_lights[i]->position);

        sprintf(out, "pointLights[%d].ambient\n", i);
        cgd_shader_setvec3(shader, out, point_lights[i]->ambient);

        sprintf(out, "pointLights[%d].diffuse\n", i);
        cgd_shader_setvec3(shader, out, point_lights[i]->diffuse);

        sprintf(out, "pointLights[%d].specular\n", i);
        cgd_shader_setvec3(shader, out, point_lights[i]->specular);

        sprintf(out, "pointLights[%d].constant\n", i);
        cgd_shader_setfloat(shader, out, point_lights[i]->specular[0]);

        sprintf(out, "pointLights[%d].linear\n", i);
        cgd_shader_setfloat(shader, out, point_lights[i]->linear);

        sprintf(out, "pointLights[%d].quadratic\n", i);
        cgd_shader_setfloat(shader, out, point_lights[i]->quadratic);

    }

    glActiveTexture(GL_TEXTURE0);
    cgd_texture_bind(box_diff);

    glActiveTexture(GL_TEXTURE1);
    cgd_texture_bind(box_spec);

    glBindVertexArray(cube_VAO);
    for (int i = 0; i < 10; i++)
    {
        mat4 model;
        glm_mat4_copy((mat4)GLM_MAT4_IDENTITY_INIT, model);
        glm_translate(model, cube_pos[i]);
        float angle = 20.0f * i;
        glm_rotate(model, glm_rad(angle), (vec3) {1.0f, 0.3f, 0.5f});
        cgd_shader_setmat4(shader, "model", model);

        glDrawArrays(GL_TRIANGLES, 0, 36);
    }

    cgd_shader_start(lamp_shader);
    cgd_shader_setmat4(lamp_shader, "projection", camera->projection);
    cgd_shader_setmat4(lamp_shader, "view", camera->view);

    glBindVertexArray(light_VAO);
    for (unsigned int i = 0; i < 4; i++)
    {
        mat4 model;
        glm_mat4_copy((mat4)GLM_MAT4_IDENTITY_INIT, model);
        glm_translate(model, plight_pos[i]);
        glm_scale(model, (vec3){0.2f, 0.2f, 0.2f}); // Make it a smaller cube
        cgd_shader_setmat4(lamp_shader, "model", model);
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }
}

void handle_input(float delta)
{
    vec3 front = {0};
    vec3 right = {0};

    front[0] = cosf(glm_rad(camera->rotation[1])) * cosf(glm_rad(camera->rotation[0]));
    front[1] = sinf(glm_rad(camera->rotation[0]));
    front[2] = sinf(glm_rad(camera->rotation[1])) * cosf(glm_rad(camera->rotation[0]));

    glm_vec3_normalize(front);
    glm_vec3_cross(front, GLM_YUP, right);
    glm_vec3_normalize(right);

    float velocity = 5 * delta;
    glm_vec3_scale(front, velocity, front);
    glm_vec3_sub(camera->position, front, camera->position);

    cgd_camera_update(camera);

    //glm_vec3_print(camera->position, stdout);


}

void dispose()
{
    printf("dispose");
}
