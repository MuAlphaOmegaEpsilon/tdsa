#pragma once
#include "default_size_t.hpp"
#include <assert.h>
#include <stddef.h>

#define NX noexcept
#define CNX const noexcept
#define CX constexpr
#define ND [[nodiscard]]

namespace thin
{
template<class T, class SIZE_T = DEFAULT_SIZE_T>
struct view
{
	T* data;
	SIZE_T size;

	// Utilities
	ND CX bool empty() CNX { return !size; }
	// Accessors
	ND CX T& back() NX
	{
		assert(size);
		return data[size - 1];
	}
	ND CX T& operator[](SIZE_T index) NX
	{
		assert(index < size);
		return data[index];
	}
	ND CX const T& back() CNX
	{
		assert(size);
		return data[size - 1];
	}
	ND CX const T& operator[](SIZE_T index) CNX
	{
		assert(index < size);
		return data[index];
	}
	// Operators
	ND CX operator T*() NX { return data; }
	ND CX operator const T*() CNX { return data; }
	CX view& operator=(const T* other) NX
	{
		data = other;
		return *this;
	}
	// Iterators
	ND CX T* begin() NX { return data; }
	ND CX T* end() NX { return data + size; }
	ND CX const T* begin() CNX { return data; }
	ND CX const T* end() CNX { return data + size; }
};
template<class T, class SIZE_T = size_t, SIZE_T N>
view(T (&)[N]) -> view<T, SIZE_T>;
template<class T, class SIZE_T = size_t>
view(T*, SIZE_T) -> view<T, SIZE_T>;
} // namespace thin

#undef NX
#undef CNX
#undef CX
#undef ND
