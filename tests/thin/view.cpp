#include <thin/view.hpp>

extern "C" int puts(const char*) noexcept;

static constexpr int ground_truth[] {1, 2, 3, 4, 5};

int main()
{
	using namespace thin;

	// Compile-time checks
	constexpr view<const int> ground_view {ground_truth + 1, 2};
	static_assert(ground_view.back() == 3);
	static_assert(*ground_view.begin() == 2);
	static_assert(*ground_view.end() == 4);
	static_assert(ground_view[0] == 2);

	puts("Success.");
	return 0;
}
