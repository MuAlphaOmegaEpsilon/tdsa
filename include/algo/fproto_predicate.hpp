#pragma once
#define R __restrict__
namespace algo
{
namespace fproto
{
template<class T>
using predicate_1 = bool (*const)(const T&);
template<class T>
using predicate_2 = bool (*const)(const T& R, const T& R);
} // namespace fproto
} // namespace algo
#undef R
