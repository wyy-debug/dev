VkBufferMemoryBarrier bufferMemoryBarrier = 
{
    VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
    nullptr,
    VK_ACCESS_TRANSFER_WRITE_BIT,
    VK_ACCESS_HOST_READ_BIT,
    VK_QUEUE_FAMILY_IGNORED,
    VK_QUEUE_FAMILY_IGNORED,
    buffer,
    0,
    VK_WHOLE_SIZE
};

vkCmdPipelineBarrier(
    cmdBuffer,
    VK_PIPELINE_STAGE_TRANSFER_BIT,
    VK_PIPELINE_STAGE_HOST_BIT,
    0,
    0,
    nullptr,
    1,
    &bufferMemoryBarrier,
    0,
    nullptr
);
