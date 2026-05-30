#include "vec2.hpp"
#include "free_func.hpp"

#include <cmath>

namespace emath {

vec2::vec2() : x(0), y(0) {}
vec2::vec2(float a) : x(a), y(a) {}
vec2::vec2(float x, float y) : x(x), y(y) {}

auto vec2::operator+=(const vec2& other) -> vec2& {
    x += other.x;
    y += other.y;
    return *this;
}

auto vec2::operator-=(const vec2& other) -> vec2& {
    x -= other.x;
    y -= other.y;
    return *this;
}

auto vec2::operator*=(const vec2& other) -> vec2&
{
    x *= other.x;
    y *= other.y;
    return *this;
}

auto vec2::operator*=(float a) -> vec2& {
    x *= a;
    y *= a;
    return *this;
}

auto vec2::operator+(const vec2& other) const -> vec2
{
    return vec2(x + other.x, y + other.y);
    vec2 result = *this;
    result += other;
    return result;
}

auto vec2::operator-(const vec2& other) const -> vec2
{
     vec2 result = *this;
    result -= other;
    return result;
}

auto vec2::operator*(const vec2& other) const -> vec2
{
    vec2 result = *this;
    result *= other;
    return result;
}


auto vec2::operator*(float a) const -> vec2
{
    vec2 result = *this;
    result *= a;
    return result;
}

auto vec2::operator-() const -> vec2
{
    vec2 result = *this;
    result *= -1;
    return result;
}


auto vec2::magnitude() const -> float
{
    return std::hypot(x, y);
}

auto vec2::normalize(const vec2 &v) -> vec2
{
    auto l = v.magnitude();
    if(l > 0) return v * (1.0f/l);
    else return v;
}

auto vec2::is_normalized() const -> bool
{
    return magnitude() == 1.0f;
}

auto vec2::dot(const vec2 &l, const vec2 &r) -> float
{
    return  l.x * r.x + l.y * r.y;
}

auto vec2::angle(const vec2& l, const vec2& r, bool rad) -> float
{
    // angle = acos( (dot(l,r)) / (magnitude(l) * magnitude(r)) )

    auto lxr_mag = l.magnitude() * r.magnitude();
    float result = 0.0f;

    if(lxr_mag > 0.0f) result = std::acos( dot(l,r) / lxr_mag);
    if(!rad) result = to_deg(result);
    return result;
}

auto vec2::length() -> int
{
    return 2;
}

auto vec2::operator[](size_t i) -> float &
{
    return (&x)[i];
}

auto vec2::operator[](size_t i) const -> const float &
{
    return (&x)[i];
}

} // namespace emath