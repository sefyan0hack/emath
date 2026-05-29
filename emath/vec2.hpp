namespace emath {

auto to_deg(float rad) -> float;
auto to_rad(float deg) -> float;

struct vec2
{
    vec2();
    vec2(float a);
    vec2(float x, float y);

    auto operator+=(const vec2& other) -> vec2&;
    auto operator-=(const vec2& other) -> vec2&;

    auto operator*=(float a) -> vec2&;

    auto operator+(const vec2& other) const -> vec2;
    auto operator-(const vec2& other) const -> vec2;

    auto operator*(const vec2& other) const -> float;
    auto operator*(float a) const -> vec2;
    auto operator-() const -> vec2;

    auto magnitude() const -> float;

    auto is_normalized() const -> bool;

    auto component_product(const vec2& other) const -> vec2;

    static auto length() -> int;
    static auto normalize(const vec2& v) -> vec2;
    static auto dot(const vec2& l, const vec2& r) -> float;
    static auto angle(const vec2& l, const vec2& r, bool rad = true) -> float;

    float x, y, z;
};

} // namespace emath