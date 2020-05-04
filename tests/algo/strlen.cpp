#include <algo/strlen.hpp>

extern "C" int puts(const char*) noexcept;

int main()
{
	using namespace algo;

	// Compile-time checks
	constexpr const char* seven_chars {"1234567"};
	static_assert(strlen(seven_chars) == 7);

	puts("Success.");
	return 0;
}
