namespace emath {

struct vec3
{
    vec3();
    vec3(float a);
    vec3(float x, float y, float z);

    auto operator+=(const vec3& other) -> vec3&;
    auto operator-=(const vec3& other) -> vec3&;

    auto operator*=(float a) -> vec3&;

    auto operator+(const vec3& other) const -> vec3;
    auto operator-(const vec3& other) const -> vec3;

    auto operator*(const vec3& other) const -> float;
    auto operator*(float a) const -> vec3;
    auto operator-() const -> vec3;

    auto magnitude() const -> float;

    auto is_normalized() const -> bool;
    auto is_parallel_to(const vec3& other) const -> bool;

    auto component_product(const vec3& other) const -> vec3;

    static auto length() -> int;
    static auto normalize(const vec3& v) -> vec3;
    static auto dot(const vec3& l, const vec3& r) -> float;
    static auto cross(const vec3& l, const vec3& r) -> vec3;
    static auto is_parallel(const vec3& l, const vec3& r) -> bool;
    static auto angle(const vec3& l, const vec3& r, bool rad = true) -> float;

    float x, y, z;
};

} // namespace emath