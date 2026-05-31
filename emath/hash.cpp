#include "hash.hpp"


auto hash_combine(size_t &seed, auto hash) -> void
{
	hash += 0x9e3779b9 + (seed << 6) + (seed >> 2);
	seed ^= hash;
}

auto std::hash<emath::vec2>::operator()(emath::vec2 const& v) const noexcept -> size_t
{
	size_t seed = 0;
	hash<float> hasher;
	hash_combine(seed, hasher(v.x));
	hash_combine(seed, hasher(v.y));
	return seed;
}
	

auto std::hash<emath::vec3>::operator()(emath::vec3 const& v) const noexcept -> size_t
{
	size_t seed = 0;
	hash<float> hasher;
	hash_combine(seed, hasher(v.x));
	hash_combine(seed, hasher(v.y));
	hash_combine(seed, hasher(v.z));
	return seed;
}
	

auto std::hash<emath::vec4>::operator()(emath::vec4 const& v) const noexcept -> size_t
{
	size_t seed = 0;
	hash<float> hasher;
	hash_combine(seed, hasher(v.x));
	hash_combine(seed, hasher(v.y));
	hash_combine(seed, hasher(v.z));
	hash_combine(seed, hasher(v.w));
	return seed;
}
	
auto std::hash<emath::ivec2>::operator()(emath::ivec2 const& v) const noexcept -> size_t
{
	size_t seed = 0;
	hash<int> hasher;
	hash_combine(seed, hasher(v.x));
	hash_combine(seed, hasher(v.y));
	return seed;
}
	

auto std::hash<emath::ivec3>::operator()(emath::ivec3 const& v) const noexcept -> size_t
{
	size_t seed = 0;
	hash<int> hasher;
	hash_combine(seed, hasher(v.x));
	hash_combine(seed, hasher(v.y));
	hash_combine(seed, hasher(v.z));
	return seed;
}
	

auto std::hash<emath::ivec4>::operator()(emath::ivec4 const& v) const noexcept -> size_t
{
	size_t seed = 0;
	hash<int> hasher;
	hash_combine(seed, hasher(v.x));
	hash_combine(seed, hasher(v.y));
	hash_combine(seed, hasher(v.z));
	hash_combine(seed, hasher(v.w));
	return seed;
}	

auto std::hash<emath::mat2>::operator()(emath::mat2 const& m) const noexcept -> size_t
{
	size_t seed = 0;
	hash<emath::vec2> hasher;
	hash_combine(seed, hasher(m[0]));
	hash_combine(seed, hasher(m[1]));
	return seed;
}


auto std::hash<emath::mat3>::operator()(emath::mat3 const& m) const noexcept -> size_t
{
	size_t seed = 0;
	hash<emath::vec3> hasher;
	hash_combine(seed, hasher(m[0]));
	hash_combine(seed, hasher(m[1]));
	hash_combine(seed, hasher(m[2]));
	return seed;
}


auto std::hash<emath::mat4>::operator()(emath::mat4 const& m) const noexcept -> size_t
{
	size_t seed = 0;
	hash<emath::vec4> hasher;
	hash_combine(seed, hasher(m[0]));
	hash_combine(seed, hasher(m[1]));
	hash_combine(seed, hasher(m[2]));
	hash_combine(seed, hasher(m[3]));
	return seed;
}

auto std::hash<emath::quat>::operator()(emath::quat const& q) const noexcept -> size_t
{
	size_t seed = 0;
	hash<float> hasher;
	hash_combine(seed, hasher(q.x));
	hash_combine(seed, hasher(q.y));
	hash_combine(seed, hasher(q.z));
	hash_combine(seed, hasher(q.w));
	return seed;
}	