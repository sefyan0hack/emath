#pragma once
#include "vec2.hpp"
#include <cstddef>

namespace emath {

struct mat2 {

    mat2();
    mat2(float m00, float m01, float m10, float m11);
    mat2(float diag);

    auto operator[](size_t i) -> vec2&;
    auto operator[](size_t i) const -> const vec2&;

    auto operator+(const mat2& m) const -> mat2;
    auto operator-(const mat2& m) const -> mat2;

    auto operator*(float s) const -> mat2;
    friend auto operator*(float s, const mat2& m) -> mat2;

    auto operator<=>(const mat2&) const = default;

    auto operator*(const mat2& m) const -> mat2;
    auto determinant() const -> float;
    auto inverse() const -> mat2;
    auto transpose() const -> mat2;

    vec2 data[2];

};

}