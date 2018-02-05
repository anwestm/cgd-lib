//
// Created by andreas on 2018-02-04.
//

#include "camera.h"

CGD_Camera *cgd_camera_create(vec3 pos, int width, int height)
{
    CGD_Camera *camera = malloc(sizeof(CGD_Camera));
    camera->width = width;
    camera->height = height;


    glm_vec_copy(pos, camera->position);
    glm_vec_copy((vec3) {0.0f, -90.0f, 0.0f}, camera->rotation);
    glm_vec_copy((vec3) {0.0f, 0.0f, -1.0f}, camera->_front);

    cgd_camera_update(camera);

    return camera;
}

void cgd_camera_update(CGD_Camera *camera)
{
    glm_perspective(glm_rad(CGD_CAMERA_FOV), camera->width / (float) camera->height,
                    CGD_CAMERA_NEAR, CGD_CAMERA_FAR, camera->projection);

    camera->_front[0] = cosf(glm_rad(camera->rotation[1])) * cosf(glm_rad(camera->rotation[0]));
    camera->_front[1] = sinf(glm_rad(camera->rotation[0]));
    camera->_front[2] = sinf(glm_rad(camera->rotation[1])) * cosf(glm_rad(camera->rotation[0]));

    glm_vec_normalize(camera->_front);

    glm_vec_cross(camera->_front, GLM_YUP, camera->_right);
    glm_vec_normalize(camera->_right);

    glm_vec_cross(camera->_right, camera->_front, camera->_up);

    vec3 center = {0};
    glm_vec_add(camera->position, camera->_front, center);
    glm_lookat(camera->position, center, camera->_up, camera->view);
}
