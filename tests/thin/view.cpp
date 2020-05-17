#include <thin/view.hpp>

extern "C" int puts(const char*) noexcept;

static constexpr int ground_truth[] {1, 2, 3, 4, 5};

int main()
{
	using namespace thin;

	// Compile-time checks
	constexpr view<const int> ground_view {ground_truth + 1, 2};
	constexpr view<const int, char> charsized_view {ground_truth, 5};
	static_assert(ground_view.back() == 3);
	static_assert(*ground_view.begin() == 2);
	static_assert(*ground_view.end() == 4);
	static_assert(ground_view[0] == 2);
	static_assert(sizeof(char) == sizeof(charsized_view.size));

	puts("Success.");
	return 0;
}
