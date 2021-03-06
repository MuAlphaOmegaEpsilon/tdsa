#pragma once
#include "../algo/strlen.hpp"
#include <assert.h>
#include <stddef.h>

#define NX noexcept
#define CNX const noexcept
#define CX constexpr
#define ND [[nodiscard]]

namespace thin
{
template<size_t N>
struct castr
{
	char data[N ? N : 1] {};

	// Utilities
	ND CX bool empty() CNX { return !length(); }
	ND CX size_t length() CNX
	{
		if constexpr(N < 2) return 0;
		return algo::strlen(data);
	}
	ND CX size_t size() CNX { return N; }
	// Accessors
	ND CX char& back() NX
	{
		if constexpr(N < 2) return data[0];
		return data[N - 2];
	}
	ND CX char& operator[](size_t index) NX
	{
		assert(index < N);
		return data[index];
	}
	ND CX const char& back() CNX
	{
		if constexpr(N < 2) return data[0];
		return data[N - 2];
	}
	ND CX const char& operator[](size_t index) CNX
	{
		assert(index < N);
		return data[index];
	}
	// Operators
	ND CX operator char*() NX { return data; }
	ND CX operator const char*() CNX { return data; }
	// Iterators
	ND CX char* begin() NX { return data; }
	ND CX char* end() NX
	{
		if constexpr(!N) return data;
		return data + N - 1;
	}
	ND CX const char* begin() CNX { return data; }
	ND CX const char* end() CNX
	{
		if constexpr(!N) return data;
		return data + N - 1;
	}
};
castr()->castr<0>;
template<size_t N>
castr(const char (&)[N]) -> castr<N>;
} // namespace thin

#undef NX
#undef CNX
#undef CX
#undef ND
