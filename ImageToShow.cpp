const VkImageMemoryBarrier barrier = 
{
    VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,//sType
    nullptr,//pNext
    VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT,//srcAccessMask
    VK_ACCESS_MEMORY_READ_BIT,//dstAccessMask
    VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,//oldLayout
    VK_IMAGE_LAYOUR_PRESENT_SRC_KHR,//newLayout
    0,//srcQueueFamily
    0,//dstQueueFamilyIndex
    sourceImage,//image
    {//subresourceRange
        VK_IMAGE_ASPECT_COLOR_BIT,//aspectMask
        0, //baseMipLevel
        1, //levelCount
        0, //baseArrayLayerout
        1, //layerCount
    }
};
vkCmdPipelineBarrier(cmdBuffer,VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,0,0,nullptr,0,nullptr,1,&barrier);
