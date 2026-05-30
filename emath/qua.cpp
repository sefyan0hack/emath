#include "qua.hpp"

#include <cmath>

namespace emath {

qua::qua()
    : w(1.0f)
    , x(0.0f)
    , y(0.0f)
    , z(0.0f) {}

qua::qua(float w, float x, float y, float z)
    : w(w)
    , x(x)
    , y(y)
    , z(z) {}

qua::qua(vec3 eulerAngle)
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

auto qua::length() const -> float {
    return 4;
}

auto qua::magnitude() const -> float {
    return std::sqrt(w * w + x * x + y * y + z * z);
}

auto qua::normalized() const -> qua {
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

auto qua::conjugate() const -> qua {
    return {
        w,
        -x,
        -y,
        -z
    };
}

auto qua::inverse() const -> qua {
    float len2 = w * w + x * x + y * y + z * z;

    if (len2 == 0.0f)
        return {};

    return conjugate() * (1.0f / len2);
}

auto qua::operator[](size_t i) -> float &
{
    return (&x)[i];
}

auto qua::operator[](size_t i) const -> const float &
{
    return (&x)[i];
}

auto operator+(const qua& a,
               const qua& b) -> qua {
    return {
        a.w + b.w,
        a.x + b.x,
        a.y + b.y,
        a.z + b.z
    };
}

auto operator-(const qua& a,
               const qua& b) -> qua {
    return {
        a.w - b.w,
        a.x - b.x,
        a.y - b.y,
        a.z - b.z
    };
}

auto operator*(const qua& q,
               float s) -> qua {
    return {
        q.w * s,
        q.x * s,
        q.y * s,
        q.z * s
    };
}

auto operator*(float s,
               const qua& q) -> qua {
    return q * s;
}

auto operator*(const qua& a,
               const qua& b) -> qua {
    return {
        a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z,
        a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y,
        a.w * b.y - a.x * b.z + a.y * b.w + a.z * b.x,
        a.w * b.z + a.x * b.y - a.y * b.x + a.z * b.w
    };
}

auto angle_axis(float angle, vec3 axis) -> qua {
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

auto rotate(const qua& q, vec3 v) -> vec3 {
    qua p{
        0.0f,
        v.x,
        v.y,
        v.z
    };

    qua r = q * p * q.inverse();

    return {
        r.x,
        r.y,
        r.z
    };
}
}