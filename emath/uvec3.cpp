#include "uvec3.hpp"
#include "free_func.hpp"

#include <cmath>

namespace emath {

uvec3::uvec3() : x(0), y(0), z(0) {}
uvec3::uvec3(unsigned int a) : x(a), y(a), z(a) {}
uvec3::uvec3(unsigned int x, unsigned int y, unsigned int z) : x(x), y(y), z(z) {}

auto uvec3::operator+=(const uvec3& other) -> uvec3& {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

auto uvec3::operator-=(const uvec3& other) -> uvec3& {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

auto uvec3::operator*=(const uvec3& other) -> uvec3&
{
    x *= other.x;
    y *= other.y;
    z *= other.z;
    return *this;
}

auto uvec3::operator*=(unsigned int a) -> uvec3& {
    x *= a;
    y *= a;
    z *= a;
    return *this;
}

auto uvec3::operator+(const uvec3& other) const -> uvec3
{
    return uvec3(x + other.x, y + other.y, z + other.z);
    uvec3 result = *this;
    result += other;
    return result;
}

auto uvec3::operator-(const uvec3& other) const -> uvec3
{
     uvec3 result = *this;
    result -= other;
    return result;
}

auto uvec3::operator*(const uvec3& other) const -> uvec3
{
    uvec3 result = *this;
    result *= other;
    return result;
}


auto uvec3::operator*(unsigned int a) const -> uvec3
{
    uvec3 result = *this;
    result *= a;
    return result;
}

auto uvec3::operator-() const -> uvec3
{
    uvec3 result = *this;
    result *= -1;
    return result;
}


auto uvec3::magnitude() const -> float
{
    return std::hypot(x, y, z);
}

auto uvec3::normalize(const uvec3 &v) -> uvec3
{
    auto l = v.magnitude();
    if(l > 0) return v * (1.0f/l);
    else return v;
}

auto uvec3::is_normalized() const -> bool
{
    return magnitude() == 1.0f;
}

auto uvec3::dot(const uvec3 &l, const uvec3 &r) -> unsigned int
{
    return l.x * r.x + l.y * r.y + l.z * r.z;
}

auto uvec3::angle(const uvec3& l, const uvec3& r, bool rad) -> float
{
    // angle = acos( (dot(l,r)) / (magnitude(l) * magnitude(r)) )

    auto lxr_mag = l.magnitude() * r.magnitude();
    float result = 0.0f;

    if(lxr_mag > 0.0f) result = std::acos( dot(l,r) / lxr_mag);
    if(!rad) result = to_deg(result);
    return result;
}

auto uvec3::length() -> int
{
    return 3;
}

auto uvec3::operator[](size_t i) -> unsigned int &
{
    return (&x)[i];
}

auto uvec3::operator[](size_t i) const -> const unsigned int &
{
    return (&x)[i];
}

} // namespace emath