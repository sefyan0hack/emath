#include "uvec4.hpp"
#include "free_func.hpp"

#include <cmath>

namespace emath {

uvec4::uvec4() : x(0), y(0), z(0), w(0) {}
uvec4::uvec4(unsigned int a) : x(a), y(a), z(a), w(a) {}
uvec4::uvec4(unsigned int x, unsigned int y, unsigned int z, unsigned int w) : x(x), y(y), z(z), w(w) {}

auto uvec4::operator+=(const uvec4& other) -> uvec4& {
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
}

auto uvec4::operator-=(const uvec4& other) -> uvec4& {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
    return *this;
}

auto uvec4::operator*=(const uvec4& other) -> uvec4&
{
    x *= other.x;
    y *= other.y;
    z *= other.z;
    w *= other.w;
    return *this;
}

auto uvec4::operator*=(unsigned int a) -> uvec4& {
    x *= a;
    y *= a;
    z *= a;
    w *= a;
    return *this;
}

auto uvec4::operator+(const uvec4& other) const -> uvec4
{
    return uvec4(x + other.x, y + other.y, z + other.z,  w + other.w);
    uvec4 result = *this;
    result += other;
    return result;
}

auto uvec4::operator-(const uvec4& other) const -> uvec4
{
    uvec4 result = *this;
    result -= other;
    return result;
}

auto uvec4::operator*(const uvec4& other) const -> uvec4
{
    uvec4 result = *this;
    result *= other;
    return result;
}

auto uvec4::operator*(unsigned int a) const -> uvec4
{
    uvec4 result = *this;
    result *= a;
    return result;
}

auto uvec4::operator-() const -> uvec4
{
    uvec4 result = *this;
    result *= -1;
    return result;
}

auto uvec4::magnitude() const -> float
{
    return std::sqrt(x*x + y*y + z*z + w*w);
}

auto uvec4::normalize(const uvec4 &v) -> uvec4
{
    auto l = v.magnitude();
    if(l > 0) return v * (1.0f/l);
    else return v;
}

auto uvec4::is_normalized() const -> bool
{
    return magnitude() == 1.0f;
}

auto uvec4::dot(const uvec4 &l, const uvec4 &r) -> unsigned int
{
    return l.x * r.x + l.y * r.y + l.z * r.z + l.w * r.w;
}

auto uvec4::angle(const uvec4& l, const uvec4& r, bool rad) -> float
{
    // angle = acos( (dot(l,r)) / (magnitude(l) * magnitude(r)) )

    auto lxr_mag = l.magnitude() * r.magnitude();
    float result = 0.0f;

    if(lxr_mag > 0.0f) result = std::acos( dot(l,r) / lxr_mag);
    if(!rad) result = to_deg(result);
    return result;
}

auto uvec4::length() -> int
{
    return 4;
}

auto uvec4::operator[](size_t i) -> unsigned int &
{
    return (&x)[i];
}

auto uvec4::operator[](size_t i) const -> const unsigned int &
{
    return (&x)[i];
}

} // namespace emath