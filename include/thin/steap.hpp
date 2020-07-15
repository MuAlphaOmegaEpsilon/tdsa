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
template<class T, size_t PRE_ALLOC, class SIZE_T = DEFAULT_SIZE_T>
struct steap
{
	static_assert(PRE_ALLOC);

	SIZE_T size;
	T* heap;
	T stack[PRE_ALLOC];

	~steap() NX { delete[] heap; }
	// Utilities
	ND CX SIZE_T sizeHeap() CNX { return heap ? size : 0; }
	ND CX SIZE_T sizeStack() CNX { return heap ? PRE_ALLOC : size; }
	ND CX SIZE_T sizePrealloc() CNX { return PRE_ALLOC; }
	ND CX T* sizedBuffer() NX
	{
		assert(heap == nullptr);
		return size <= PRE_ALLOC ? stack : heap = new T[size];
	}
	// Accessors
	ND CX T& back() NX { return (size - 1)[heap ? heap : stack]; }
	ND CX const T& back() CNX { return (size - 1)[heap ? heap : stack]; }
	ND CX T& operator[](SIZE_T i) NX
	{
		assert(i < size);
		return i[heap ? heap : stack];
	}
	ND CX const T& operator[](SIZE_T i) CNX
	{
		assert(i < size);
		return i[heap ? heap : stack];
	}
	// Conversions
	ND CX operator T*() NX { return heap ? heap : stack; }
	ND CX operator const T*() CNX { return heap ? heap : stack; }
	// Iterators
	ND CX T* begin() NX { return heap ? heap : stack; }
	ND CX T* end() NX { return size + (heap ? heap : stack); }
	ND CX const T* begin() CNX { return heap ? heap : stack; }
	ND CX const T* end() CNX { return size + (heap ? heap : stack); }
};
} // namespace thin

#undef NX
#undef CNX
#undef CX
#undef ND
