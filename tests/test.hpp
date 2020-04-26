#pragma once

extern "C" int puts(const char*) noexcept;

[[nodiscard]] constexpr bool test(bool value, const char* message) noexcept
{
	if(value) puts(message);
	return value;
}
