#pragma once
#include <stddef.h>

#define NX noexcept
#define CNX const noexcept
#define CX constexpr
#define ND [[nodiscard]]

namespace thin
{
template<size_t N> struct castr
{
	char data[N];

	// Utilities
	ND CX bool empty() CNX { return !length(); }
	ND CX size_t length() CNX { return strlen(data); }
	ND CX size_t size() CNX { return N; }
	// Accessors
	ND CX char& back() NX { return data[N - 2]; }
	ND CX char& operator[](size_t index) NX { return data[index]; }
	ND CX const char& back() CNX { return data[N - 2]; }
	ND CX const char& operator[](size_t index) CNX { return data[index]; }
	// Conversions
	ND CX operator char*() NX { return data; }
	ND CX operator const char*() CNX { return data; }
	// Iterators
	ND CX char* begin() NX { return data; }
	ND CX char* end() NX { return data + N - 1; }
	ND CX const char* begin() CNX { return data; }
	ND CX const char* end() CNX { return data + N - 1; }

  private:
	CX static size_t strlen(const char* s) NX
	{
		const char* needle = s;
		while(*needle) ++needle;
		return static_cast<size_t>(needle - s);
	}
};
template<size_t N> castr(const char (&)[N]) -> castr<N>;
} // namespace thin

#undef NX
#undef CNX
#undef CX
#undef ND
