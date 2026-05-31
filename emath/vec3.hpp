#pragma once

#include <cstddef>
#include <format>

namespace emath {

struct vec3
{
    vec3();
    vec3(float a);
    vec3(float x, float y, float z);

    auto operator+=(const vec3& other) -> vec3&;
    auto operator-=(const vec3& other) -> vec3&;
    auto operator*=(const vec3& other) -> vec3&;

    auto operator*=(float a) -> vec3&;

    auto operator+(const vec3& other) const -> vec3;
    auto operator-(const vec3& other) const -> vec3;

    auto operator*(const vec3& other) const -> vec3;
    auto operator*(float a) const -> vec3;
    auto operator-() const -> vec3;

    auto operator[](size_t i) -> float&;
    auto operator[](size_t i) const -> const float&;

    auto operator<=>(const vec3&) const = default;

    auto magnitude() const -> float;

    auto is_normalized() const -> bool;
    auto is_parallel_to(const vec3& other) const -> bool;

    static auto length() -> int;
    static auto normalize(const vec3& v) -> vec3;
    static auto dot(const vec3& l, const vec3& r) -> float;
    static auto cross(const vec3& l, const vec3& r) -> vec3;
    static auto is_parallel(const vec3& l, const vec3& r) -> bool;
    static auto angle(const vec3& l, const vec3& r, bool rad = true) -> float;

    float x, y, z;
};

#ifdef __cpp_lib_formatters

template<>
struct std::formatter<vec3> {
  constexpr auto parse(std::format_parse_context& context) {
    return context.begin();
  }
  auto format(const vec3& obj, auto& context) const {
    return std::format_to(context.out(),
    R"({{ "x": {}, "y": {}, "z": {} }})"
    , obj.x, obj.y, obj.z);
  }
};

#endif

} // namespace emath