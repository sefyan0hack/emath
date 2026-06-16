#include "u16vec4.hpp"
#include "free_func.hpp"

#include <cmath>

namespace emath {

u16vec4::u16vec4() : x(0), y(0), z(0), w(0) {}
u16vec4::u16vec4(uint16_t a) : x(a), y(a), z(a), w(a) {}
u16vec4::u16vec4(uint16_t x, uint16_t y, uint16_t z, uint16_t w) : x(x), y(y), z(z), w(w) {}

auto u16vec4::operator+=(const u16vec4& other) -> u16vec4& {
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
}

auto u16vec4::operator-=(const u16vec4& other) -> u16vec4& {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
    return *this;
}

auto u16vec4::operator*=(const u16vec4& other) -> u16vec4&
{
    x *= other.x;
    y *= other.y;
    z *= other.z;
    w *= other.w;
    return *this;
}

auto u16vec4::operator*=(uint16_t a) -> u16vec4& {
    x *= a;
    y *= a;
    z *= a;
    w *= a;
    return *this;
}

auto u16vec4::operator+(const u16vec4& other) const -> u16vec4
{
    return u16vec4(x + other.x, y + other.y, z + other.z,  w + other.w);
    u16vec4 result = *this;
    result += other;
    return result;
}

auto u16vec4::operator-(const u16vec4& other) const -> u16vec4
{
    u16vec4 result = *this;
    result -= other;
    return result;
}

auto u16vec4::operator*(const u16vec4& other) const -> u16vec4
{
    u16vec4 result = *this;
    result *= other;
    return result;
}

auto u16vec4::operator*(uint16_t a) const -> u16vec4
{
    u16vec4 result = *this;
    result *= a;
    return result;
}

auto u16vec4::operator-() const -> u16vec4
{
    u16vec4 result = *this;
    result *= -1;
    return result;
}

auto u16vec4::magnitude() const -> float
{
    return std::sqrt(x*x + y*y + z*z + w*w);
}

auto u16vec4::normalize(const u16vec4 &v) -> u16vec4
{
    auto l = v.magnitude();
    if(l > 0) return v * (1.0f/l);
    else return v;
}

auto u16vec4::is_normalized() const -> bool
{
    return magnitude() == 1.0f;
}

auto u16vec4::dot(const u16vec4 &l, const u16vec4 &r) -> uint16_t
{
    return l.x * r.x + l.y * r.y + l.z * r.z + l.w * r.w;
}

auto u16vec4::angle(const u16vec4& l, const u16vec4& r, bool rad) -> float
{
    // angle = acos( (dot(l,r)) / (magnitude(l) * magnitude(r)) )

    auto lxr_mag = l.magnitude() * r.magnitude();
    float result = 0.0f;

    if(lxr_mag > 0.0f) result = std::acos( dot(l,r) / lxr_mag);
    if(!rad) result = to_deg(result);
    return result;
}

auto u16vec4::length() -> int
{
    return 4;
}

auto u16vec4::operator[](size_t i) -> uint16_t &
{
    return (&x)[i];
}

auto u16vec4::operator[](size_t i) const -> const uint16_t &
{
    return (&x)[i];
}

} // namespace emath