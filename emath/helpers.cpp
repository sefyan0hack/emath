#include "helpers.hpp"

#include <cmath>
#include <numbers>

namespace emath {

auto translate(const mat4& m, const vec3& v) -> mat4
{
    auto t = mat4(
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        v.x, v.y, v.z, 1
    );
    return m * t;
}

auto look_at(const vec3& eye, const vec3& center, const vec3& up) -> mat4
{
    auto f = vec3::normalize(center - eye);          // forward
    auto r = vec3::normalize(vec3::cross(f, up));   // right
    auto u = vec3::cross(r, f);                     // corrected up

    return mat4(
        r.x,  u.x, -f.x, 0,
        r.y,  u.y, -f.y, 0,
        r.z,  u.z, -f.z, 0,
        -vec3::dot(r, eye), 
        -vec3::dot(u, eye), 
         vec3::dot(f, eye), 1
    );
}

auto perspective(float fov, float aspect, float zNear, float zFar) -> mat4
{
    auto t = std::tan(fov/2.0f);
    auto z_f = (zNear - zFar);

    return mat4(
        1.0f/(aspect * t), 0, 0, 0,
        0, 1.0f/t, 0, 0,
        0, 0, (zFar + zNear)/z_f, -1,
        0, 0,  (2 * zFar * zNear)/z_f, 0
    );
}

auto to_mat4(const quat& q) -> mat4
{
    float w = q.w;
    float x = q.x;
    float y = q.y;
    float z = q.z;

    float xx = x * x;
    float yy = y * y;
    float zz = z * z;

    float xy = x * y;
    float xz = x * z;
    float yz = y * z;

    float wx = w * x;
    float wy = w * y;
    float wz = w * z;

    return mat4(
        1 - 2 * (yy + zz),  2 * (xy + wz),      2 * (xz - wy),      0,
        2 * (xy - wz),      1 - 2 * (xx + zz),  2 * (yz + wx),      0,
        2 * (xz + wy),      2 * (yz - wx),      1 - 2 * (xx + yy),  0,
        0,                  0,                  0,                  1
    );
}

auto to_quat(const mat4& m) -> quat
{
    vec3 X(m.data[0].x, m.data[0].y, m.data[0].z);
    vec3 Y(m.data[1].x, m.data[1].y, m.data[1].z);
    vec3 Z(m.data[2].x, m.data[2].y, m.data[2].z);

    // remove scale
    X = vec3::normalize(X);
    Y = vec3::normalize(Y);
    Z = vec3::normalize(Z);

    float trace = X.x + Y.y + Z.z;

    quat q;

    if (trace > 0.0f)
    {
        float s = sqrt(trace + 1.0f) * 2.0f;
        q.w = 0.25f * s;
        q.x = (Y.z - Z.y) / s;
        q.y = (Z.x - X.z) / s;
        q.z = (X.y - Y.x) / s;
    }
    else if (X.x > Y.y && X.x > Z.z)
    {
        float s = sqrt(1.0f + X.x - Y.y - Z.z) * 2.0f;
        q.w = (Y.z - Z.y) / s;
        q.x = 0.25f * s;
        q.y = (Y.x + X.y) / s;
        q.z = (Z.x + X.z) / s;
    }
    else if (Y.y > Z.z)
    {
        float s = sqrt(1.0f + Y.y - X.x - Z.z) * 2.0f;
        q.w = (Z.x - X.z) / s;
        q.x = (Y.x + X.y) / s;
        q.y = 0.25f * s;
        q.z = (Z.y + Y.z) / s;
    }
    else
    {
        float s = sqrt(1.0f + Z.z - X.x - Y.y) * 2.0f;
        q.w = (X.y - Y.x) / s;
        q.x = (Z.x + X.z) / s;
        q.y = (Z.y + Y.z) / s;
        q.z = 0.25f * s;
    }

    return q;
}

auto scale(const mat4& m, const vec3& v) -> mat4
{
    auto scale_mat = mat4(
        v.x, 0, 0, 0,
        0, v.y, 0, 0,
        0, 0, v.z, 0,
        0, 0, 0,   1
    );
    return m * scale_mat;
}

auto decompose(mat4 ModelMatrix, vec3 &Scale, quat &Orientation, vec3 &Translation, vec3 &Skew, vec4 &Perspective) -> bool
{
    // 1. Translation
    Translation = vec3(ModelMatrix.data[3].x, ModelMatrix.data[3].y, ModelMatrix.data[3].z);

    // 2. Extract basis vectors (columns)
    vec3 X(ModelMatrix.data[0].x, ModelMatrix.data[0].y, ModelMatrix.data[0].z);
    vec3 Y(ModelMatrix.data[1].x, ModelMatrix.data[1].y, ModelMatrix.data[1].z);
    vec3 Z(ModelMatrix.data[2].x, ModelMatrix.data[2].y, ModelMatrix.data[2].z);

    // 3. Scale
    Scale.x = X.magnitude();
    Scale.y = Y.magnitude();
    Scale.z = Z.magnitude();

    if (Scale.x == 0 || Scale.y == 0 || Scale.z == 0)
        return false;

    // 4. Remove scale (normalize axes)
    X = X * (1.0f/Scale.x);
    Y = Y * (1.0f/Scale.y);
    Z = Z * (1.0f/Scale.z);

    // 5. Reconstruct rotation matrix (orthonormal)
    mat4 R(
        X.x, X.y, X.z, 0,
        Y.x, Y.y, Y.z, 0,
        Z.x, Z.y, Z.z, 0,
        0,   0,   0,   1
    );

    // 6. Convert rotation matrix → quaternion
    Orientation = to_quat(R);

    // 7. Ignore skew/perspective for now (GLM supports full decomposition)
    Skew = vec3(0);
    Perspective = vec4(0, 0, 0, 1);

    return true;
}

auto euler_angles(const quat& q) -> vec3
{
    float w = q.w;
    float x = q.x;
    float y = q.y;
    float z = q.z;

    // roll (X axis)
    float sinr_cosp = 2 * (w * x + y * z);
    float cosr_cosp = 1 - 2 * (x * x + y * y);
    float roll = std::atan2(sinr_cosp, cosr_cosp);

    // pitch (Y axis)
    float sinp = 2 * (w * y - z * x);
    float pitch;

    if (std::abs(sinp) >= 1)
        pitch = std::copysign(std::numbers::pi_v<float> / 2, sinp);
    else
        pitch = std::asin(sinp);

    // yaw (Z axis)
    float siny_cosp = 2 * (w * z + x * y);
    float cosy_cosp = 1 - 2 * (y * y + z * z);
    float yaw = std::atan2(siny_cosp, cosy_cosp);

    return vec3(roll, pitch, yaw);
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

auto ortho(float left, float right, float bottom, float top, float zNear, float zFar) -> mat4
{
    auto r_l = left - right;
    auto t_b = top - bottom;
    auto f_n = zFar - zNear;
    return mat4(
        2.0f/r_l, 0, 0, 0,
        0, 2.0f/t_b, 0, 0,
        0, 0, -2.0f/f_n,0,
        -(right + left)/r_l, -(top + bottom)/t_b, -(zFar + zNear)/f_n, 1
    );
}

}