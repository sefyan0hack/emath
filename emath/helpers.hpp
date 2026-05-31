#pragma once

#include "vec3.hpp"
#include "vec4.hpp"
#include "mat4.hpp"
#include "quat.hpp"

namespace emath
{
    auto translate(mat4 m, vec3 v) -> mat4;
    auto look_at(vec3 eye, vec3 cnter, vec3 up) -> mat4;
    auto perspective(float fovy, float aspect, float zNear, float zFar) -> mat4; // CLIP_CONfloatROL_(LH/RH)_(ZO/NO) ??
    auto ortho(float left, float right, float bottom, float top, float zNear, float zFar) -> mat4; // CLIP_CONfloatROL_(LH/RH)_(ZO/NO) ??
    auto ortho(float left, float right, float bottom, float top) -> mat4;
    auto to_mat4(quat q) -> mat4;
    auto scale(mat4 m, vec3 v) -> mat4;
    auto decompose(mat4 ModelMatrix, vec3& Scale, quat& Orientation, vec3& Translation, vec3& Skew, vec4& Perspective) -> bool;
    auto euler_angles(quat x) -> vec3;
}