VkImage image = VK_NULL_HANDLE;
VkResult result = VK_SUCCESS;
static const VkImageCreateInfo imageCreateInfo = {
    VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,//sType
    nullptr, //pNext
    0,//flags
    VK_IMAGE_TYPE_2D,//imageType
    VK_FORMAT_R8G8B8A8_UNORM,//format
    {1024,1024,1}, //extent
    10, //mipLevels
    1,//arrayLayers
    VK_SAMPLE_COUNT_1_BIT,//samples
    VK_IMAGE_TILING_OPTIMAL,//tiling
    VK_IMAGE_USAGE_SAMPLED_BIT, //sharingMode
    0, //queueFamilyIndexCount
    nullptr,//pQueueFamilyIndices
    VK_IMAGE_LAYOUT_UNDEFINDE //initialLayout
};
result = vkCreateImage(device,&imageCreateInfo,nullptr,&image);