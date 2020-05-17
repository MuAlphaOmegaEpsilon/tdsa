#pragma once
namespace thin
{
template<class Lambda>
struct scope_guard
{
	const Lambda onScopeExit;
	constexpr scope_guard(Lambda lambda) noexcept : onScopeExit(lambda) {}
	~scope_guard() noexcept { onScopeExit(); }
};
} // namespace thin
