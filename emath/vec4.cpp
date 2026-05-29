#include "vec4.hpp"
#include "free_func.hpp"

#include <cmath>

namespace emath {

vec4::vec4() : x(0), y(0), z(0), w(0) {}
vec4::vec4(float a) : x(a), y(a), z(a), w(a) {}
vec4::vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

auto vec4::operator+=(const vec4& other) -> vec4& {
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
}

auto vec4::operator-=(const vec4& other) -> vec4& {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
    return *this;
}

auto vec4::operator*=(float a) -> vec4& {
    x *= a;
    y *= a;
    z *= a;
    w *= a;
    return *this;
}

auto vec4::operator+(const vec4& other) const -> vec4
{
    return vec4(x + other.x, y + other.y, z + other.z,  w + other.w);
    vec4 result = *this;
    result += other;
    return result;
}

auto vec4::operator-(const vec4& other) const -> vec4
{
    vec4 result = *this;
    result -= other;
    return result;
}

auto vec4::operator*(const vec4& other) const -> float
{
    return x * other.x + y * other.y + z * other.z + z * other.z;
}

auto vec4::operator*(float a) const -> vec4
{
    vec4 result = *this;
    result *= a;
    return result;
}

auto vec4::operator-() const -> vec4
{
    vec4 result = *this;
    result *= -1;
    return result;
}


auto vec4::magnitude() const -> float
{
    return std::sqrt(x*x + y*y + z*z + w*w);
}

auto vec4::normalize(const vec4 &v) -> vec4
{
    auto l = v.magnitude();
    if(l > 0) return v * (1.0f/l);
    else return v;
}

auto vec4::is_normalized() const -> bool
{
    return magnitude() == 1.0f;
}

auto vec4::component_product(const vec4 &other) const -> vec4
{
    return vec4(x * other.x, y * other.y, z * other.z, w * other.w);
}

auto vec4::dot(const vec4 &l, const vec4 &r) -> float
{
    return l * r;
}

auto vec4::angle(const vec4& l, const vec4& r, bool rad) -> float
{
    // angle = acos( (dot(l,r)) / (magnitude(l) * magnitude(r)) )

    auto lxr_mag = l.magnitude() * r.magnitude();
    float result = 0.0f;

    if(lxr_mag > 0.0f) result = std::acos( dot(l,r) / lxr_mag);
    if(!rad) result = to_deg(result);
    return result;
}

auto vec4::length() -> int
{
    return 4;
}

} // namespace emath