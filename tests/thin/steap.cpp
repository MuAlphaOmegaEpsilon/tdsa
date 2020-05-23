#include "../test.hpp"
#include <thin/steap.hpp>

extern "C" int puts(const char*) noexcept;

int main()
{
	using namespace thin;

	// Runtime checks
	steap<int, 16> s {};
	bool result = true;
	s.size = 8;
	result &=
		test(s.sizedBuffer() == s, "sizedBuffer 8 differs from operator*.");
	result &= test(s.stack == s, "Wrong operator*, not stack.");
	result &= test(s.size == 8, "Wrong size, not 8.");
	result &= test(s.sizeHeap() == 0, "Wrong sizeHeap(), not 0.");
	result &= test(s.sizeStack() == 8, "Wrong sizeStack(), not 8.");
	result &= test(s.sizePrealloc() == 16, "Wrong sizePrealloc(), not 16.");
	s.size = 64;
	result &=
		test(s.sizedBuffer() == s, "sizedBuffer 64 differs from operator*.");
	result &= test(s.heap == s, "Wrong operator*, not heap.");
	result &= test(s.size == 64, "Wrong size, not 64.");
	result &= test(s.sizeHeap() == 64, "Wrong sizeHeap(), not 64.");
	result &= test(s.sizeStack() == 16, "Wrong sizeStack(), not 16.");
	result &= test(s.sizePrealloc() == 16, "Wrong sizePrealloc(), not 16.");

	if(result) puts("Success.");
	return result ? 0 : 1;
}
