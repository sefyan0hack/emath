#include "uvec2.hpp"
#include "free_func.hpp"

#include <cmath>

namespace emath {

uvec2::uvec2() : x(0), y(0) {}
uvec2::uvec2(unsigned int a) : x(a), y(a) {}
uvec2::uvec2(unsigned int x, unsigned int y) : x(x), y(y) {}

auto uvec2::operator+=(const uvec2& other) -> uvec2& {
    x += other.x;
    y += other.y;
    return *this;
}

auto uvec2::operator-=(const uvec2& other) -> uvec2& {
    x -= other.x;
    y -= other.y;
    return *this;
}

auto uvec2::operator*=(const uvec2& other) -> uvec2&
{
    x *= other.x;
    y *= other.y;
    return *this;
}

auto uvec2::operator*=(unsigned int a) -> uvec2& {
    x *= a;
    y *= a;
    return *this;
}

auto uvec2::operator+(const uvec2& other) const -> uvec2
{
    return uvec2(x + other.x, y + other.y);
    uvec2 result = *this;
    result += other;
    return result;
}

auto uvec2::operator-(const uvec2& other) const -> uvec2
{
     uvec2 result = *this;
    result -= other;
    return result;
}

auto uvec2::operator*(const uvec2& other) const -> uvec2
{
    uvec2 result = *this;
    result *= other;
    return result;
}


auto uvec2::operator*(unsigned int a) const -> uvec2
{
    uvec2 result = *this;
    result *= a;
    return result;
}

auto uvec2::operator-() const -> uvec2
{
    uvec2 result = *this;
    result *= -1;
    return result;
}


auto uvec2::magnitude() const -> float
{
    return std::hypot(x, y);
}

auto uvec2::normalize(const uvec2 &v) -> uvec2
{
    auto l = v.magnitude();
    if(l > 0) return v * (1.0f/l);
    else return v;
}

auto uvec2::is_normalized() const -> bool
{
    return magnitude() == 1.0f;
}


auto uvec2::dot(const uvec2 &l, const uvec2 &r) -> unsigned int
{
    return l.x * r.x + l.y * r.y;
}

auto uvec2::angle(const uvec2& l, const uvec2& r, bool rad) -> float
{
    // angle = acos( (dot(l,r)) / (magnitude(l) * magnitude(r)) )

    auto lxr_mag = l.magnitude() * r.magnitude();
    float result = 0.0f;

    if(lxr_mag > 0.0f) result = std::acos( dot(l,r) / lxr_mag);
    if(!rad) result = to_deg(result);
    return result;
}

auto uvec2::length() -> int
{
    return 2;
}

auto uvec2::operator[](size_t i) -> unsigned int &
{
    return (&x)[i];
}

auto uvec2::operator[](size_t i) const -> const unsigned int &
{
    return (&x)[i];
}

} // namespace emath