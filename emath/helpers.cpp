#include "helpers.hpp"
#include <cmath>

namespace emath {

auto to_mat4(const quat& q) -> mat4 {
    mat4 result(1.0f);

    const float xx = q.x * q.x;
    const float yy = q.y * q.y;
    const float zz = q.z * q.z;
    const float xy = q.x * q.y;
    const float xz = q.x * q.z;
    const float yz = q.y * q.z;
    const float wx = q.w * q.x;
    const float wy = q.w * q.y;
    const float wz = q.w * q.z;

    result[0][0] = 1.0f - 2.0f * (yy + zz);
    result[0][1] = 2.0f * (xy + wz);
    result[0][2] = 2.0f * (xz - wy);

    result[1][0] = 2.0f * (xy - wz);
    result[1][1] = 1.0f - 2.0f * (xx + zz);
    result[1][2] = 2.0f * (yz + wx);

    result[2][0] = 2.0f * (xz + wy);
    result[2][1] = 2.0f * (yz - wx);
    result[2][2] = 1.0f - 2.0f * (xx + yy);

    return result;
}

auto to_quat(const mat4& m) -> quat {
    float trace = m[0][0] + m[1][1] + m[2][2];

    if (trace > 0.0f) {
        float s = 0.5f / std::sqrt(trace + 1.0f);
        return quat(
            0.25f / s,
            (m[2][1] - m[1][2]) * s,
            (m[0][2] - m[2][0]) * s,
            (m[1][0] - m[0][1]) * s
        );
    } else if (m[0][0] > m[1][1] && m[0][0] > m[2][2]) {
        float s = 2.0f * std::sqrt(1.0f + m[0][0] - m[1][1] - m[2][2]);
        return quat(
            (m[2][1] - m[1][2]) / s,
            0.25f * s,
            (m[0][1] + m[1][0]) / s,
            (m[0][2] + m[2][0]) / s
        );
    } else if (m[1][1] > m[2][2]) {
        float s = 2.0f * std::sqrt(1.0f + m[1][1] - m[0][0] - m[2][2]);
        return quat(
            (m[0][2] - m[2][0]) / s,
            (m[0][1] + m[1][0]) / s,
            0.25f * s,
            (m[1][2] + m[2][1]) / s
        );
    } else {
        float s = 2.0f * std::sqrt(1.0f + m[2][2] - m[0][0] - m[1][1]);
        return quat(
            (m[1][0] - m[0][1]) / s,
            (m[0][2] + m[2][0]) / s,
            (m[1][2] + m[2][1]) / s,
            0.25f * s
        );
    }
}

auto scale(const mat4& m, const vec3& v) -> mat4 {
    mat4 result;
    result[0] = m[0] * v.x;
    result[1] = m[1] * v.y;
    result[2] = m[2] * v.z;
    result[3] = m[3];
    return result;
}

auto translate(const mat4& m, const vec3& v) -> mat4 {
    mat4 result = m;
    result[3] = m[0] * v.x + m[1] * v.y + m[2] * v.z + m[3];
    return result;
}

auto perspective(float fov, float aspect, float zNear, float zFar) -> mat4 {
    const float f = 1.0f / std::tan(fov * 0.5f);

    mat4 result(0.0f);
    result[0][0] = f / aspect;
    result[1][1] = f;
    result[2][2] = (zFar + zNear) / (zNear - zFar);
    result[2][3] = -1.0f;
    result[3][2] = (2.0f * zFar * zNear) / (zNear - zFar);

    return result;
}

auto ortho(float left, float right, float bottom, float top, float zNear, float zFar) -> mat4 {
    mat4 result(1.0f);
    result[0][0] = 2.0f / (right - left);
    result[1][1] = 2.0f / (top - bottom);
    result[2][2] = -2.0f / (zFar - zNear);

    result[3][0] = -(right + left) / (right - left);
    result[3][1] = -(top + bottom) / (top - bottom);
    result[3][2] = -(zFar + zNear) / (zFar - zNear);

    return result;
}

auto ortho(float left, float right, float bottom, float top) -> mat4 {
    mat4 result(1.0f);
    result[0][0] = 2.0f / (right - left);
    result[1][1] = 2.0f / (top - bottom);
    result[2][2] = -1.0f;

    result[3][0] = -(right + left) / (right - left);
    result[3][1] = -(top + bottom) / (top - bottom);

    return result;
}

auto decompose(mat4 ModelMatrix, vec3& Scale, quat& Orientation, vec3& Translation, vec3& Skew, vec4& Perspective) -> bool {
    mat4 M = ModelMatrix;

    // Extract perspective
    if (std::abs(M[3][3]) < 0.001f) {
        return false;
    }

    for (int i = 0; i < 4; ++i) {
        Perspective[i] = M[i][3];
    }
    M[0][3] = 0.0f;
    M[1][3] = 0.0f;
    M[2][3] = 0.0f;
    M[3][3] = 1.0f;

    // Extract translation
    Translation = vec3(M[3][0], M[3][1], M[3][2]);
    M[3][0] = 0.0f;
    M[3][1] = 0.0f;
    M[3][2] = 0.0f;

    // Extract scale and rotation
    vec3 Row0(M[0][0], M[1][0], M[2][0]);
    vec3 Row1(M[0][1], M[1][1], M[2][1]);
    vec3 Row2(M[0][2], M[1][2], M[2][2]);

    Scale.x = Row0.magnitude();
    Scale.y = Row1.magnitude();
    Scale.z = Row2.magnitude();

    Skew = vec3(0.0f);

    mat4 Rotation = M;
    if (Scale.x != 0.0f) {
        Rotation[0][0] /= Scale.x;
        Rotation[1][0] /= Scale.x;
        Rotation[2][0] /= Scale.x;
    }
    if (Scale.y != 0.0f) {
        Rotation[0][1] /= Scale.y;
        Rotation[1][1] /= Scale.y;
        Rotation[2][1] /= Scale.y;
    }
    if (Scale.z != 0.0f) {
        Rotation[0][2] /= Scale.z;
        Rotation[1][2] /= Scale.z;
        Rotation[2][2] /= Scale.z;
    }

    Orientation = to_quat(Rotation);

    return true;
}

auto look_at(const vec3& eye, const vec3& center, const vec3& up) -> mat4 {
    const vec3 f = vec3::normalize(center - eye);
    const vec3 s = vec3::normalize(vec3::cross(f, up));
    const vec3 u = vec3::cross(s, f);

    mat4 result(1.0f);
    result[0][0] = s.x;
    result[1][0] = s.y;
    result[2][0] = s.z;

    result[0][1] = u.x;
    result[1][1] = u.y;
    result[2][1] = u.z;

    result[0][2] = -f.x;
    result[1][2] = -f.y;
    result[2][2] = -f.z;

    result[3][0] = -vec3::dot(s, eye);
    result[3][1] = -vec3::dot(u, eye);
    result[3][2] = vec3::dot(f, eye);

    return result;
}

auto euler_angles(const quat& q) -> vec3 {
    float sinr_cosp = 2.0f * (q.w * q.x + q.y * q.z);
    float cosr_cosp = 1.0f - 2.0f * (q.x * q.x + q.y * q.y);
    float roll = std::atan2(sinr_cosp, cosr_cosp);

    float sinp = 2.0f * (q.w * q.y - q.z * q.x);
    float pitch;
    if (std::abs(sinp) >= 1.0f) {
        pitch = std::copysign(3.14159265359f / 2.0f, sinp);
    } else {
        pitch = std::asin(sinp);
    }

    float siny_cosp = 2.0f * (q.w * q.z + q.x * q.y);
    float cosy_cosp = 1.0f - 2.0f * (q.y * q.y + q.z * q.z);
    float yaw = std::atan2(siny_cosp, cosy_cosp);

    return vec3(roll, pitch, yaw);
}

} // namespace emath
