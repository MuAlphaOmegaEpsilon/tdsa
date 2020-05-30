#include "../test.hpp"
#include <thin/ver3.hpp>

extern "C" int puts(const char*) noexcept;
extern "C" [[gnu::nonnull(1, 2)]] int strcmp(const char* __restrict__,
											 const char* __restrict__) noexcept;
int main()
{
	using namespace thin;

	// Compile-time checks
	constexpr ver3 maximum {1023, 1023, 4095};
	static_assert(maximum.major == 0x3ff);
	static_assert(maximum.minor == 0x3ff);
	static_assert(maximum.patch == 0xfff);
	static_assert(maximum == UINT32_MAX);

	// Runtime checks
	castr<ver3::MAX_C> stringVersion = ver3 {1u, 2u, 3u};
	bool result =
		test(strcmp(stringVersion, "1.2.3") == 0, "Wrong string conversion.");

	if(result) puts("Success.");
	return result ? 0 : 1;
}
