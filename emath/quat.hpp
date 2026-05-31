#pragma once

#include <cstddef>
#include <format>

namespace emath {

struct quat {
    float w;
    float x;
    float y;
    float z;

    quat();
    quat(float w, float x, float y, float z);
    quat(struct vec3 eulerAngle);

    auto length() const -> float;
    auto magnitude() const -> float;
    auto normalized() const -> quat;
    auto conjugate() const -> quat;
    auto inverse() const -> quat;

    friend auto operator+(const quat& a, const quat& b) -> quat;
    friend auto operator-(const quat& a, const quat& b) -> quat;
    friend auto operator*(const quat& q, float s) -> quat;
    friend auto operator*(float s, const quat& q) -> quat;
    friend auto operator*(const quat& a, const quat& b) -> quat;

    auto operator[](size_t i) -> float&;
    auto operator[](size_t i) const -> const float&;

    auto operator<=>(const quat&) const = default;
};

auto angle_axis(float angle, struct vec3 axis) -> quat;
auto rotate(const quat& q, struct vec3 v) -> struct vec3;

}

#ifdef __cpp_lib_formatters

template<>
struct std::formatter<emath::quat> {
  constexpr auto parse(std::format_parse_context& context) {
    return context.begin();
  }
  auto format(const emath::quat& obj, auto& context) const {
    return std::format_to(context.out(),
    R"({{ "w": {}, "y": {}, "z": {}, "x": {} }})"
    , obj.w, obj.y, obj.z, obj.x);
  }
};

#endif
