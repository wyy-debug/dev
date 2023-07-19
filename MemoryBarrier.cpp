const VkImageMemoryBarrier imageMemoryBarriers = {
    VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,//sType
    nullptr, //pNext
    VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT,//srcAccessMask
    VK_ACCESS_SHADER_READ_BIT,//dstAccessMask
    VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,//oldLayout,
    VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,//newLayour,
    VK_QUEUE_FAMILY_IGNORED,//srcQueueFamilyIndex,
    VK_QUEIE_FAMILY_IGNORED,//dstQueueFamilyIndex,
    image,//image
    {
        VK_IMAGE_ASPECT_COLOR_BIT,//aspectMask
        0,//baseMipLevel
        VK_REMAINING_MIP_LEVELS,//levelCount
        0,//baseArrayLayer
        VK_REMAINING_ARRAY_LAYERS,//layerCount
    }
};

vkCmdPipelineBarrier(m_currentCommandBuffer,VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
                    VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,0,0,nullptr,0,nullptr,1,&imageMemoryBarrier);