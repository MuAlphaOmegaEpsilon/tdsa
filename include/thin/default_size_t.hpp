#pragma once
#include <stddef.h>
#include <stdint.h>
#ifdef THIN_SIZE_T
namespace thin
{
using DEFAULT_SIZE_T = THIN_SIZE_T;
}
#else
namespace thin
{
using DEFAULT_SIZE_T = size_t;
} // namespace thin
#endif
