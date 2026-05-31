#pragma once
#include <cstddef>
#include "vec3.hpp"

namespace emath {

struct quat {
    float w;
    float x;
    float y;
    float z;

    quat();
    quat(float w, float x, float y, float z);
    quat(vec3 eulerAngle);

    auto length() const -> float;
    auto magnitude() const -> float;
    auto normalized() const -> quat;
    auto conjugate() const -> quat;
    auto inverse() const -> quat;

    friend auto operator+(const quat& a, const quat& b) -> quat;
    friend auto operator-(const quat& a, const quat& b) -> quat;
    friend auto operator*(const quat& q, float s) -> quat;
    friend auto operator*(float s, const quat& q) -> quat;
    friend auto operator*(const quat& a, const quat& b) -> quat;

    auto operator[](size_t i) -> float&;
    auto operator[](size_t i) const -> const float&;

    auto operator<=>(const quat&) const = default;
};

auto angle_axis(float angle, vec3 axis) -> quat;
auto rotate(const quat& q, vec3 v) -> vec3;

}