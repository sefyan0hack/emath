#pragma once
#include "vec3.hpp"

namespace emath {

auto to_deg(float rad) -> float;
auto to_deg(const vec3& rad) -> vec3;
auto to_rad(float deg) -> float;
auto to_rad(const vec3& deg) -> vec3;

}