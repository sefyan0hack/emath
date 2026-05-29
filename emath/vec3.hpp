namespace emath {

class vec3
{
public:
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

    auto component_product(const vec3& other) const -> vec3;

    static auto dot(const vec3& l, const vec3& r) -> float;

    auto magnitude() const -> float;
    auto normalize() -> void;

private:
    float x, y, z;
};


} // namespace emath