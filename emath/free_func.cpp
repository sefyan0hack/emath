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

}