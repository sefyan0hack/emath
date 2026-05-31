#pragma once

#include <cstddef>
#include "vec3.hpp"
#include "mat4.hpp"

namespace emath {

struct mat3 {

    mat3();
    mat3(float diag);
    mat3(float m00, float m01, float m02,
         float m10, float m11, float m12,
         float m20, float m21, float m22);
    explicit mat3(const struct mat4& m);

    auto operator[](size_t i) -> vec3&;
    auto operator[](size_t i) const -> const vec3&;

    auto operator+(const mat3& m) const -> mat3;
    auto operator-(const mat3& m) const -> mat3;

    auto operator*(float s) const -> mat3;
    friend auto operator*(float s, const mat3& m) -> mat3;

    auto operator*(const mat3& m) const -> mat3;

    auto operator<=>(const mat3&) const = default;

    auto determinant() const -> float;
    auto inverse() const -> mat3;
    auto transpose() const -> mat3;

    vec3 data[3];
};


}