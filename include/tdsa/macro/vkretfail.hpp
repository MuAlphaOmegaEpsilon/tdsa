#pragma once
#define VKRETFAIL(x)                                                           \
	if(const VkResult r = x; r != VK_SUCCESS) return r
