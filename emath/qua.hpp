#pragma once
#include <cstddef>
#include "vec3.hpp"

namespace emath {

struct qua {
    float w;
    float x;
    float y;
    float z;

    qua();
    qua(float w, float x, float y, float z);
    qua(vec3 eulerAngle);

    auto length() const -> float;
    auto magnitude() const -> float;
    auto normalized() const -> qua;
    auto conjugate() const -> qua;
    auto inverse() const -> qua;

    friend auto operator+(const qua& a, const qua& b) -> qua;
    friend auto operator-(const qua& a, const qua& b) -> qua;
    friend auto operator*(const qua& q, float s) -> qua;
    friend auto operator*(float s, const qua& q) -> qua;
    friend auto operator*(const qua& a, const qua& b) -> qua;

    auto operator[](size_t i) -> float&;
    auto operator[](size_t i) const -> const float&;
};

auto angle_axis(float angle, vec3 axis) -> qua;
auto rotate(const qua& q, vec3 v) -> vec3;

}