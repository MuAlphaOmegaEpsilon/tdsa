#include <algo/max.hpp>
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
	static_assert(max(5, 7) == 7);
	static_assert(max(5, 7, &revert) == 5);
	static_assert(max(zero_to_three) == 3);
	static_assert(max(zero_to_three, revert) == 0);
	static_assert(max(one_to_five) == 5);
	static_assert(max(one_to_five, revert) == 1);

	puts("Success.");
	return 0;
}
