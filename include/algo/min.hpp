#pragma once
#include "fproto_predicate.hpp"
#include <stddef.h>
#define NSC [[nodiscard]] static constexpr
#define NX noexcept
namespace algo
{
template<class T>
NSC const T& min(const T& a, const T& b) NX
{
	return a < b ? a : b;
}
template<class T>
NSC const T& min(const T& a, const T& b, fproto::predicate_2<T> lesserCmp) NX
{
	return lesserCmp(a, b) ? a : b;
}
template<class T, size_t N>
NSC const T& min(const T (&arr)[N]) NX
{
	const T* candidate = &arr[0];
	for(size_t i = 1; i < N; i++)
		if(arr[i] < *candidate) [[unlikely]] candidate = &arr[i];
	return *candidate;
}
template<class T, size_t N>
NSC const T& min(const T (&arr)[N], fproto::predicate_2<T> lesserCmp) NX
{
	const T* candidate = &arr[0];
	for(size_t i = 1; i < N; i++)
		if(lesserCmp(arr[i], *candidate)) [[unlikely]] candidate = &arr[i];
	return *candidate;
}
template<class Collection>
NSC const auto& min(const Collection& c) NX
{
	const auto* candidate = &c[0];
	const size_t col_size = c.size();
	for(size_t i = 1; i < col_size; i++)
		if(c[i] < *candidate) [[unlikely]] candidate = &c[i];
	return *candidate;
}
template<class Collection, class T>
NSC auto& min(const Collection& c, fproto::predicate_2<T> lesserCmp) NX
{
	const auto* candidate = &c[0];
	const size_t col_size = c.size();
	for(size_t i = 1; i < col_size; i++)
		if(lesserCmp(c[i], *candidate)) [[unlikely]] candidate = &c[i];
	return *candidate;
}
} // namespace algo
#undef NSC
#undef NX
