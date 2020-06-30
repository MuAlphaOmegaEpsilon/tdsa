#pragma once
#include <assert.h>
#include <stddef.h>

#define NX noexcept
#define CNX const noexcept
#define CX constexpr
#define ND [[nodiscard]]

namespace thin
{
template<class T, size_t N, class SIZE_T = size_t>
struct array
{
	T data[N ? N : 1];

	// Utilities
	ND CX SIZE_T size() CNX { return static_cast<SIZE_T>(N); }
	// Accessors
	ND CX T& operator[](size_t index) NX
	{
		static_assert(N);
		assert(index < N);
		return data[index];
	}
	ND CX const T& operator[](size_t index) CNX
	{
		static_assert(N);
		assert(index < N);
		return data[index];
	}
	ND CX T& back() NX
	{
		static_assert(N);
		assert(N - 1 < N);
		return data[N - 1];
	}
	ND CX const T& back() CNX
	{
		static_assert(N);
		assert(N - 1 < N);
		return data[N - 1];
	}
	// Conversions
	ND CX operator T*() NX
	{
		if constexpr(!N) return nullptr;
		return data;
	}
	ND CX operator const T*() CNX
	{
		if constexpr(!N) return nullptr;
		return data;
	}
	// Iterators
	ND CX T* begin() NX { return operator T*(); }
	ND CX T* end() NX { return operator T*() + N; }
	ND CX const T* begin() CNX { return operator const T*(); }
	ND CX const T* end() CNX { return operator const T*() + N; }
};
template<class T, class... varargs>
array(T first, varargs... list) -> array<T, 1 + sizeof...(varargs)>;
} // namespace thin

#undef NX
#undef CNX
#undef CX
#undef ND
