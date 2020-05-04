#include "../test.hpp"
#include <thin/castr.hpp>

int main()
{
	using namespace thin;

	// Compile-time checks
	constexpr castr<10> one_to_nine {"123456789"};
	constexpr castr jats {"just a test string"};
	static_assert(one_to_nine.back() == '9');
	static_assert(*one_to_nine.begin() == '1');
	static_assert(*one_to_nine.end() == '\0');
	static_assert(one_to_nine[9] == '\0');
	static_assert(jats[18] == '\0');
	static_assert(sizeof(one_to_nine) == 10);
	static_assert(sizeof(jats) == jats.length() + 1);
	static_assert(one_to_nine.length() == 9);
	static_assert(jats.length() == 18);
	static_assert(*static_cast<const char*>(jats) == 'j');

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
