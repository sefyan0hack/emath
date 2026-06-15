#pragma once

#include <cstddef>
#include <format>

namespace emath {

struct uvec4
{
    uvec4();
    uvec4(unsigned int a);
    uvec4(unsigned int x, unsigned int y, unsigned int z, unsigned int w);

    auto operator+=(const uvec4& other) -> uvec4&;
    auto operator-=(const uvec4& other) -> uvec4&;
    auto operator*=(const uvec4& other) -> uvec4&;

    auto operator*=(unsigned int a) -> uvec4&;

    auto operator+(const uvec4& other) const -> uvec4;
    auto operator-(const uvec4& other) const -> uvec4;

    auto operator*(const uvec4& other) const -> uvec4;
    auto operator*(unsigned int a) const -> uvec4;
    auto operator-() const -> uvec4;

    auto operator[](size_t i) -> unsigned int&;
    auto operator[](size_t i) const -> const unsigned int&;

    auto operator<=>(const uvec4&) const = default;

    auto magnitude() const -> float;

    auto is_normalized() const -> bool;

    static auto length() -> int;
    static auto normalize(const uvec4& v) -> uvec4;
    static auto dot(const uvec4& l, const uvec4& r) -> unsigned int;
    static auto angle(const uvec4& l, const uvec4& r, bool rad = true) -> float;

    unsigned int x, y, z, w;
};

} // namespace emath

#ifdef __cpp_lib_formatters

template<>
struct std::formatter<emath::uvec4> {
  constexpr auto parse(std::format_parse_context& context) {
    return context.begin();
  }
  auto format(const emath::uvec4& obj, auto& context) const {
    return std::format_to(context.out(),
    R"({{ "x": {}, "y": {}, "z": {}, "w": {} }})"
    , obj.x, obj.y, obj.z, obj.w);
  }
};

#endif
