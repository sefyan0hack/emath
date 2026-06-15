#pragma once
#include <cstddef>
#include <format>

namespace emath {

struct uvec2
{
    uvec2();
    uvec2(unsigned int a);
    uvec2(unsigned int x, unsigned int y);

    auto operator+=(const uvec2& other) -> uvec2&;
    auto operator-=(const uvec2& other) -> uvec2&;
    auto operator*=(const uvec2& other) -> uvec2&;

    auto operator*=(unsigned int a) -> uvec2&;

    auto operator+(const uvec2& other) const -> uvec2;
    auto operator-(const uvec2& other) const -> uvec2;

    auto operator*(const uvec2& other) const -> uvec2;
    auto operator*(unsigned int a) const -> uvec2;
    auto operator-() const -> uvec2;

    auto operator[](size_t i) -> unsigned int&;
    auto operator[](size_t i) const -> const unsigned int&;

    auto operator<=>(const uvec2&) const = default;

    auto magnitude() const -> float;

    auto is_normalized() const -> bool;

    static auto length() -> int;
    static auto normalize(const uvec2& v) -> uvec2;
    static auto dot(const uvec2& l, const uvec2& r) -> unsigned int;
    static auto angle(const uvec2& l, const uvec2& r, bool rad = true) -> float;

    unsigned int x, y;
};

} // namespace emath

#ifdef __cpp_lib_formatters

template<>
struct std::formatter<emath::uvec2> {
  constexpr auto parse(std::format_parse_context& context) {
    return context.begin();
  }
  auto format(const emath::uvec2& obj, auto& context) const {
    return std::format_to(context.out(),
    R"({{ "x": {}, "y": {} }})"
    , obj.x, obj.y);
  }
};

#endif