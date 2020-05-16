#include <tdsa/macro/scope_exit.hpp>
#include <thin/scope_guard.hpp>
extern "C" int puts(const char*) noexcept;
extern "C" void exit(int) noexcept;

int main()
{
	using namespace thin;
	SCOPE_EXIT([]() {
		puts("Success.");
		exit(0);
	});
	return 1;
}
