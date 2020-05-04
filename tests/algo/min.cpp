#include <algo/min.hpp>
#include <thin/array.hpp>

extern "C" int puts(const char*) noexcept;

constexpr bool revert(const int& a, const int& b) noexcept
{
	return a > b;
}

int main()
{
	using namespace algo;

	// Compile-time checks
	constexpr int zero_to_three[] {0, 1, 2, 3};
	constexpr thin::array one_to_five {1, 2, 3, 4, 5};
	static_assert(min(5, 7) == 5);
	static_assert(min(5, 7, &revert) == 7);
	static_assert(min(zero_to_three) == 0);
	static_assert(min(zero_to_three, revert) == 3);
	static_assert(min(one_to_five) == 1);
	static_assert(min(one_to_five, revert) == 5);

	puts("Success.");
	return 0;
}
