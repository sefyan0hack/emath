#include "quat.hpp"

#include <cmath>

namespace emath {

quat::quat()
    : w(1.0f)
    , x(0.0f)
    , y(0.0f)
    , z(0.0f) {}

quat::quat(float w, float x, float y, float z)
    : w(w)
    , x(x)
    , y(y)
    , z(z) {}

quat::quat(vec3 eulerAngle)
{
    float cx = std::cos(eulerAngle.x * 0.5f);
    float sx = std::sin(eulerAngle.x * 0.5f);

    float cy = std::cos(eulerAngle.y * 0.5f);
    float sy = std::sin(eulerAngle.y * 0.5f);

    float cz = std::cos(eulerAngle.z * 0.5f);
    float sz = std::sin(eulerAngle.z * 0.5f);

    w = cx * cy * cz + sx * sy * sz;
    x = sx * cy * cz - cx * sy * sz;
    y = cx * sy * cz + sx * cy * sz;
    z = cx * cy * sz - sx * sy * cz;
}

auto quat::length() const -> float {
    return 4;
}

auto quat::magnitude() const -> float {
    return std::sqrt(w * w + x * x + y * y + z * z);
}

auto quat::normalized() const -> quat {
    float len = magnitude();

    if (len == 0.0f)
        return {};

    return {
        w / len,
        x / len,
        y / len,
        z / len
    };
}

auto quat::conjugate() const -> quat {
    return {
        w,
        -x,
        -y,
        -z
    };
}

auto quat::inverse() const -> quat {
    float len2 = w * w + x * x + y * y + z * z;

    if (len2 == 0.0f)
        return {};

    return conjugate() * (1.0f / len2);
}

auto quat::operator[](size_t i) -> float &
{
    return (&x)[i];
}

auto quat::operator[](size_t i) const -> const float &
{
    return (&x)[i];
}

auto operator+(const quat& a,
               const quat& b) -> quat {
    return {
        a.w + b.w,
        a.x + b.x,
        a.y + b.y,
        a.z + b.z
    };
}

auto operator-(const quat& a,
               const quat& b) -> quat {
    return {
        a.w - b.w,
        a.x - b.x,
        a.y - b.y,
        a.z - b.z
    };
}

auto operator*(const quat& q,
               float s) -> quat {
    return {
        q.w * s,
        q.x * s,
        q.y * s,
        q.z * s
    };
}

auto operator*(float s,
               const quat& q) -> quat {
    return q * s;
}

auto operator*(const quat& a,
               const quat& b) -> quat {
    return {
        a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z,
        a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y,
        a.w * b.y - a.x * b.z + a.y * b.w + a.z * b.x,
        a.w * b.z + a.x * b.y - a.y * b.x + a.z * b.w
    };
}

auto angle_axis(float angle, vec3 axis) -> quat {
    float half = angle * 0.5f;

    float s = std::sin(half);
    float c = std::cos(half);

    return {
        c,
        axis.x * s,
        axis.y * s,
        axis.z * s
    };
}

auto rotate(const quat& q, vec3 v) -> vec3 {
    quat p{
        0.0f,
        v.x,
        v.y,
        v.z
    };

    quat r = q * p * q.inverse();

    return {
        r.x,
        r.y,
        r.z
    };
}
}