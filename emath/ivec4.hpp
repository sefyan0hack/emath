#pragma once

#include <cstddef>
#include <format>

namespace emath {

struct ivec4
{
    ivec4();
    ivec4(int a);
    ivec4(int x, int y, int z, int w);

    auto operator+=(const ivec4& other) -> ivec4&;
    auto operator-=(const ivec4& other) -> ivec4&;
    auto operator*=(const ivec4& other) -> ivec4&;

    auto operator*=(int a) -> ivec4&;

    auto operator+(const ivec4& other) const -> ivec4;
    auto operator-(const ivec4& other) const -> ivec4;

    auto operator*(const ivec4& other) const -> ivec4;
    auto operator*(int a) const -> ivec4;
    auto operator-() const -> ivec4;

    auto operator[](size_t i) -> int&;
    auto operator[](size_t i) const -> const int&;

    auto operator<=>(const ivec4&) const = default;

    auto magnitude() const -> float;

    auto is_normalized() const -> bool;

    static auto length() -> int;
    static auto normalize(const ivec4& v) -> ivec4;
    static auto dot(const ivec4& l, const ivec4& r) -> int;
    static auto angle(const ivec4& l, const ivec4& r, bool rad = true) -> float;

    int x, y, z, w;
};

} // namespace emath

#ifdef __cpp_lib_formatters

template<>
struct std::formatter<emath::ivec4> {
  constexpr auto parse(std::format_parse_context& context) {
    return context.begin();
  }
  auto format(const emath::ivec4& obj, auto& context) const {
    return std::format_to(context.out(),
    R"({{ "x": {}, "y": {}, "z": {}, "w": {} }})"
    , obj.x, obj.y, obj.z, obj.w);
  }
};

#endif
