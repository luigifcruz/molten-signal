#ifndef VK_TOOLS_H
#define VK_TOOLS_H

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

#include <fstream>
#include <iostream>
#include <cassert>

#include "magic_enum.hpp"

namespace MoltenSig::Vulkan {

#define VK_CHECK_RESULT(f) {                                                  \
	VkResult res = (f);                                                       \
	if (res != VK_SUCCESS) {                                                  \
		std::cout << "Fatal : VkResult is \"" << magic_enum::enum_name(res) \
                  << "\" in " << __FILE__ << " at line " << __LINE__ << "\n"; \
		assert(res == VK_SUCCESS);                                            \
	}                                                                         \
}

class Tools {
public:
    static VkShaderModule LoadShaderFromFile(const char*, VkDevice);
    static VkShaderModule LoadShader(const uint32_t*, size_t, VkDevice);
};

} // namespace MoltenSig::Vulkan

#endif