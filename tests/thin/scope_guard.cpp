#include <thin/scope_guard.hpp> // for array
extern "C" int puts(const char*) noexcept;
extern "C" void exit(int) noexcept;

int main()
{
	using namespace thin;
	SCOPE_EXIT([](){ puts("Success."); exit(0); });
	return 1;
}
