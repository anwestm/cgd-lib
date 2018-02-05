//
// Created by andreas on 2018-02-04.
//

#ifndef CGD_LIB_CAMERA_H
#define CGD_LIB_CAMERA_H

#include <cglm/cglm.h>

#define CGD_CAMERA_FOV 67.0f
#define CGD_CAMERA_NEAR 0.1f
#define CGD_CAMERA_FAR 300.0f

typedef struct {
    int width, height;

    mat4 view;
    mat4 projection;
    vec3 position;
    vec3 rotation;

    vec3 _front;
    vec3 _right;
    vec3 _up;


} CGD_Camera;

CGD_Camera *cgd_camera_create(vec3 pos, int width, int height);
void cgd_camera_update(CGD_Camera *camera);

#endif //CGD_LIB_CAMERA_H
