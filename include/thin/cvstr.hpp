#pragma once
#include <stddef.h>

#define NX noexcept
#define CNX const noexcept
#define CX constexpr
#define ND [[nodiscard]]

namespace thin
{
struct cvstr
{
	const char* const data;
	const size_t length;

	CX cvstr(const char* s) NX : data(s), length(strlen(s)) {}
	CX cvstr(const char* s, size_t len) NX : data(s), length(len) {}
	// Utilities
	ND CX bool empty() CNX { return !length; }
	ND CX size_t size() CNX { return length + 1; }
	// Accessors
	ND CX char back() CNX { return data[length - 1]; }
	ND CX const char& operator[](size_t index) CNX { return data[index]; }
	// Conversions
	ND CX operator const char*() CNX { return data; }
	// Iterators
	ND CX const char* begin() CNX { return data; }
	ND CX const char* end() CNX { return data + length; }

  private:
	CX static size_t strlen(const char* s) NX
	{
		const char* needle = s;
		while(*needle) ++needle;
		return static_cast<size_t>(needle - s);
	}
};
} // namespace thin

#undef NX
#undef CNX
#undef CX
#undef ND
