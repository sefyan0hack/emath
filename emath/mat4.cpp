#include "mat4.hpp"

#include <cmath>
#include <cassert>

namespace emath {

mat4::mat4()
: data{
    {1,0,0,0}, 
    {0,1,0,0}, 
    {0,0,1,0}, 
    {0,0,0,1}
} {}

mat4::mat4(float m00, float m01, float m02, float m03,
     float m10, float m11, float m12, float m13,
     float m20, float m21, float m22, float m23,
     float m30, float m31, float m32, float m33)
:data{
    {m00,m10,m20,m30},
    {m01,m11,m21,m31},
    {m02,m12,m22,m32}, 
    {m03,m13,m23,m33}
} {}

mat4::mat4(float diag)
: data{
    {diag,0,0,0},
    {0,diag,0,0},
    {0,0,diag,0},
    {0,0,0,diag}
} {}

auto mat4::operator+(const mat4 &m) const -> mat4
{
    mat4 r;
    for(int i=0;i<4;++i) for(int j=0;j<4;++j)
        r[i][j] = data[i][j] + m[i][j];
    return r;
}

mat4 mat4::operator-(const mat4& m) const {
    mat4 r;
    for(int i=0;i<4;++i) for(int j=0;j<4;++j)
        r[i][j] = data[i][j] - m[i][j];
    return r;
}
mat4 mat4::operator*(float s) const {
    mat4 r;
    for(int i=0;i<4;++i) for(int j=0;j<4;++j)
        r[i][j] = data[i][j] * s;
    return r;
}
auto operator*(float s, const mat4& m) -> mat4
{
    return m * s;
}

auto mat4::operator*(const mat4& m) const -> mat4
{
    mat4 r(0.f);
    for(int i=0;i<4;++i)
        for(int j=0;j<4;++j)
            for(int k=0;k<4;++k)
                r[i][j] += data[i][k] * m[k][j];
    return r;
}
auto mat4::determinant() const -> float
{
    const mat4& m = *this;
    float s0 = m[0][0]*m[1][1] - m[1][0]*m[0][1];
    float s1 = m[0][0]*m[1][2] - m[1][0]*m[0][2];
    float s2 = m[0][0]*m[1][3] - m[1][0]*m[0][3];
    float s3 = m[0][1]*m[1][2] - m[1][1]*m[0][2];
    float s4 = m[0][1]*m[1][3] - m[1][1]*m[0][3];
    float s5 = m[0][2]*m[1][3] - m[1][2]*m[0][3];
    float c0 = m[2][0]*m[3][1] - m[3][0]*m[2][1];
    float c1 = m[2][0]*m[3][2] - m[3][0]*m[2][2];
    float c2 = m[2][0]*m[3][3] - m[3][0]*m[2][3];
    float c3 = m[2][1]*m[3][2] - m[3][1]*m[2][2];
    float c4 = m[2][1]*m[3][3] - m[3][1]*m[2][3];
    float c5 = m[2][2]*m[3][3] - m[3][2]*m[2][3];
    return s0*c5 - s1*c4 + s2*c3 + s3*c2 - s4*c1 + s5*c0;
}
auto mat4::inverse() const -> mat4
{
    const mat4& m = *this;
    // compute cofactors
    float s0 = m[0][0]*m[1][1] - m[1][0]*m[0][1];
    float s1 = m[0][0]*m[1][2] - m[1][0]*m[0][2];
    float s2 = m[0][0]*m[1][3] - m[1][0]*m[0][3];
    float s3 = m[0][1]*m[1][2] - m[1][1]*m[0][2];
    float s4 = m[0][1]*m[1][3] - m[1][1]*m[0][3];
    float s5 = m[0][2]*m[1][3] - m[1][2]*m[0][3];
    float c0 = m[2][0]*m[3][1] - m[3][0]*m[2][1];
    float c1 = m[2][0]*m[3][2] - m[3][0]*m[2][2];
    float c2 = m[2][0]*m[3][3] - m[3][0]*m[2][3];
    float c3 = m[2][1]*m[3][2] - m[3][1]*m[2][2];
    float c4 = m[2][1]*m[3][3] - m[3][1]*m[2][3];
    float c5 = m[2][2]*m[3][3] - m[3][2]*m[2][3];
    float det = s0*c5 - s1*c4 + s2*c3 + s3*c2 - s4*c1 + s5*c0;
    assert(det != 0.f && "mat4::inv: singular matrix");
    float invd = 1.f / det;
    mat4 r;
    r[0][0] = ( m[1][1]*c5 - m[1][2]*c4 + m[1][3]*c3) * invd;
    r[0][1] = (-m[0][1]*c5 + m[0][2]*c4 - m[0][3]*c3) * invd;
    r[0][2] = ( m[3][1]*s5 - m[3][2]*s4 + m[3][3]*s3) * invd;
    r[0][3] = (-m[2][1]*s5 + m[2][2]*s4 - m[2][3]*s3) * invd;
    r[1][0] = (-m[1][0]*c5 + m[1][2]*c2 - m[1][3]*c1) * invd;
    r[1][1] = ( m[0][0]*c5 - m[0][2]*c2 + m[0][3]*c1) * invd;
    r[1][2] = (-m[3][0]*s5 + m[3][2]*s2 - m[3][3]*s1) * invd;
    r[1][3] = ( m[2][0]*s5 - m[2][2]*s2 + m[2][3]*s1) * invd;
    r[2][0] = ( m[1][0]*c4 - m[1][1]*c2 + m[1][3]*c0) * invd;
    r[2][1] = (-m[0][0]*c4 + m[0][1]*c2 - m[0][3]*c0) * invd;
    r[2][2] = ( m[3][0]*s4 - m[3][1]*s2 + m[3][3]*s0) * invd;
    r[2][3] = (-m[2][0]*s4 + m[2][1]*s2 - m[2][3]*s0) * invd;
    r[3][0] = (-m[1][0]*c3 + m[1][1]*c1 - m[1][2]*c0) * invd;
    r[3][1] = ( m[0][0]*c3 - m[0][1]*c1 + m[0][2]*c0) * invd;
    r[3][2] = (-m[3][0]*s3 + m[3][1]*s1 - m[3][2]*s0) * invd;
    r[3][3] = ( m[2][0]*s3 - m[2][1]*s1 + m[2][2]*s0) * invd;
    return r;
}

auto mat4::transpose() const -> mat4
{
    mat4 r;
    for(int i=0;i<4;++i)
        for(int j=0;j<4;++j)
            r[i][j] = data[j][i];
    return r;
}

auto mat4::operator[](size_t i) -> vec4 &
{
    return data[i];
}

auto mat4::operator[](size_t i) const -> const vec4 &
{
    return data[i];
}

}