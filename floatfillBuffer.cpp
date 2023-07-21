void FillBufferWithFloats(VkCommandBuffercmd Buffer,VkBuffer dstBuffer,VkDeviceSize offset,VkDeviceSize length,const float value)
{
    vkCmdFillBuffer(cmdBuffer,dstBuffer,0,1024,*(const uint32_t*)&value);
}