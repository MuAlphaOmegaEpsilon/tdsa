#include <thin/revit.hpp>

extern "C" int puts(const char*) noexcept;

static constexpr int ground_truth[] {1, 2, 3, 4, 5};

int main()
{
	using namespace thin;

	// Compile-time checks
	constexpr revit int_rev {ground_truth + 5};
	static_assert(*int_rev == 5, "Wrong int_rev operator*.");
	static_assert(*(int_rev + 1) == 4, "Wrong int_rev operator+.");

	puts("Success.");
	return 0;
}
