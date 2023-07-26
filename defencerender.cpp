enum
{
    kAttachment_BACK = 0,
    kAttachment_DEPTH = 1,
    kAttachment_GBUFFER = 2
};
enum
{
    kSubpass_DEPTH = 0,
    kSubpass_GBUFFER = 1,
    kSubpass_LIGHTING = 2
};
static const VkAttachmentDescription attachments[] = 
{
    //后备缓冲区
    {
        0,
        VK_FORMAT_R8G8B8A8_UNORM,
        VK_SAMPLE_COUNT_1_BIT,
        VK_ATTACHEMENT_LOAD_OP_DONT_CARE,
        VK_ATTACHEMENT_STORE_OP_STORE,
        VK_ATTACHEMENT_LOAD_OP_DONT_CARE,
        VK_ATTACHEMENT_STORE_OP_DONT_CARE,
        VK_IMAGE_LAYOUT_UNDEFINED,
        VK_IMAGE_LAYOUT_PRESENT_SRC_KHR
    },
    //深度缓冲区
    {
        0,
        VK_FORMAT_D32_SFLOAT,
        VK_SMAPLE_COUNT_1_BIT,
        VK_ATTACHEMENT_LOAD_OP_DONT_CARE,
        VK_ATTACHEMENT_STORE_OP_DONT_CARE,
        VK_ATTACHEMENT_LOAD_OP_DONT_CARE,
        VK_ATTACHEMENT_STORE_OP_DONT_CARE,
        VK_IMAGE_LAYOUT_UNDEFINED,
        VK_IMAGE_LAYOUT_UNDEFINED
    };
    //G缓冲区
    {
        0,
        VK_FORMAT_R32G32B32A32_UINT,
        VK_SMAPLE_COUNT_1_BIT,
        VK_ATTACHEMENT_LOAD_OP_DONT_CARE,
        VK_ATTACHEMENT_STORE_OP_DONT_CARE,
        VK_ATTACHEMENT_LOAD_OP_DONT_CARE,
        VK_ATTACHEMENT_STORE_OP_DONT_CARE,
        VK_IMAGE_LAYOUT_UNDEFINED,
        VK_IMAGE_LAYOUT_UNDEFINED
    }
};

//深度预渲染通道深度缓冲区引用（读写）
static const VkAttachmentReference depthAttachmentReference = 
{
    kAttachment_DEPTH,
    VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL
};
//G缓冲区附件引用（渲染）
static const VkAttachmentReference gBufferOutputs[] = 
{
    {
        kAttachment_GBUFFER,
        VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL
    }
};
//光照阶段输入附件引用
static const VkAttachmentReference gBufferReadRef[] = 
{
    //从g缓冲区读取数据
    {
        kAttachment_GBUFFER,
        VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL

    },
    //像纹理一样读取深度
    {
        kAttachment_DEPTH,
        VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL
    }
}

//最终通道--后备缓冲区渲染引用
static const VkAttachmentReference backBufferRenderRef[] = 
{
    {
        kAttachment_BACK,
        VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL
    }
};
static const VkSubpassDescription subpasses[] = 
{
    //子通道1--深度预渲染通道
    {
        0,
        VK_PIPELINE_BIND_POINT_GRAPHICS,
        0,
        nullptr,
        0,
        nullptr,
        nullptr,
        &depthAttachmentReference,
        0,
        nullptr
    },
    //子通道2--产生G缓冲区
    {
        0,
        VK_PIPELINE_BIND_POINT_GRAPHICS,
        0,
        nullptr,
        vkcore::utils::arrarysize(gBufferOutputs),
        gBufferOutputs,
        nullptr,
        &depthAttachmentRenference,
        0,
        nullptr
    },
    //子通道3--光照
    {
        0,
        VK_PIPELINE_BIND_POINT_GRAPHICS,
        vkcore::utils::arrarysize(gBufferReadRef),
        gBufferReadRef,
        vkcore::utils::arrarysize(backBufferRenderRef),
        backBufferRenderRef,
        nullptr,
        nullptr,
        0,
        nullptr
    }
};
static const VkSubpassDependency dependencies[] = 
{
    //g缓冲区通道依赖于深度预渲染通道
    {
        kSubpass_DEPTH,
        kSubpass_GBUFFER,
        VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
        VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,
        VK_PIPELINE_COLOR_ATTACHMENT_WRITE_BIT,
        VK_ACCESS_SHADER_READ_BIT,
        VK_DEPENDENCY_BY_REGION_BOT
    },
    //光照通道依赖于G缓冲区
    {
        kSubpass_GBUFFER,
        kSubpass_LIGHTING,
        VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
        VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,
        VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT,
        VK_ACCESS_SHADER_READ_BIT,
        VK_DEPENDENCY_BY_REGION_BOT
    },
};
static const VkRenderPassCreateInfo renderPassCreateInfo = 
{
    VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO,
    nullptr,
    vkcore::utils::arraysize(attachments),
    attachments,
    vkcore::utils::arraysize(subpass),
    subpass,
    vkcore::utils::arraysize(dependencies),
    dependencies
};
result = vkCreateRenderPass(device,&renderPassCreateInfo,nullptr,&m_renderPass);