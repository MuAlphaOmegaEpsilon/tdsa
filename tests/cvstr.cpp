#include <thin/cvstr.hpp>

extern "C" int puts(const char*) noexcept;

int main()
{
	using namespace thin;

	// Compile-time checks
	constexpr cvstr one_to_nine {"123456789"};
	constexpr cvstr jats {"just a test string"};
	static_assert(one_to_nine.back() == '9', "Wrong one_to_nine back.");
	static_assert(*one_to_nine.begin() == '1', "Wrong one_to_nine begin.");
	static_assert(*one_to_nine.end() == '\0', "Wrong one_to_nine end.");
	static_assert(one_to_nine[9] == '\0', "one_to_nine doesn't end with \0.");
	static_assert(jats[18] == '\0', "jats doesn't end with \0.");
	static_assert(one_to_nine.size() == 10, "Wrong one_to_nine size.");
	static_assert(jats.size() == jats.length + 1, "Wrong jats size.");
	static_assert(one_to_nine.length == 9, "Wrong one_to_nine length.");
	static_assert(jats.length == 18, "Wrong jats length.");

	puts("Success.");
	return 0;
}
