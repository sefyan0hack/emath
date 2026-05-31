#pragma once

#include <cstddef>
#include <format>

namespace emath {

struct vec2
{
    vec2();
    vec2(float a);
    vec2(float x, float y);

    auto operator+=(const vec2& other) -> vec2&;
    auto operator-=(const vec2& other) -> vec2&;
    auto operator*=(const vec2& other) -> vec2&;

    auto operator*=(float a) -> vec2&;

    auto operator+(const vec2& other) const -> vec2;
    auto operator-(const vec2& other) const -> vec2;

    auto operator*(const vec2& other) const -> vec2;
    auto operator*(float a) const -> vec2;
    auto operator-() const -> vec2;

    auto operator[](size_t i) -> float&;
    auto operator[](size_t i) const -> const float&;

    auto operator<=>(const vec2&) const = default;

    auto magnitude() const -> float;

    auto is_normalized() const -> bool;

    static auto length() -> int;
    static auto normalize(const vec2& v) -> vec2;
    static auto dot(const vec2& l, const vec2& r) -> float;
    static auto angle(const vec2& l, const vec2& r, bool rad = true) -> float;

    float x, y;
};

} // namespace emath

#ifdef __cpp_lib_formatters

template<>
struct std::formatter<emath::vec2> {
  constexpr auto parse(std::format_parse_context& context) {
    return context.begin();
  }
  auto format(const emath::vec2& obj, auto& context) const {
    return std::format_to(context.out(),
    R"({{ "x": {}, "y": {} }})"
    , obj.x, obj.y);
  }
};

#endif
