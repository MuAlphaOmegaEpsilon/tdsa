#pragma once

extern "C" int puts(const char*) noexcept;

[[nodiscard]] constexpr bool test(bool cond, const char* message) noexcept
{
	if(!cond) puts(message);
	return cond;
}
