#pragma once
namespace algo
{
namespace fproto
{
template<class T>
using blackbox_1 = T& (*const)(T&);
template<class T>
using blackbox_2 = T& (*const)(T&, T&);
} // namespace fproto
} // namespace algo
