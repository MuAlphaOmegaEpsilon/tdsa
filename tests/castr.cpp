#include "test.hpp"
#include <thin/castr.hpp>

int main()
{
	using namespace thin;

	// Compile-time checks
	constexpr castr<10> one_to_nine {"123456789"};
	constexpr castr jats {"just a test string"};
	static_assert(one_to_nine.back() == '9', "Wrong one_to_nine back.");
	static_assert(*one_to_nine.begin() == '1', "Wrong one_to_nine begin.");
	static_assert(*one_to_nine.end() == '\0', "Wrong one_to_nine end.");
	static_assert(one_to_nine[9] == '\0', "one_to_nine doesn't end with \0.");
	static_assert(jats[18] == '\0', "jats doesn't end with \0.");
	static_assert(sizeof(one_to_nine) == 10, "Wrong one_to_nine size.");
	static_assert(sizeof(jats) == jats.length() + 1, "Wrong jats size.");
	static_assert(one_to_nine.length() == 9, "Wrong one_to_nine length.");
	static_assert(jats.length() == 18, "Wrong jats length.");

	// Runtime checks
	castr<10> A {"A"};
	castr AB {A};
	AB[1] = 'B';

	bool result = true;
	result &= test(A.length() == 1, "Wrong A length.");
	result &= test(AB.length() == 2, "Wrong AB length.");
	result &= test(sizeof(A) == 10, "Wrong A size.");
	result &= test(sizeof(AB) == 10, "Wrong AB size.");

	if(result) puts("Success.");
	return result ? 0 : 1;
}
