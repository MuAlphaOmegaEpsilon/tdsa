#pragma once
namespace thin
{
template<class Lambda>
struct scope_guard
{
	Lambda onScopeExit;
	scope_guard(Lambda lambda) noexcept : onScopeExit(lambda) {}
	~scope_guard() noexcept { onScopeExit(); }
};
} // namespace thin
#define CONCATENATE(x, y) x##y
#define SCOPE_EXIT(f) scope_guard CONCATENATE(scopeGuard, __LINE__) { f }
