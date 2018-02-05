//
// Created by andreas on 2018-02-05.
//

#ifndef CGD_LIB_LIGHT_H
#define CGD_LIB_LIGHT_H

#include <cglm/cglm.h>

typedef struct {
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float linear;
    float quadratic;
} CGD_PointLight;

typedef struct {
    vec3 direction;
    vec3 ambient;
    vec3 diffuse;
   vec3 specular;
} CGD_DirectionalLight;


#endif //CGD_LIB_LIGHT_H
