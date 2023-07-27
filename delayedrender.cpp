enum
{
    kAttachment_BACK  =0,
    kAttachment_DEPTH =1,
    kAttachment_GBUFFER = 2,
    kAttachment_TRANSLUCENCY = 3,
    kAttachment_OPAQUE = 4
};
enum
{
    kSubpass_DEPTH = 0,
    kSubpass_GBUFFER = 1,
    kSubpass_LIGHTING = 2,
    kSubpass_TRANSLUCENTS = 3,
    kSubpass_COMPOSITE = 4
};
static const VkAttachmentDescription attachments[] = 
{
    //后备缓冲区
    {
        0,
        VK_FORMAT_R8G8B8A8_UNORM,
        VK_SAMPLE_COUNT_1_BIT,
        VK_ATTACHMENT_LOAD_OP_DONT_CARE,
        VK_ATTACHMENT_STORE_OP_STORE,
        VK_ATTACHMENT_LOAD_OP_DONT_CARE,
        VK_ATTACHMENT_STORE_OP_DONT_CARE,
        VK_IMAGE_LAYOUT_UNDEFINED,
        VK_IMAGE_LAYOUT_PRESENT_SRC_KHR
    },
    //深度缓冲区
    {
        0,
        VK_FORMAT_D32_SFLOAT,
        VK_SAMPLE_COUNT_1_BIT,
        VK_ATTACHMENT_LOAD_OP_DONT_CARE,
        VK_ATTACHMENT_STORE_OP_DONT_CARE,
        VK_ATTACHMENT_LOAD_OP_DONT_CARE,
        VK_ATTACHMENT_STORE_OP_DONT_CARE,
        VK_IMAGE_LAYOUT_UNDEFINED,
        VK_IMAGE_LAYOUT_UNDEFINED
    },
    //g缓冲区
    {
        0,
        VK_FORMAT_R32G32B32A32_UINT,
        VK_SAMPLE_COUNT_1_BIT,
        VK_ATTACHMENT_LOAD_OP_DONT_CARE,
        VK_ATTACHMENT_STORE_OP_DONT_CARE,
        VK_ATTACHMENT_LOAD_OP_DONT_CARE,
        VK_ATTACHMENT_STORE_OP_DONT_CARE,
        VK_IMAGE_LAYOUT_UNDEFINED,
        VK_IMAGE_LAYOUT_UNDEFINED
    },
    //半透明缓冲区
    {
        0,
        VK_FORMAT_R8G8B8A8_UNORM,
        VK_SAMPLE_COUNT_1_BIT,
        VK_ATTACHMENT_LOAD_OP_DONT_CARE,
        VK_ATTACHMENT_STORE_OP_DONT_CARE,
        VK_ATTACHMENT_LOAD_OP_DONT_CARE,
        VK_ATTACHMENT_STORE_OP_DONT_CARE,
        VK_IMAGE_LAYOUT_UNDEFINED,
        VK_IMAGE_LAYOUT_UNDEFINED
    }
};
//深度预渲染通道深度缓冲区引用（读/写）
static VkAttachmentReference gBufferReadRef[] = 
{
    //从g缓冲区里读取
    {
        kAttachment_GBUFFER,
        VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL
    },
    //像纹理一样读取深度
    {
        kAttachment_DEPTH,
        VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL
    }
};
//光照通道--写入不透明缓冲区
static VkAttachmentReference opaqueWrite[] = 
{
    //写入不透明缓冲区中
    {
        kAttachment_OPAQUE,
        VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL
    }
};

//半透明渲染通道 写入半透明缓冲区中
static const VkAttachmentReference translucentWrite[] = 
{
    //写入半透明缓冲区中
    {
        kAttachment_TRANSLUCENCY,
        VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL
    }
};
static const VkAttachmentReference compositeInputs[] = 
{
    //从半透明中读取
    {
        kAttachment_TRANSLUCENCY,
        VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL
    },
    //从不透明中读取
    {
        kAttachment_OPAQUE,
        VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL
    }

};
//最终的通道--后备缓冲区渲染引用
static const VkAttacchmentReference backBufferRenderRef[]=
{
    {
        kAttachment_BACK,
        VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL
    }
};
static const VkSubpassDescription subpasses[] = 
{
    //子通道1 --深度预渲染通道
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
        nullptr,
    },
    //子通道2 --产生G缓冲区
    {
        0,
        VK_PIPELINE_BIND_POINT_GRAPHICS,
        0,
        nullptr,
        0,
        nullptr,
        vkcore::utils::arraysize(gBufferOutputs),
        gBufferOutputs,
        nullptr,
        &depthAttachmentReference,
        0,
        nullptr
    },
    //子通道3 --光照
    {
        0,
        VK_PIPELINE_BIND_POINT_GRAPHICS,
        vkcore::utils::arraysize(gBufferReadRef),
        gBufferReadRef,
        vkcore::utils::arraysize(opaqueWrite),
        opaqueWrite,
        nullptr,
        nullptr,
        0,
        nullptr
    },
    //子通道4 -- 半透明对象
    {
        0,
        VK_PIPELINE_BIND_POINT_GRAPHICS,
        0,
        nullptr,
        vkcore::utils::arraysize(translucentWrite),
        tanslucentWrite,
        nullptr,
        nullptr,
        0,
        nullptr
    },
    //子通道4 --合成
    {
        0,
        VK_PIPELINE_BIND_POINT_GRAPHICS,
        0,
        nullptr,
        vkcore::utils::arraysize(backBufferRenderRef),
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
        VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT,
        VK_ACCESS_SHADER_READ_BIT,
        VK_DEPENDENCY_BY_REGION_BIT
    },
    //光照通道依赖于g缓冲区
    {
        kSubpass_GBUFFER,
        kSubpass_LIGHTING,
        VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
        VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,
        VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT,
        VK_ACCESS_SHADER_READ_BIT,
        VK_DEPENDENCY_BY_REGION_BIT
    },
    //合成通道依赖于半透明通道
    {
        kSubpass_TRANSPARENT,
        kSubpass_COMPOSITE,
        VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
        VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,
        VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT,
        VK_ACCESS_SHADER_READ_BIT,
        VK_DEPENDENCY_BY_REGION_BIT
    },
    //合成通道依赖于光照通道
    {
        kSubpass_LIGHTING,
        kSubpass_COMPOSITE,
        VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
        VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,
        VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT,
        VK_ACCESS_SHADER_READ_BIT,
        VK_DEPENDENCY_BY_REGION_BIT
    }
};
static const VkRenderPassCreateInfo renderPassInfo = {
    {
        VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO,
        0,
        vkcore::utils::arraysize(attachments),
        attachments,
        vkcore::utils::arraysize(subpasses),
        subpasses,
        vkcore::utils::arraysize(dependencies),
        dependencies
    }
};
result = vkCreateRenderPass(device,&renderPassInfo,nullptr,&m_renderPass);
