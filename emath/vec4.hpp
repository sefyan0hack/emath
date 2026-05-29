namespace emath {

struct vec4
{
    vec4();
    vec4(float a);
    vec4(float x, float y, float z, float w);

    auto operator+=(const vec4& other) -> vec4&;
    auto operator-=(const vec4& other) -> vec4&;

    auto operator*=(float a) -> vec4&;

    auto operator+(const vec4& other) const -> vec4;
    auto operator-(const vec4& other) const -> vec4;

    auto operator*(const vec4& other) const -> float;
    auto operator*(float a) const -> vec4;
    auto operator-() const -> vec4;

    auto magnitude() const -> float;

    auto is_normalized() const -> bool;

    auto component_product(const vec4& other) const -> vec4;

    static auto length() -> int;
    static auto normalize(const vec4& v) -> vec4;
    static auto dot(const vec4& l, const vec4& r) -> float;
    static auto angle(const vec4& l, const vec4& r, bool rad = true) -> float;

    float x, y, z, w;
};

} // namespace emath