#include "ivec2.hpp"
#include "free_func.hpp"

#include <cmath>

namespace emath {

ivec2::ivec2() : x(0), y(0) {}
ivec2::ivec2(int a) : x(a), y(a) {}
ivec2::ivec2(int x, int y) : x(x), y(y) {}

auto ivec2::operator+=(const ivec2& other) -> ivec2& {
    x += other.x;
    y += other.y;
    return *this;
}

auto ivec2::operator-=(const ivec2& other) -> ivec2& {
    x -= other.x;
    y -= other.y;
    return *this;
}

auto ivec2::operator*=(const ivec2& other) -> ivec2&
{
    x *= other.x;
    y *= other.y;
    return *this;
}

auto ivec2::operator*=(int a) -> ivec2& {
    x *= a;
    y *= a;
    return *this;
}

auto ivec2::operator+(const ivec2& other) const -> ivec2
{
    return ivec2(x + other.x, y + other.y);
    ivec2 result = *this;
    result += other;
    return result;
}

auto ivec2::operator-(const ivec2& other) const -> ivec2
{
     ivec2 result = *this;
    result -= other;
    return result;
}

auto ivec2::operator*(const ivec2& other) const -> ivec2
{
    ivec2 result = *this;
    result *= other;
    return result;
}


auto ivec2::operator*(int a) const -> ivec2
{
    ivec2 result = *this;
    result *= a;
    return result;
}

auto ivec2::operator-() const -> ivec2
{
    ivec2 result = *this;
    result *= -1;
    return result;
}


auto ivec2::magnitude() const -> float
{
    return std::hypot(x, y);
}

auto ivec2::normalize(const ivec2 &v) -> ivec2
{
    auto l = v.magnitude();
    if(l > 0) return v * (1.0f/l);
    else return v;
}

auto ivec2::is_normalized() const -> bool
{
    return magnitude() == 1.0f;
}

auto ivec2::component_product(const ivec2 &other) const -> ivec2
{
    return ivec2(x * other.x, y * other.y);
}

auto ivec2::dot(const ivec2 &l, const ivec2 &r) -> int
{
    return l * r;
}

auto ivec2::angle(const ivec2& l, const ivec2& r, bool rad) -> float
{
    // angle = acos( (dot(l,r)) / (magnitude(l) * magnitude(r)) )

    auto lxr_mag = l.magnitude() * r.magnitude();
    float result = 0.0f;

    if(lxr_mag > 0.0f) result = std::acos( dot(l,r) / lxr_mag);
    if(!rad) result = to_deg(result);
    return result;
}

auto ivec2::length() -> int
{
    return 2;
}

} // namespace emath