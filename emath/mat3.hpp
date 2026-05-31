#pragma once

#include "vec3.hpp"

#include <cstddef>
#include <format>

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

#ifdef __cpp_lib_formatters
template<>
struct std::formatter<emath::mat3> {
  constexpr auto parse(std::format_parse_context& context) {
    return context.begin();
  }
  auto format(const emath::mat3& obj, auto& context) const {
    return std::format_to(context.out(),
    "[[ {}, {}, {} ], "
    "[ {}, {}, {} ], "
    "[ {}, {}, {} ]]",
    obj[0][0], obj[1][0], obj[2][0],
    obj[0][1], obj[1][1], obj[2][1],
    obj[0][2], obj[1][2], obj[2][2]);
  }
};
#endif