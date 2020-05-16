#include <algo/strlen.hpp>
#include <thin/strar.hpp>

extern "C" int puts(const char*) noexcept;

int main()
{
	using namespace algo;

	// Compile-time checks
	constexpr const char* seven_chars {"1234567"};
	constexpr const char* hello_world[] {"Hello", "world", "!"};
	constexpr thin::strar string_array {"Super", "string", "array"};
	static_assert(strlen(seven_chars) == 7);
	static_assert(strlen(hello_world + 1, 1) == 6);
	static_assert(strlen(hello_world) == 11);
	static_assert(strlen(string_array) == 16);

	puts("Success.");
	return 0;
}
