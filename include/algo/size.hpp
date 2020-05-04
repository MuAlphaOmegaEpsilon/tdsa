#pragma once
#include <stddef.h>
namespace algo
{
template<class T, size_t N>
[[nodiscard]] static constexpr size_t size(const T (&)[N]) noexcept
{
	return N;
}
} // namespace algo
