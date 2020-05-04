#pragma once
#include <stddef.h>

#define NX noexcept
#define CNX const noexcept
#define CX constexpr
#define ND [[nodiscard]]

namespace thin
{
template<class T>
struct revit
{
	T* ptr;

	ND CX T& operator*() NX { return *(ptr - 1); }
	ND CX T* operator->() NX { return ptr - 1; }
	ND CX const T& operator*() CNX { return *(ptr - 1); }
	ND CX const T* operator->() CNX { return ptr - 1; }
	CX revit& operator++() NX
	{
		--ptr;
		return *this;
	}
	CX revit& operator--() NX
	{
		++ptr;
		return *this;
	}
	ND CX revit operator+(ptrdiff_t off) CNX { return revit {ptr - off}; }
	ND CX revit operator-(ptrdiff_t off) CNX { return revit {ptr + off}; }
	ND CX bool operator==(const revit other) CNX { return ptr == other.ptr; }
	ND CX bool operator==(const T* other) CNX { return ptr == other + 1; }
};
template<class T>
revit(T*) -> revit<T>;
} // namespace thin

#undef NX
#undef CNX
#undef CX
#undef ND
