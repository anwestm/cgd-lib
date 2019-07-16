//
// Created by andreas on 2018-02-04.
//

#ifndef CGD_LIB_CAMERA_H
#define CGD_LIB_CAMERA_H

#include <cglm/cglm.h>

#define CGD_CAMERA_FOV 45.0f
#define CGD_CAMERA_NEAR 0.1f
#define CGD_CAMERA_FAR 300.0f

#define YAW -90.0f
#define PITCH 0.0f
#define SPEED 2.5
#define SENSITIVITY 0

typedef struct {
    int width, height;

    mat4 view;
    mat4 projection;
    vec3 position; // {x, y, z}
    vec3 rotation; // {pitch, yaw, roll}

    vec3 m_front;
    vec3 m_right;
    vec3 m_up;


} CGD_Camera;

CGD_Camera *cgd_camera_create(vec3 pos, int width, int height);
void cgd_camera_update(CGD_Camera *camera);

#endif //CGD_LIB_CAMERA_H
