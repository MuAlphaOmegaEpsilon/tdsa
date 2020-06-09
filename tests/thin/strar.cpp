#include <thin/strar.hpp>

extern "C" int puts(const char*) noexcept;

int main()
{
	using namespace thin;

	// Compile-time checks
	constexpr strar<1> unused;
	constexpr strar<5> one_to_five {"1", "2", "3", "4", "5"};
	constexpr strar hello_world {"Hello", "C++", "world!"};
	static_assert(unused[0] == nullptr);
	static_assert(unused[0].length == 0);
	static_assert(one_to_five[0][0] == '1');
	static_assert((*hello_world.begin())[0] == 'H');
	static_assert(*(hello_world.end() - 1)[0] == 'w');
	static_assert(hello_world.size() == 3);
	static_assert(hello_world[0].length == 5);
	static_assert(hello_world.back().length == 6);

	puts("Success.");
	return 0;
}
