#include <algo/size.hpp>

extern "C" int puts(const char*) noexcept;

int main()
{
	using namespace algo;

	// Compile-time checks
	constexpr int seven_integers[] {1, 2, 3, 4, 5, 6, 7};
	static_assert(size(seven_integers) == 7);

	puts("Success.");
	return 0;
}
