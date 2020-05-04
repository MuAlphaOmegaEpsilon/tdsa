#include <thin/cvstr.hpp>

extern "C" int puts(const char*) noexcept;

int main()
{
	using namespace thin;

	// Compile-time checks
	constexpr cvstr one_to_nine {"123456789"};
	constexpr cvstr jats {"just a test string"};
	static_assert(one_to_nine.back() == '9');
	static_assert(*one_to_nine.begin() == '1');
	static_assert(*one_to_nine.end() == '\0');
	static_assert(one_to_nine[9] == '\0');
	static_assert(jats[18] == '\0');
	static_assert(one_to_nine.size() == 10);
	static_assert(jats.size() == jats.length + 1);
	static_assert(one_to_nine.length == 9);
	static_assert(jats.length == 18);
	static_assert(*static_cast<const char*>(jats) == 'j');

	puts("Success.");
	return 0;
}
