//
// Created by andreas on 2018-01-28.
//

#include "testscene.h"
#include "libcgd/camera.h"
#include "libcgd/mesh.h"

float vertices[] = {
        0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
        0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left
};
unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
};

float texCoords[] = {
        0.0f, 0.0f,  // lower-left corner
        1.0f, 0.0f,  // lower-right corner
        0.5f, 1.0f   // top-center corner
};


CGD_ShaderProgram* shader;
CGD_Camera *camera;
CGD_Texture *wall_diff;
CGD_Texture *box_diff;
CGD_Mesh *box_mesh;

unsigned int VBO;
unsigned int VAO;
unsigned int EBO;

void init()
{
    printf("init\n");

    char vertBuff[4096];
    char fragBuff[4096];

    cgd_file_to_str("shader/tex2Shader.vs", vertBuff);
    cgd_file_to_str("shader/tex2Shader.fs", fragBuff);
    shader = cgd_shader_create(vertBuff, fragBuff);

    cgd_shader_start(shader);
    wall_diff = cgd_texture_create("res/wall.jpg", CGD_DIFFUSE);
    box_diff = cgd_texture_create("res/box.png", CGD_DIFFUSE);
    camera = cgd_camera_create((vec3){0.0f, 0.0f, 3.0f}, 1920, 1080);


    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    cgd_shader_start(shader);
    cgd_shader_setint(shader, "texture_diffuse1", 0);
    cgd_shader_setint(shader, "texture_diffuse2", 1);


    glViewport(0, 0, 1920, 1080);
}

void render(const float delta)
{
    handle_input(delta);

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    mat4 model_mat;
    glm_mat4_copy((mat4)GLM_MAT4_IDENTITY_INIT, model_mat);
    glm_rotate(model_mat, glm_rad(-55.0f), (vec3){1.0f, 0.0f, 0.0f});

    //cgd_camera_update(camera);
    cgd_shader_start(shader);
    cgd_shader_setmat4(shader, "model", model_mat);
    cgd_shader_setmat4(shader, "view", camera->view);
    cgd_shader_setmat4(shader, "projection", camera->projection);

    glActiveTexture(GL_TEXTURE0);
    cgd_texture_bind(wall_diff);
    glActiveTexture(GL_TEXTURE1);
    cgd_texture_bind(box_diff);

    glBindVertexArray(VAO);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    //cgd_mesh_draw(box_mesh, shader);

    //printf("cam");
    //glm_vec3_print(camera->position, stdout);

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
