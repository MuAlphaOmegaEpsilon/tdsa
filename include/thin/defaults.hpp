#pragma once
#include <stddef.h>

namespace thin
{
using DEFAULT_SIZE_TYPE =
#ifdef THIN_DEFAULT_SIZE_TYPE
	THIN_DEFAULT_SIZE_TYPE
#else
	size_t
#endif
;
static constexpr size_t DEFAULT_PREALLOC {
#ifdef THIN_DEFAULT_PREALLOC
	THIN_DEFAULT_PREALLOC
#else
	16
#endif
};
} // namespace thin

#undef THIN_DEFAULT_PREALLOC
#undef THIN_DEFAULT_SIZE_TYPE
