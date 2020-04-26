#include <thin/strar.hpp>

extern "C" int puts(const char*) noexcept;

int main()
{
	using namespace thin;

	// Compile-time checks
	constexpr strar hello_world {"Hello", "C++", "world!"};
	static_assert((*hello_world.begin())[0] == 'H', "Wrong hello_world begin.");
	static_assert(*(hello_world.end() - 1)[0] == 'w', "Wrong hello_world end.");
	static_assert(hello_world.size() == 3, "Wrong hello_world size.");
	static_assert(hello_world[0].length == 5, "Wrong hello_world[0] length.");
	static_assert(hello_world.back().length == 6,
				  "Wrong hello_world.back() length.");

	puts("Success.");
	return 0;
}
