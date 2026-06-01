#pragma once

#include "vec3.hpp"
#include "vec4.hpp"
#include "mat4.hpp"
#include "quat.hpp"

namespace emath
{
    auto translate(const mat4& m, const vec3& v) -> mat4;
    auto look_at(const vec3& eye, const vec3& center, const vec3& up) -> mat4;
    auto perspective(float fov, float aspect, float zNear, float zFar) -> mat4; // CLIP_CONfloatROL_(LH/RH)_(ZO/NO) ??
    auto ortho(float left, float right, float bottom, float top, float zNear, float zFar) -> mat4; // CLIP_CONfloatROL_(LH/RH)_(ZO/NO) ??
    auto ortho(float left, float right, float bottom, float top) -> mat4;
    auto to_mat4(const quat& q) -> mat4;
    auto to_quat(const mat4& m) -> quat;
    auto scale(const mat4& m, const vec3& v) -> mat4;
    auto decompose(mat4 ModelMatrix, vec3& Scale, quat& Orientation, vec3& Translation, vec3& Skew, vec4& Perspective) -> bool;
    auto euler_angles(const quat& q) -> vec3;
}