//一帧的开始---计算分段的索引
static int framesRendered = 0;
const int segmentIndex = framesRendered % kRingBufferSegments;

//使用一个环状的命令缓冲区，用分段进行索引
const VkCommandBuffer cmdBuffer = m_cmdBuffer[segmentIndex];

//等待和这个分段相关联的栅栏
result = vkWaitForFences(device,1,&m_fence[segmentIndex],VK_TURE,UINT64_MAX);

//现在可以安全的重写该数据了。m_mappedData是包含kRingBufferSegments这个指针的数组
//这些指针指向源缓冲区的永久性映射内存。
fillBufferWithData(m_mappedData[segmentIndex]);

//重置命令缓冲区。我们总是使用相同的命令缓冲区来从暂存缓冲区的给定分段进行复制，
//所以在这里进行重置，因为我们已经等待了相关的栅栏
vkResetCommandBuffer(cmdBuffer,0);

//重新记录命令缓冲区
static const VkCommandBufferBeginInfo beginInfo = 
{
    VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO,
    nullptr,
    VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT,
    nullptr
};

vkBeginCommandBuffer(cmdBuffer,&beginInfo)；
//从暂存缓冲区的正确分段里复制进最终的目标缓冲区
VkBufferCopy copyRegion = 
{
    segmentIndex* kFrameDataSize,
    0,
    kFrameDataSize
};

vkCmdCopyBuffer(
    cmdBuffer,
    m_targetBuffer,
    1,
    &copyRegion
);

vkEndCommandBuffer(cmdBuffer);

//在将这一组任务提交到队列之前，为这个分段重置栅栏
vkResetFences(device,1,&m_fence[segmentIndex]);

//注意，这个例子不适用任何提交信号量。在实际的应用程序中，你应该在单次里提交多个命令缓冲区，并且使用等待和通知信号量保护这个提交操作

VkSubmitInfo submitinfo = 
{
    VK_STRUCTURE_TYPE_SUBMIT_INFO,
    nullptr,
    0,
    nullptr,
    nullptr,
    1,
    &cmdBuffer,
    0,
    nullptr
};

vkQueueSubmit(m_queue,1,&submitInfo,m_fence[segmentIndex]);
framesRendered++;