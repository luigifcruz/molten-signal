#include "vulkan/tools.h"

namespace MoltenSig::Vulkan {

VkShaderModule Tools::LoadShaderFromFile(const char* filename, VkDevice device) {
    std::ifstream is(filename, std::ios::binary | std::ios::ate);

    if (!is.is_open()) {
        throw std::runtime_error("[VULKAN] Can't open shader file.");
    }

    size_t size = (size_t)is.tellg();
    is.seekg(0, std::ios::beg);
    char* shaderCode = new char[size];
    is.read(shaderCode, size);
    is.close();

    assert(size > 0);

    std::cout << size << std::endl;

    VkShaderModule module = Vulkan::Tools::LoadShader(
        reinterpret_cast<const uint32_t*>(shaderCode), size, device);

    delete [] shaderCode;

    return module;
}

VkShaderModule Tools::LoadShader(const uint32_t* code, size_t size, VkDevice device) {
    VkShaderModule shaderModule;
    VkShaderModuleCreateInfo moduleCreateInfo{};
    moduleCreateInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    moduleCreateInfo.codeSize = size;
    moduleCreateInfo.pCode = code;

    VK_CHECK_RESULT(vkCreateShaderModule(device, &moduleCreateInfo, nullptr, &shaderModule));

    return shaderModule;
}

} // namespace MoltenSig::Vulkan