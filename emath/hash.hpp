#pragma once
#include <cstddef>
#include <functional>

#include "vec2.hpp"
#include "vec3.hpp"
#include "vec4.hpp"
#include "ivec2.hpp"
#include "ivec3.hpp"
#include "ivec4.hpp"
#include "uvec2.hpp"
#include "uvec3.hpp"
#include "uvec4.hpp"
#include "mat2.hpp"
#include "mat3.hpp"
#include "mat4.hpp"
#include "quat.hpp"

namespace std
{
	template <> struct hash<emath::vec2>
	{
		auto operator()(emath::vec2 const& v) const noexcept -> size_t;
	};

	template <> struct hash<emath::vec3>
	{
		auto operator()(emath::vec3 const& v) const noexcept -> size_t;
	};

	template <> struct hash<emath::vec4>
	{
		auto operator()(emath::vec4 const& v) const noexcept -> size_t;
	};

	template <> struct hash<emath::ivec2>
	{
		auto operator()(emath::ivec2 const& v) const noexcept -> size_t;
	};

	template <> struct hash<emath::ivec3>
	{
		auto operator()(emath::ivec3 const& v) const noexcept -> size_t;
	};

	template <> struct hash<emath::ivec4>
	{
		auto operator()(emath::ivec4 const& v) const noexcept -> size_t;
	};

	template <> struct hash<emath::uvec2>
	{
		auto operator()(emath::uvec2 const& v) const noexcept -> size_t;
	};

	template <> struct hash<emath::uvec3>
	{
		auto operator()(emath::uvec3 const& v) const noexcept -> size_t;
	};

	template <> struct hash<emath::uvec4>
	{
		auto operator()(emath::uvec4 const& v) const noexcept -> size_t;
	};

	template <> struct hash<emath::mat2>
	{
		auto operator()(emath::mat2 const& v) const noexcept -> size_t;
	};

    template <> struct hash<emath::mat3>
	{
		auto operator()(emath::mat3 const& v) const noexcept -> size_t;
	};

    template <> struct hash<emath::mat4>
	{
		auto operator()(emath::mat4 const& v) const noexcept -> size_t;
	};

    template <> struct hash<emath::quat>
	{
		auto operator()(emath::quat const& v) const noexcept -> size_t;
	};

}