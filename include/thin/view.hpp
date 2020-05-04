#pragma once
#include <stddef.h>

#define NX noexcept
#define CNX const noexcept
#define CX constexpr
#define ND [[nodiscard]]

namespace thin
{
template<class T>
struct view
{
	T* data;
	size_t size;

	// Utilities
	ND CX bool empty() CNX { return !size; }
	// Accessors
	ND CX T& back() NX { return data[size - 1]; }
	ND CX T& operator[](size_t index) NX { return data[index]; }
	ND CX const T& back() CNX { return data[size - 1]; }
	ND CX const T& operator[](size_t index) CNX { return data[index]; }
	// Conversions
	ND CX operator T*() NX { return data; }
	ND CX operator const T*() CNX { return data; }
	// Iterators
	ND CX T* begin() NX { return data; }
	ND CX T* end() NX { return data + size; }
	ND CX const T* begin() CNX { return data; }
	ND CX const T* end() CNX { return data + size; }
};
template<class T>
view(T*, size_t) -> view<T>;
} // namespace thin

#undef NX
#undef CNX
#undef CX
#undef ND
