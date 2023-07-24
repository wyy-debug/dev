//这是颜色附件，是R8G8B8A8_UNORM类型的单采样图像。我们希望在渲染通道开始时对它进行清除，并在完成以后
//保存它。它以UNDEFINED布局开始，这是Vulkan的一个关键字，允许丢弃旧内容，并且我们希望在完成时将它设置为
//COLOR_ATTACHMENT_OPTIMAL状态
static const VkAttachmentDescription attachments[] = 
{
    {
        0,//flags
        VK_FORMAT_R8G8B8A8_UNORM,//format
        VK_SAMPLE_COUNT_1_BIT,//samples
        VK_ATTACHMENT_LOAD_OP_CLEAR,//loadOp
        VK_ATTACHMENT_STORE_OP_STORE,//storeOp
        VK_ATTACHMENT_LOAD_OP_DONT_CARE,//stencilLoadOp
        VK_ATTACHMENT_STORE_OP_DONT_CARE,//stencilStoreOp
        VK_IMAGE_LAYOUT_UNDEFINEE,//initalLayout
        VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL//finalLayout
    }
};

//这是对唯一附件的唯一引用
static const VkAttachmentReference attchmentReferences[] = 
{
    {
        0,//attachment
        VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL//finalLayout
    }
};
//这个渲染通道只有一个子通道，并只有一个对改输出附件的引用
static const VkSubpassDescription subpasses[] = 
{
    {
        0,//flags
        VK_PIPELINE_BIND_POINT_GRAPHICS,//pipelineBindPoint
        0,//inputAttachmentCount
        nullptr,//pInputAttachments
        1,//colorAttachmentCount
        &attachmentReferences[0],//pColorAttachments
        nullptr,//pResolveAttachments
        nullptr,//pDepthStencilAttachment
        0,//preserveAttachmentCount
        nullptr,//pPreserveAttachments
    }
};
//最终，这是Vulkan创建渲染通道对象所需的信息
static VkRenderPassCreateInfo renderpassCreateInfo = 
{
    VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO,//sType
    nullptr,//pNext
    0,//flags
    1,//attachmentCount
    &attachments[0],//pAttachments
    1,//subpassCount
    &subpasses[0],//pSubpasses
    0,//dependencyCount
    nullptr//pDependencies
};

VkRenderPass renderpass = VK_NULL_HANDLE;
//实际执行的代码只有这一段，用于创建渲染通道对象
vkCreateRenderPass(device,&renderpassCreateInfo,nullptr,&renderpass);