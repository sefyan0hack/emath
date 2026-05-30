#include "mat2.hpp"

#include <cmath>
#include <cassert>

namespace emath {

mat2::mat2()
: data{
    {1,0},
    {0,1}
} {}

mat2::mat2(float m00, float m01, float m10, float m11)
: data{
    {m00, m10},
    {m01, m11}
} {}

mat2::mat2(float diag)
: data{
    {diag,0},
    {0,diag}
} {}

auto mat2::operator+(const mat2& m) const -> mat2
{
    return mat2(
        data[0][0]+m[0][0], data[0][1]+m[0][1],
        data[1][0]+m[1][0], data[1][1]+m[1][1]
    );
}
auto mat2::operator-(const mat2& m) const -> mat2
{
    return mat2(
        data[0][0]-m[0][0], data[0][1]-m[0][1],
        data[1][0]-m[1][0], data[1][1]-m[1][1]
    );
}

auto mat2::operator*(float s) const -> mat2
{
    return mat2(
        data[0][0]*s, data[0][1]*s,
        data[1][0]*s, data[1][1]*s
    );
}

auto operator*(float s, const mat2& m) -> mat2
{
    return m * s;
}

// matrix multiplication
auto mat2::operator*(const mat2& m) const -> mat2
{
    mat2 r(0.f);
    for(int i=0;i<2;++i)
        for(int j=0;j<2;++j)
            for(int k=0;k<2;++k)
                r[i][j] += data[i][k] * m[i][k];
    return r;
}

auto mat2::determinant() const -> float
{
    return data[0][0] * data[1][1] - data[1][0] * data[0][1];
}

auto mat2::inverse() const -> mat2 {
    float d = determinant();
    assert(d != 0.f && "mat2::inv: singular matrix");
    float invd = 1.f / d;
    return mat2(
         data[1][1] * invd, -data[0][1] * invd,
        -data[1][0] * invd,  data[0][0] * invd
    );
}

auto mat2::transpose() const -> mat2
{
    return mat2(
        data[0][0], data[1][0],
        data[0][1], data[1][1]
    );
}

auto mat2::operator[](std::size_t i) -> vec2&
{
    return data[i];
}

auto mat2::operator[](std::size_t i) const -> const vec2&
{
    return data[i];
}

}