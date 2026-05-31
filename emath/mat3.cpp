#include "mat3.hpp"
#include "mat4.hpp"

#include <cmath>
#include <cassert>

namespace emath {

mat3::mat3()
: data{
    {1,0,0}, 
    {0,1,0}, 
    {0,0,1}
} {}

mat3::mat3(float m00, float m01, float m02,
     float m10, float m11, float m12,
     float m20, float m21, float m22)
: data{
    {m00,m10,m20},
    {m01,m11,m21}, 
    {m02,m12,m22}
} {}

mat3::mat3(float diag)
: data{
    {diag,0,0}, 
    {0,diag,0}, 
    {0,0,diag}
} {}

mat3::mat3(const mat4& m)
: data {
    {m[0].x, m[0].y, m[0].z},
    {m[1].x, m[1].y, m[1].z},
    {m[2].x, m[2].y, m[2].z}
} {}

auto mat3::operator+(const mat3& m) const -> mat3
{
    mat3 r;
    for(int i=0;i<3;++i) for(int j=0;j<3;++j)
        r[i][j] = data[i][j] + m[i][j];
    return r;
}
auto mat3::operator-(const mat3& m) const -> mat3
{
    mat3 r;
    for(int i=0;i<3;++i) for(int j=0;j<3;++j)
        r[i][j] = data[i][j] - m[i][j];
    return r;
}
auto mat3::operator*(float s) const -> mat3
{
    mat3 r;
    for(int i=0;i<3;++i) for(int j=0;j<3;++j)
        r[i][j] = data[i][j] * s;
    return r;
}

auto operator*(float s, const mat3& m) -> mat3
{
    return m * s;
}

auto mat3::operator*(const mat3& m) const -> mat3
{
    mat3 r(0.f);
    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j)
            for(int k=0;k<3;++k)
                r[i][j] += data[i][k] * m[k][j];
    return r;
}

auto mat3::determinant() const -> float
{
    const mat3& m = *this;
    return m[0][0]*(m[1][1]*m[2][2]-m[2][1]*m[1][2])
         - m[0][1]*(m[1][0]*m[2][2]-m[2][0]*m[1][2])
         + m[0][2]*(m[1][0]*m[2][1]-m[2][0]*m[1][1]);
}
auto mat3::inverse() const -> mat3
{
    float d = determinant();
    assert(d != 0.f && "mat3::inv: singular matrix");
    float invd = 1.f / d;
    const mat3& m = *this;
    mat3 r;
    r[0][0] = (m[1][1]*m[2][2] - m[2][1]*m[1][2]) * invd;
    r[0][1] = (m[0][2]*m[2][1] - m[0][1]*m[2][2]) * invd;
    r[0][2] = (m[0][1]*m[1][2] - m[0][2]*m[1][1]) * invd;
    r[1][0] = (m[1][2]*m[2][0] - m[1][0]*m[2][2]) * invd;
    r[1][1] = (m[0][0]*m[2][2] - m[0][2]*m[2][0]) * invd;
    r[1][2] = (m[0][2]*m[1][0] - m[0][0]*m[1][2]) * invd;
    r[2][0] = (m[1][0]*m[2][1] - m[2][0]*m[1][1]) * invd;
    r[2][1] = (m[0][1]*m[2][0] - m[0][0]*m[2][1]) * invd;
    r[2][2] = (m[0][0]*m[1][1] - m[0][1]*m[1][0]) * invd;
    return r;
}
auto mat3::transpose() const -> mat3
{
    mat3 r;
    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j)
            r[i][j] = data[i][j];
    return r;
}

auto mat3::operator[](size_t i) -> vec3 &
{
    return data[i];
}

auto mat3::operator[](size_t i) const -> const vec3 &
{
    return data[i];
}

}