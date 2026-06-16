#pragma once

#include <cstddef>
#include <format>

namespace emath {

struct u16vec4
{
    u16vec4();
    u16vec4(uint16_t a);
    u16vec4(uint16_t x, uint16_t y, uint16_t z, uint16_t w);

    auto operator+=(const u16vec4& other) -> u16vec4&;
    auto operator-=(const u16vec4& other) -> u16vec4&;
    auto operator*=(const u16vec4& other) -> u16vec4&;

    auto operator*=(uint16_t a) -> u16vec4&;

    auto operator+(const u16vec4& other) const -> u16vec4;
    auto operator-(const u16vec4& other) const -> u16vec4;

    auto operator*(const u16vec4& other) const -> u16vec4;
    auto operator*(uint16_t a) const -> u16vec4;
    auto operator-() const -> u16vec4;

    auto operator[](size_t i) -> uint16_t&;
    auto operator[](size_t i) const -> const uint16_t&;

    auto operator<=>(const u16vec4&) const = default;

    auto magnitude() const -> float;

    auto is_normalized() const -> bool;

    static auto length() -> int;
    static auto normalize(const u16vec4& v) -> u16vec4;
    static auto dot(const u16vec4& l, const u16vec4& r) -> uint16_t;
    static auto angle(const u16vec4& l, const u16vec4& r, bool rad = true) -> float;

    uint16_t x, y, z, w;
};

} // namespace emath

#ifdef __cpp_lib_formatters

template<>
struct std::formatter<emath::u16vec4> {
  constexpr auto parse(std::format_parse_context& context) {
    return context.begin();
  }
  auto format(const emath::u16vec4& obj, auto& context) const {
    return std::format_to(context.out(),
    R"({{ "x": {}, "y": {}, "z": {}, "w": {} }})"
    , obj.x, obj.y, obj.z, obj.w);
  }
};

#endif
