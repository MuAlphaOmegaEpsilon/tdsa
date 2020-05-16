#pragma once
#include <stddef.h>
#define NSC [[nodiscard]] static constexpr
#define NX noexcept
namespace algo
{
NSC size_t strlen(const char* s) NX
{
	const char* needle = s;
	while(*needle) ++needle;
	return static_cast<size_t>(needle - s);
}
NSC size_t strlen(const char* const* arr, size_t extra_num) NX
{
	size_t length = 0;
	do
		length += strlen(*arr++);
	while(extra_num--);
	return length;
}
template<size_t N>
NSC size_t strlen(const char* const (&arr)[N]) NX
{
	size_t length = 0;
	for(const char* s : arr) length += strlen(s);
	return length;
}
template<class Collection>
NSC size_t strlen(const Collection& c) NX
{
	size_t length = 0;
	for(const char* s : c) length += strlen(s);
	return length;
}
} // namespace algo
#undef NSC
#undef NX
