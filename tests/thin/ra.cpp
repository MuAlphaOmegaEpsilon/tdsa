#include <thin/ra.hpp>

extern "C" int puts(const char*) noexcept;

template<class T>
constexpr int accumulate(T& int_collection)
{
	int result = 0;
	for(const int value : int_collection) result += value;
	return result;
}
template<size_t N>
constexpr size_t count(thin::ra<int, N> a)
{
	return a.size();
}

int main()
{
	using namespace thin;

	// Compile-time checks
	[[maybe_unused]] constexpr ra<int> zero_allowed {};
	[[maybe_unused]] constexpr ra deduced_type_and_size {0, 1, 2, 3, 4};
	constexpr ra<int, 10> zero_to_nine {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	constexpr ra<int, 5> partial {0, 1};
	constexpr ra<int, 3> zero_init {};
	static_assert(count(ra {1, 2, 3}) == 3);
	static_assert(zero_to_nine.size() == 10);
	static_assert(zero_to_nine.back() == 9);
	static_assert(zero_to_nine[7] == 7);
	static_assert(accumulate(zero_to_nine) == 10 * 9 / 2);
	static_assert(!partial[2] && !partial[3] && !partial[4]);
	static_assert(!zero_init[0] && !zero_init[1] && !zero_init[2]);

	// Runtime checks
	ra rw_ints {0, 1, 2, 3};
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
