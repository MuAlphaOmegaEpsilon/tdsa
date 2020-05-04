#pragma once
#include "array.hpp"
#include "cvstr.hpp"

#define NX noexcept
#define CNX const noexcept
#define CX constexpr
#define ND [[nodiscard]]

namespace thin
{
template<class... varargs>
struct strar
{
	array<cvstr, sizeof...(varargs)> arr;

	CX strar(varargs... va) NX : arr {va...} {}
	// Utilities
	ND CX size_t size() CNX { return sizeof...(varargs); }
	// Accessors
	ND CX const cvstr& back() CNX { return arr[sizeof...(varargs) - 1]; }
	ND CX const cvstr& operator[](size_t index) CNX { return arr[index]; }
	// Iterators
	ND CX cvstr* begin() NX { return arr.begin(); }
	ND CX cvstr* end() NX { return arr.end(); }
	ND CX const cvstr* begin() CNX { return arr.begin(); }
	ND CX const cvstr* end() CNX { return arr.end(); }
};
} // namespace thin

#undef NX
#undef CNX
#undef CX
#undef ND
