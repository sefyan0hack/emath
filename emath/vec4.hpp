#pragma once

#include <cstddef>
#include <format>

namespace emath {

struct vec4
{
    vec4();
    vec4(float a);
    vec4(float x, float y, float z, float w);

    auto operator+=(const vec4& other) -> vec4&;
    auto operator-=(const vec4& other) -> vec4&;
    auto operator*=(const vec4& other) -> vec4&;

    auto operator*=(float a) -> vec4&;

    auto operator+(const vec4& other) const -> vec4;
    auto operator-(const vec4& other) const -> vec4;

    auto operator*(const vec4& other) const -> vec4;
    auto operator*(float a) const -> vec4;
    auto operator-() const -> vec4;

    auto operator[](size_t i) -> float&;
    auto operator[](size_t i) const -> const float&;

    auto operator<=>(const vec4&) const = default;

    auto magnitude() const -> float;

    auto is_normalized() const -> bool;

    static auto length() -> int;
    static auto normalize(const vec4& v) -> vec4;
    static auto dot(const vec4& l, const vec4& r) -> float;
    static auto angle(const vec4& l, const vec4& r, bool rad = true) -> float;

    float x, y, z, w;
};

} // namespace emath

#ifdef __cpp_lib_formatters

template<>
struct std::formatter<emath::vec4> {
  constexpr auto parse(std::format_parse_context& context) {
    return context.begin();
  }
  auto format(const emath::vec4& obj, auto& context) const {
    return std::format_to(context.out(),
    R"({{ "x": {}, "y": {}, "z": {}, "w": {} }})"
    , obj.x, obj.y, obj.z, obj.w);
  }
};

#endif
