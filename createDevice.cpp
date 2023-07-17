VkResult result;
VkPhysicalDeviceFetures supportedFeatures;
VkPhysicalDeviceFetures requiresFeatures = {};

vkGetPhysicalDeviceFeatures(m_physicalDevices[0],&supportedFeatures);

requiredFeatures.multiDreawIndirect = supportedFeatures.multiDrawIndirect;
requiredFeatures.tessellationShader = VK_TURE;
requiredFeatures.geometryShader = VK_TURE;
const VkDeviceQueueCreateInfo deviceQueueCreateInfos = {
    VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO,//sType
    nullptr,
    0,
    0,
    1,
    nullptr
};
const VkDeviceQueueCreateInfo deviceCreateInfo {
    VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO,//sType
    nullptr,
    0,
    1,
    &deviceQueueCreateInfo,
    0,
    nullptr,
    0,
    nullptr,
    &requiredFeatures
};

result = vkCreateDevice(m_physicalDevices[0],&deviceCreateInfo,nullptr,&m_logicalDevie);