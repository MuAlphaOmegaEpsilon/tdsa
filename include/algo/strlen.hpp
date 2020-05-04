#pragma once
#include <stddef.h>
namespace algo
{
static constexpr size_t strlen(const char* s) noexcept
{
	const char* needle = s;
	while(*needle) ++needle;
	return static_cast<size_t>(needle - s);
}
} // namespace algo
