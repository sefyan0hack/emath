#include "ivec3.hpp"
#include "free_func.hpp"

#include <cmath>

namespace emath {

ivec3::ivec3() : x(0), y(0), z(0) {}
ivec3::ivec3(int a) : x(a), y(a), z(a) {}
ivec3::ivec3(int x, int y, int z) : x(x), y(y), z(z) {}

auto ivec3::operator+=(const ivec3& other) -> ivec3& {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

auto ivec3::operator-=(const ivec3& other) -> ivec3& {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

auto ivec3::operator*=(const ivec3& other) -> ivec3&
{
    x *= other.x;
    y *= other.y;
    z *= other.z;
    return *this;
}

auto ivec3::operator*=(int a) -> ivec3& {
    x *= a;
    y *= a;
    z *= a;
    return *this;
}

auto ivec3::operator+(const ivec3& other) const -> ivec3
{
    return ivec3(x + other.x, y + other.y, z + other.z);
    ivec3 result = *this;
    result += other;
    return result;
}

auto ivec3::operator-(const ivec3& other) const -> ivec3
{
     ivec3 result = *this;
    result -= other;
    return result;
}

auto ivec3::operator*(const ivec3& other) const -> ivec3
{
    ivec3 result = *this;
    result *= other;
    return result;
}


auto ivec3::operator*(int a) const -> ivec3
{
    ivec3 result = *this;
    result *= a;
    return result;
}

auto ivec3::operator-() const -> ivec3
{
    ivec3 result = *this;
    result *= -1;
    return result;
}


auto ivec3::magnitude() const -> float
{
    return std::hypot(x, y, z);
}

auto ivec3::normalize(const ivec3 &v) -> ivec3
{
    auto l = v.magnitude();
    if(l > 0) return v * (1.0f/l);
    else return v;
}

auto ivec3::is_normalized() const -> bool
{
    return magnitude() == 1.0f;
}

auto ivec3::dot(const ivec3 &l, const ivec3 &r) -> int
{
    return l.x * r.x + l.y * r.y + l.z * r.z;
}

auto ivec3::angle(const ivec3& l, const ivec3& r, bool rad) -> float
{
    // angle = acos( (dot(l,r)) / (magnitude(l) * magnitude(r)) )

    auto lxr_mag = l.magnitude() * r.magnitude();
    float result = 0.0f;

    if(lxr_mag > 0.0f) result = std::acos( dot(l,r) / lxr_mag);
    if(!rad) result = to_deg(result);
    return result;
}

auto ivec3::length() -> int
{
    return 3;
}

auto ivec3::operator[](size_t i) -> int &
{
    return (&x)[i];
}

auto ivec3::operator[](size_t i) const -> const int &
{
    return (&x)[i];
}

} // namespace emath