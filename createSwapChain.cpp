VkResult result;

//首先，创建交换链
VkSwapchainCreateInfoKHR swapChainCreateInfo = 
{
    VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR,//sType
    nullptr,//pNext
    0,//flags
    m_mainSurface,//surface
    2，
    VK_FORMAT_R8G8B8A8_UNORM,//imageFormat
    VK_COLORSPACE_SRGB_NONLOMEAR_KHR,//imageColorSpace
    {1024,768},//imageExtent
    1,//imagearrayLayers
    VK_IMAGE_UASGE_COLOR_ATTACHMENT_BIT,//imageUsage
    VK_SHARING_MODE_EXCLUSIVE,//imageSharingMode
    0,//queueFamilyIndexCount
    nullptr,//pQueueFamilyIndices
    VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR,//perTransform
    VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR,//compositeAlpha
    VK_PRESENT_MODE_FIFO_KHR,//presentMode
    VK_TURE,//clipped
    m_swapChain,//oldswapChain
};
result = vkCreateSwapchainKHR(m_logicalDevice,
            &swapChainCreateInfo,
            nullptr,
            &m_swapChain);

//然后，查询交换链实际所需的图像数量contains
uint32_t swapChainImageCount = 0;
if(result == VK_SUCCESS)
{
    result = vkGetSwapchainImagesKHR(m_logicalDevice,&swapChainCreateInfo,&swapChainImageCount,nullptr);
}
if(result == VK_SUCCESS)
{
    m_swapChainImages.reszie(swapChainImageCount);
    result = vkGetSwapchainImagesKHR(m_logicalDevice,m_swapChain,&swapChainImageCount,m_swapChainImages.data());
}
return result == VK_SUCCESS ? m_swapChain : VK_NULL_HANDLE;