#pragma once
#include "castr.hpp"
#include <assert.h>
#include <inttypes.h>
#define NX noexcept
#define CNX const noexcept
#define CX constexpr
#define ND [[nodiscard]]

extern "C" [[gnu::format(printf, 3, 4)]] int
snprintf(char* __restrict__, size_t, const char* __restrict__, ...) noexcept;

namespace thin
{
struct ver3
{
	static constexpr int MAX_MAJOR_CHARS = 4; // 2^10 = 1024
	static constexpr int MAX_MINOR_CHARS = 4; // 2^10 = 1024
	static constexpr int MAX_PATCH_CHARS = 4; // 2^12 = 4096
	static constexpr int MAX_C =
		MAX_MAJOR_CHARS + MAX_MINOR_CHARS + MAX_PATCH_CHARS + 2 + 1;
	uint_fast16_t major;
	uint_fast16_t minor;
	uint_fast16_t patch;
	CX ver3(uint32_t M, uint32_t m, uint32_t p) NX : major(M),
													 minor(m),
													 patch(p)
	{
		assert(major < 1024);
		assert(minor < 1024);
		assert(patch < 4096);
	}
	CX ver3(uint32_t compact) NX : major(compact >> 22u),
								   minor((compact >> 12u) & 0x000003ffu),
								   patch(compact & 0x00000fffu)
	{
		assert(major < 1024);
		assert(minor < 1024);
		assert(patch < 4096);
	}
	ND CX operator uint32_t() CNX
	{
		assert(major < 1024);
		assert(minor < 1024);
		assert(patch < 4096);
		return major << 22u | minor << 12u | patch;
	}
	ND operator castr<MAX_C>() CNX
	{
		castr<MAX_C> s;
		assert(major < 1024);
		assert(minor < 1024);
		assert(patch < 4096);
		::snprintf(s.data, 15, "%" PRIuFAST16 ".%" PRIuFAST16 ".%" PRIuFAST16,
				   major, minor, patch);
		return s;
	}
	ND castr<MAX_C> str() CNX { return this->operator castr<MAX_C>(); }
	/*
	ND operator const char*() CNX
	{
		return this->operator castr<MAX_C>();
	}
	*/
};
} // namespace thin
#undef NX
#undef CNX
#undef CX
#undef ND
