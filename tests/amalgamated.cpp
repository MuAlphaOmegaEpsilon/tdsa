#include <thin.hpp>

extern "C" int puts(const char*) noexcept;

int main()
{
	puts("Success.");
	return 0;
}
