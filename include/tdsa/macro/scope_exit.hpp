#pragma once
#include "unique.hpp"
#include <thin/scope_guard.hpp>
#define SCOPE_EXIT(f) scope_guard UNIQUE(scopeGuard) { f }
