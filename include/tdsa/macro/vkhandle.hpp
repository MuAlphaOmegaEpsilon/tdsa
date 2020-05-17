#pragma once
#define VKHANDLE(x)                                                            \
	struct CONCAT(x, _T);                                                      \
	using x = CONCAT(x, _T)*;
