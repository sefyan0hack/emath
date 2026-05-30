#include "ivec4.hpp"
#include "free_func.hpp"

#include <cmath>

namespace emath {

ivec4::ivec4() : x(0), y(0), z(0), w(0) {}
ivec4::ivec4(int a) : x(a), y(a), z(a), w(a) {}
ivec4::ivec4(int x, int y, int z, int w) : x(x), y(y), z(z), w(w) {}

auto ivec4::operator+=(const ivec4& other) -> ivec4& {
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
}

auto ivec4::operator-=(const ivec4& other) -> ivec4& {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
    return *this;
}

auto ivec4::operator*=(const ivec4& other) -> ivec4&
{
    x *= other.x;
    y *= other.y;
    z *= other.z;
    w *= other.w;
    return *this;
}

auto ivec4::operator*=(int a) -> ivec4& {
    x *= a;
    y *= a;
    z *= a;
    w *= a;
    return *this;
}

auto ivec4::operator+(const ivec4& other) const -> ivec4
{
    return ivec4(x + other.x, y + other.y, z + other.z,  w + other.w);
    ivec4 result = *this;
    result += other;
    return result;
}

auto ivec4::operator-(const ivec4& other) const -> ivec4
{
    ivec4 result = *this;
    result -= other;
    return result;
}

auto ivec4::operator*(const ivec4& other) const -> ivec4
{
    ivec4 result = *this;
    result *= other;
    return result;
}

auto ivec4::operator*(int a) const -> ivec4
{
    ivec4 result = *this;
    result *= a;
    return result;
}

auto ivec4::operator-() const -> ivec4
{
    ivec4 result = *this;
    result *= -1;
    return result;
}

auto ivec4::magnitude() const -> float
{
    return std::sqrt(x*x + y*y + z*z + w*w);
}

auto ivec4::normalize(const ivec4 &v) -> ivec4
{
    auto l = v.magnitude();
    if(l > 0) return v * (1.0f/l);
    else return v;
}

auto ivec4::is_normalized() const -> bool
{
    return magnitude() == 1.0f;
}

auto ivec4::dot(const ivec4 &l, const ivec4 &r) -> int
{
    return l.x * r.x + l.y * r.y + l.z * r.z + l.w * r.w;
}

auto ivec4::angle(const ivec4& l, const ivec4& r, bool rad) -> float
{
    // angle = acos( (dot(l,r)) / (magnitude(l) * magnitude(r)) )

    auto lxr_mag = l.magnitude() * r.magnitude();
    float result = 0.0f;

    if(lxr_mag > 0.0f) result = std::acos( dot(l,r) / lxr_mag);
    if(!rad) result = to_deg(result);
    return result;
}

auto ivec4::length() -> int
{
    return 4;
}

auto ivec4::operator[](size_t i) -> int &
{
    return (&x)[i];
}

auto ivec4::operator[](size_t i) const -> const int &
{
    return (&x)[i];
}

} // namespace emath