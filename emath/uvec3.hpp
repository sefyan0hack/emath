#pragma once
#include <cstddef>
#include <format>

namespace emath {

struct uvec3
{
    uvec3();
    uvec3(unsigned int a);
    uvec3(unsigned int x, unsigned int y, unsigned int z);

    auto operator+=(const uvec3& other) -> uvec3&;
    auto operator-=(const uvec3& other) -> uvec3&;
    auto operator*=(const uvec3& other) -> uvec3&;

    auto operator*=(unsigned int a) -> uvec3&;

    auto operator+(const uvec3& other) const -> uvec3;
    auto operator-(const uvec3& other) const -> uvec3;

    auto operator*(const uvec3& other) const -> uvec3;
    auto operator*(unsigned int a) const -> uvec3;
    auto operator-() const -> uvec3;

    auto operator[](size_t i) -> unsigned int&;
    auto operator[](size_t i) const -> const unsigned int&;

    auto operator<=>(const uvec3&) const = default;

    auto magnitude() const -> float;

    auto is_normalized() const -> bool;

    static auto length() -> int;
    static auto normalize(const uvec3& v) -> uvec3;
    static auto dot(const uvec3& l, const uvec3& r) -> unsigned int;
    static auto angle(const uvec3& l, const uvec3& r, bool rad = true) -> float;

    unsigned int x, y, z;
};

} // namespace emath

#ifdef __cpp_lib_formatters

template<>
struct std::formatter<emath::uvec3> {
  constexpr auto parse(std::format_parse_context& context) {
    return context.begin();
  }
  auto format(const emath::uvec3& obj, auto& context) const {
    return std::format_to(context.out(),
    R"({{ "x": {}, "y": {}, "z": {} }})"
    , obj.x, obj.y, obj.z);
  }
};

#endif
