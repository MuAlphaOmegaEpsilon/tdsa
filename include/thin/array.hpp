#pragma once
#include <stddef.h>

#define NX noexcept
#define CNX const noexcept
#define CX constexpr
#define ND [[nodiscard]]

namespace thin
{
template<class T, size_t N> struct array
{
	T data[N];

	// Utilities
	ND CX size_t size() CNX { return N; }
	// Accessors
	ND CX T& operator[](size_t index) NX { return data[index]; }
	ND CX T& back() NX { return data[N - 1]; }
	ND CX const T& operator[](size_t index) CNX { return data[index]; }
	ND CX const T& back() CNX { return data[N - 1]; }
	// Iterators
	ND CX T* begin() NX { return data; }
	ND CX T* end() NX { return data + N; }
	ND CX const T* begin() CNX { return data; }
	ND CX const T* end() CNX { return data + N; }
};
template<class T, class... varargs>
array(T first, varargs... list) -> array<T, 1 + sizeof...(varargs)>;
} // namespace thin

#undef NX
#undef CNX
#undef CX
#undef ND
