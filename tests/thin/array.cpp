#include <thin/array.hpp> // for array

extern "C" int puts(const char*) noexcept;

template<class T>
constexpr int accumulate(T& int_collection)
{
	int result = 0;
	for(const int value : int_collection) result += value;
	return result;
}

int main()
{
	using namespace thin;

	// Compile-time checks
	[[maybe_unused]] constexpr array deduced_type_and_size {0, 1, 2, 3, 4};
	constexpr array<int, 10> zero_to_nine {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	constexpr array<int, 5> partial {0, 1};
	constexpr array<int, 3> zero_init {};
	static_assert(zero_to_nine.size() == 10);
	static_assert(zero_to_nine.back() == 9);
	static_assert(zero_to_nine[7] == 7);
	static_assert(accumulate(zero_to_nine) == 10 * 9 / 2);
	static_assert(!partial[2] && !partial[3] && !partial[4]);
	static_assert(!zero_init[0] && !zero_init[1] && !zero_init[2]);

	// Runtime checks
	array rw_ints {0, 1, 2, 3};
	for(int i = 0; i < 4; i++)
	{
		const int new_value = (i + 1) * 2;
		rw_ints[i] = new_value;
		if(rw_ints[i] != new_value)
		{
			puts("Wrong value from operator[] after write.");
			return 1;
		}
	}

	puts("Success.");
	return 0;
}
