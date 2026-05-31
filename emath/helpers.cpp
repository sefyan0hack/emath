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

}