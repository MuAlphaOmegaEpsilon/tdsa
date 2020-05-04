#pragma once
#include <stdint.h>
namespace algo
{
template<class T>
using score8 = uint_fast8_t (*const)(const T&);
template<class T>
using score16 = uint_fast16_t (*const)(const T&);
template<class T>
using score32 = uint_fast32_t (*const)(const T&);
template<class T>
using score64 = uint_fast64_t (*const)(const T&);
} // namespace algo
