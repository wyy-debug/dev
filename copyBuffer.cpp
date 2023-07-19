void CopyDataBetweenBuffers(VkCmdBuffer cmdBuffer,VkBuffer srcBuffer,VkDeviceSize srcOffset,VkBufferSize dstOffset,VkDeviceSize size)
{
    const VkBufferCopy copyRegion = {
        srcOffset,
        dstOffset,
        size
    };
    VkCmdCopyBuffer(cmdBuffer,srcBuffer,dstBuffer,1,&copyRegion);
}