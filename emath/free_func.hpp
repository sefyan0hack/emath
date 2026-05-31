#pragma once


namespace emath {

auto to_deg(float rad) -> float;
auto to_deg(const struct vec3& rad) -> vec3;
auto to_rad(float deg) -> float;
auto to_rad(const struct vec3& deg) -> vec3;

}