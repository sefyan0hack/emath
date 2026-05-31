#pragma once
#include "vec4.hpp"

#include <cstddef>
#include <format>

namespace emath {

struct mat4 {
    mat4();
    mat4(float diag);
    mat4(float m00, float m01, float m02, float m03,
         float m10, float m11, float m12, float m13,
         float m20, float m21, float m22, float m23,
         float m30, float m31, float m32, float m33);

    explicit mat4(const struct mat3& m);
    auto operator[](size_t i) -> vec4&;
    auto operator[](size_t i) const -> const vec4&;

    auto operator+(const mat4& m) const -> mat4;
    auto operator-(const mat4& m) const -> mat4;
    auto operator*(float s) const -> mat4;
    auto operator*(const mat4& m) const -> mat4;

    friend auto operator*(float s, const mat4& m) -> mat4;

    auto operator<=>(const mat4&) const = default;

    auto determinant() const -> float;
    auto inverse() const -> mat4;
    auto transpose() const -> mat4;

    vec4 data[4];
};

}
#ifdef __cpp_lib_formatters
template<>
struct std::formatter<emath::mat4> {
    constexpr auto parse(std::format_parse_context& context) {
        return context.begin();
    }

    auto format(const emath::mat4& obj, auto& context) const {
        return std::format_to(
            context.out(),
            "[[ {}, {}, {}, {} ], "
            "[ {}, {}, {}, {} ], "
            "[ {}, {}, {}, {} ], "
            "[ {}, {}, {}, {} ]]",

            obj[0][0], obj[1][0], obj[2][0], obj[3][0],
            obj[0][1], obj[1][1], obj[2][1], obj[3][1],
            obj[0][2], obj[1][2], obj[2][2], obj[3][2],
            obj[0][3], obj[1][3], obj[2][3], obj[3][3]
        );
    }
};
#endif
