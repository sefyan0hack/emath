#include "free_func.hpp"
#include <numbers>

namespace emath {

auto to_deg(float rad) -> float
{
    return rad * 180.0f / std::numbers::pi_v<float>;
}

auto to_rad(float deg) -> float
{
    return deg * (std::numbers::pi_v<float> / 180.0f);
}

auto to_deg(const vec3& rad) -> vec3
{
    return {to_deg(rad.x), to_deg(rad.y), to_deg(rad.z)};
}

}