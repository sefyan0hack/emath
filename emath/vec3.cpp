#include "vec3.hpp"
#include "free_func.hpp"

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


auto vec3::magnitude() const -> float
{
    return std::hypot(x, y, z);
}

auto vec3::normalize(const vec3 &v) -> vec3
{
    auto l = v.magnitude();
    if(l > 0) return v * (1.0f/l);
    else return v;
}

auto vec3::is_normalized() const -> bool
{
    return magnitude() == 1.0f;
}

auto vec3::is_parallel_to(const vec3 &other) const -> bool
{
    return is_parallel(*this, other);
}

auto vec3::component_product(const vec3 &other) const -> vec3
{
    return vec3(x * other.x, y * other.y, z * other.z);
}

auto vec3::dot(const vec3 &l, const vec3 &r) -> float
{
    return l * r;
}

auto vec3::cross(const vec3& l, const vec3& r) -> vec3
{
    //note: | a × b != −b × a | but | a × b == −b × a |
    return vec3(
        l.y * r.z - l.z * r.y,
        l.z * r.x - l.x * r.z,
        l.x * r.y - l.y * r.x
    );
}
auto vec3::angle(const vec3& l, const vec3& r, bool rad) -> float
{
    // angle = acos( (dot(l,r)) / (magnitude(l) * magnitude(r)) )

    auto lxr_mag = l.magnitude() * r.magnitude();
    float result = 0.0f;

    if(lxr_mag > 0.0f) result = std::acos( dot(l,r) / lxr_mag);
    if(!rad) result = to_deg(result);
    return result;
}

auto vec3::is_parallel(const vec3 &l, const vec3 &r) -> bool
{
    return cross(l, r).magnitude() == 0;
}

auto vec3::length() -> int
{
    return 3;
}

} // namespace emath