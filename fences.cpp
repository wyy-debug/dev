//kFrameDataSize是单帧里使用的数据的大小。kRingBufferSegments是值得保留数据的帧的数量。
//创建图个缓冲区，大到能够保存kRingBufferSegments份kFrameDataSize
static const VkBufferCreateInfo bufferCreateInfo = 
{
    VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
    nullptr,
    kFrameDataSize * kRingBufferSegments,
    VK_BUFFER_USAGE_TRANSFER_SRC_BIT,
    VK_SHARING_MODE_EXCLUSIVE,
    0,
    nullptr
};

result = vkCreateBuffer(device,&bufferCreateInfo,nullptr,&m_buffer);
//创建kRingBufferSegments个栅栏，初始状态都是有信号的状态
static const VkFenceCreateInfo fenceCreateInfo = 
{
    VK_STRUCTURE_TYPE_FENCE_CREATE_INFO,
    nullptr,
    VK_FENCE_CREATE_SIGNALED_BIT
};
for (int i = 0; i < kRingBufferSegments;++i)
{
    result = vkCreateFence(device,&fenceCreateInfo,nullptr,&m_fence[i]);
}