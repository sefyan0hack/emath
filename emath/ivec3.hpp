#pragma once
#include <cstddef>

namespace emath {

struct ivec3
{
    ivec3();
    ivec3(int a);
    ivec3(int x, int y, int z);

    auto operator+=(const ivec3& other) -> ivec3&;
    auto operator-=(const ivec3& other) -> ivec3&;
    auto operator*=(const ivec3& other) -> ivec3&;

    auto operator*=(int a) -> ivec3&;

    auto operator+(const ivec3& other) const -> ivec3;
    auto operator-(const ivec3& other) const -> ivec3;

    auto operator*(const ivec3& other) const -> ivec3;
    auto operator*(int a) const -> ivec3;
    auto operator-() const -> ivec3;

    auto operator[](size_t i) -> int&;
    auto operator[](size_t i) const -> const int&;

    auto operator<=>(const ivec3&) const = default;

    auto magnitude() const -> float;

    auto is_normalized() const -> bool;

    static auto length() -> int;
    static auto normalize(const ivec3& v) -> ivec3;
    static auto dot(const ivec3& l, const ivec3& r) -> int;
    static auto angle(const ivec3& l, const ivec3& r, bool rad = true) -> float;

    int x, y, z;
};

} // namespace emath