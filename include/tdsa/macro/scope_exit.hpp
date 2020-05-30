#pragma once
#include "unique.hpp"
#include <thin/scope_guard.hpp>
#define SCOPE_EXIT thin::scope_guard UNIQUE(scopeGuard) =
#define SCOPE_EXIT_VOID thin::scope_guard UNIQUE(scopeGuard) = []()
