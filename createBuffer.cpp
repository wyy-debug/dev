static const VkBufferCreateInfo bufferCreateInfo = {
    VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
    nullptr,
    0,
    1024 * 1024,
    VK_BUFFER_USAGE_TRANSFE_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT,
    VK_SHARING_MODE_EXCLUSIVE,
    0,
    nullptr
};

VkBuffer buffer = VK_NULL_HANDLE;

vkCreateBuffer(device,&bufferCreateInfo,&buffer);