#include "vec3.hpp"

#include <cmath>
namespace emath {

vec3::vec3() : x(0), y(0), z(0) {}
vec3::vec3(float a) : x(a), y(a), z(a) {}
vec3::vec3(float x, float y, float z) : x(x), y(y), z(z) {}

auto vec3::operator+=(const vec3& other) -> vec3& {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

auto vec3::operator-=(const vec3& other) -> vec3& {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

auto vec3::operator*=(float a) -> vec3& {
    x *= a;
    y *= a;
    z *= a;
    return *this;
}

auto vec3::operator+(const vec3& other) const -> vec3
{
    return vec3(x + other.x, y + other.y, z + other.z);
    vec3 result = *this;
    result += other;
    return result;
}

auto vec3::operator-(const vec3& other) const -> vec3
{
     vec3 result = *this;
    result -= other;
    return result;
}

auto vec3::operator*(const vec3& other) const -> float
{
    return x * other.x + y * other.y + z * other.z;
}

auto vec3::operator*(float a) const -> vec3
{
    vec3 result = *this;
    result *= a;
    return result;
}

auto vec3::operator-() const -> vec3
{
    vec3 result = *this;
    result *= -1;
    return result;
}

auto vec3::component_product(const vec3 &other) const -> vec3
{
    return vec3(x * other.x, y * other.y, z * other.z);
}

auto vec3::dot(const vec3 &l, const vec3 &r) -> float
{
    return l * r;
}

auto vec3::magnitude() const -> float
{
    return std::hypot(x, y, z);
}

auto vec3::normalize() -> void
{
    auto l = magnitude();
    if(l > 0) (*this) *= 1.0f/l;
}

} // namespace emath