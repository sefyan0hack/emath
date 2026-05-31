#include "helpers.hpp"

#include <cassert>

namespace emath {

auto translate(mat4 m, vec3 v) -> mat4
{
    assert(false && "unimplemented");
    return mat4();
}

auto look_at(vec3 eye, vec3 cnter, vec3 up) -> mat4
{
    assert(false && "unimplemented");
    return mat4();
}

auto perspective(float fovy, float aspect, float zNear, float zFar) -> mat4
{
    assert(false && "unimplemented");
    return mat4();
}

auto ortho(float left, float right, float bottom, float top, float zNear, float zFar) -> mat4
{
    assert(false && "unimplemented");
    return mat4();
}

auto to_mat4(quat q) -> mat4
{
    assert(false && "unimplemented");
    return mat4();
}

auto scale(mat4 m, vec3 v) -> mat4
{
    assert(false && "unimplemented");
    return mat4();
}

auto decompose(mat4 ModelMatrix, vec3 &Scale, quat &Orientation, vec3 &Translation, vec3 &Skew, vec4 &Perspective) -> bool
{
    assert(false && "unimplemented");
    return false;
}

auto euler_angles(quat x) -> vec3
{
    assert(false && "unimplemented");
    return vec3();
}

auto ortho(float left, float right, float bottom, float top) -> mat4
{
    const float r_l = right - left;
    const float t_b = top - bottom;
    const float f_n = 1.0f - (-1.0f); // zFar - zNear = 2

    // Translation components
    const float tx = -(right + left) / r_l;
    const float ty = -(top + bottom) / t_b;
    const float tz = -(1.0f + (-1.0f)) / f_n; // = 0

    // Column-major matrix
    mat4 result(0.0f); // Initialize all elements to zero
    result[0][0] = 2.0f / r_l; // Scale X
    result[1][1] = 2.0f / t_b; // Scale Y
    result[2][2] = -2.0f / f_n; // Scale Z ( = -1 )
    result[3][0] = tx;          // Translate X
    result[3][1] = ty;          // Translate Y
    result[3][2] = tz;          // Translate Z ( = 0 )
    result[3][3] = 1.0f;

    return result;
}

}