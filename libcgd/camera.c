//
// Created by andreas on 2018-02-04.
//

#include "camera.h"

CGD_Camera *cgd_camera_create(vec3 pos, int width, int height)
{
    CGD_Camera *camera = malloc(sizeof(CGD_Camera));
    camera->width = width;
    camera->height = height;

    glm_vec3_copy(pos, camera->position);
    glm_vec3_copy((vec3) {0.0f, -90.0f, 0.0f}, camera->rotation);
    glm_vec3_copy((vec3) {0.0f, 0.0f, -1.0f}, camera->m_front);
    glm_vec3_copy(GLM_YUP, camera->m_up);

    glm_mat4_copy(GLM_MAT4_IDENTITY, camera->view);
    glm_translate(camera->view, pos);

    glm_perspective(glm_rad(CGD_CAMERA_FOV), (float) camera->width / (float) camera->height,
                    CGD_CAMERA_NEAR, CGD_CAMERA_FAR, camera->projection);

    cgd_camera_update(camera);

    return camera;
}

void cgd_camera_update(CGD_Camera *camera)
{

    camera->m_front[0] = cosf(glm_rad(camera->rotation[1])) * cosf(glm_rad(camera->rotation[0]));
    camera->m_front[1] = sinf(glm_rad(camera->rotation[0]));
    camera->m_front[2] = sinf(glm_rad(camera->rotation[1])) * cosf(glm_rad(camera->rotation[0]));
    glm_vec3_normalize(camera->m_front);

    glm_vec3_cross(camera->m_front, GLM_YUP, camera->m_right);
    glm_vec3_normalize(camera->m_right);

    glm_vec3_cross(camera->m_right, camera->m_front, camera->m_up);
    glm_vec3_normalize(camera->m_up);



    vec3 center;
    glm_vec3_add(camera->position, camera->m_front, center);
    glm_lookat(camera->position, center, camera->m_up, camera->view);
}
