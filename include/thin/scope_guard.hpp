#pragma once
namespace thin
{
template<class Lambda>
struct scope_guard
{
	Lambda onScopeExit;
	constexpr scope_guard(Lambda lambda) noexcept : onScopeExit(lambda) {}
	constexpr ~scope_guard() noexcept { onScopeExit(); }
};
} // namespace thin
