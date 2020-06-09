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
struct cvstr
{
	const char* data {nullptr};
	size_t length {0};

	CX cvstr() NX = default;
	template<size_t N>
	CX cvstr(const char (&s)[]) NX : data(s), length(N)
	{
	}
	CX cvstr(const char* s) NX : data(s), length(algo::strlen(s)) {}
	CX cvstr(const char* s, size_t len) NX : data(s), length(len) {}
	// Utilities
	ND CX bool empty() CNX { return !length; }
	ND CX size_t size() CNX { return length + 1; }
	// Accessors
	ND CX char back() CNX { return length ? data[length - 1] : '\0'; }
	ND CX const char& operator[](size_t index) CNX
	{
		assert(index < length);
		return data[index];
	}
	// Conversions
	ND CX operator const char*() CNX { return data; }
	// Iterators
	ND CX const char* begin() CNX { return data; }
	ND CX const char* end() CNX { return data + length; }
};
} // namespace thin

#undef NX
#undef CNX
#undef CX
#undef ND
