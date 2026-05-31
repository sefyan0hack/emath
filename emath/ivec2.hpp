#pragma once
#include <cstddef>
#include <format>

namespace emath {

struct ivec2
{
    ivec2();
    ivec2(int a);
    ivec2(int x, int y);

    auto operator+=(const ivec2& other) -> ivec2&;
    auto operator-=(const ivec2& other) -> ivec2&;
    auto operator*=(const ivec2& other) -> ivec2&;

    auto operator*=(int a) -> ivec2&;

    auto operator+(const ivec2& other) const -> ivec2;
    auto operator-(const ivec2& other) const -> ivec2;

    auto operator*(const ivec2& other) const -> ivec2;
    auto operator*(int a) const -> ivec2;
    auto operator-() const -> ivec2;

    auto operator[](size_t i) -> int&;
    auto operator[](size_t i) const -> const int&;

    auto operator<=>(const ivec2&) const = default;

    auto magnitude() const -> float;

    auto is_normalized() const -> bool;

    static auto length() -> int;
    static auto normalize(const ivec2& v) -> ivec2;
    static auto dot(const ivec2& l, const ivec2& r) -> int;
    static auto angle(const ivec2& l, const ivec2& r, bool rad = true) -> float;

    int x, y;
};

#ifdef __cpp_lib_formatters

template<>
struct std::formatter<ivec2> {
  constexpr auto parse(std::format_parse_context& context) {
    return context.begin();
  }
  auto format(const ivec2& obj, auto& context) const {
    return std::format_to(context.out(),
    R"({{ "x": {}, "y": {} }})"
    , obj.x, obj.y);
  }
};

#endif

} // namespace emath