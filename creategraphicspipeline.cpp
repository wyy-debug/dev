VkPipelineShaderStageCreateInfo shaderStageCreateInfo = 
{
    VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO,//sType
    nullptr,//pNext
    0,//flags
    VK_SHADER_STAGE_VERTEX_BIT,//stage
    module,//module
    "main",//pName
    nullptr//pSpecicalinzationInfo
};
static const VkPipelineVertexInputStateCreateInfo vertexInputStateCreateInfo = 
{
    VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO,//sType
    nullptr,//pNext
    0,//flags
    0,//vertexBindingDescriptionCount
    nullptr,//pVertexBindingDescriptions
    0,//vertexAttributeDesciptionCount
    nullptr//pVertexAttributeDesciprtons
};

static const VkPipelineInputAssemblyStateCreateInfo inputAssemblyStateCreateInfo = 
{
    VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO,//sType
    nullptr,//pNext
    0,//flags
    VK_PRIMITIVE_TOPOLOGY_POINT_LIST,//topology
    VK_FALSE //primitiveRestartEnable
};

static const VkViewprot dummyViewport = 
{
    0.0f,0.0f,//x,y
    1.0f,1.0f,//width,height
    0.1f,1000.0f//minDepth,maxDepth
};

static const VkRect2D dummyScissor = 
{
    {0,0},//offset
    {1,1}//extent
};

static const VkPipelineViewportStateCreateInfo viewportStateCreateInfo = 
{
    VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO,//sType
    nullptr,//pNext
    0,//flags
    1,//viewportCount
    &dummyViewport,//pViewports
    1,//scissorCount
    &dummyScissor//pScissors
};
static const VkPipelineRasterizationStateCreateInfo rasterizationStateCreateInfo = 
{
    VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO,//sType
    nullptr,//pNext
    0,//flags
    VK_FALSE,//depthClampEnable
    VK_TRUE,//rasterizerDiscardEnable
    VK_POLYGON_MODE_FILL,//polygonMode
    VJ_CULL_MODE_NONE,//cullMode
    VK_FRONT_FACE_COUNTER_CLOCKWISE,//frontFace
    VK_FALSE,//depthBiasEnable
    0.0f,//depthBiasConstantFactor
    0.0f,//depthBiasClamp
    0.0f,//depthBiasSlopeFactor
    0.0f//lineWidth
};
static const VkGraphicsPipelineCreateInfo graphicsPipelineCreateInfo = 
{
    VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO,//sType
    nullptr,//pNext
    0,//flags
    1,//stageCount
    &shaderStageCreateInfo,//pStages
    &vertexInputStateCreateInfo,//pVertexInputState
    &inputAssemblyStateCreateInfo,//pInputAssemblyState
    nullptr,//pTessellationState
    &viewportStateCreateInfo,//pViewportState
    &rasterizationStateCreateInfo,//pRasterizationState
    nullptr,//pMultisampleState
    nullptr,//pDepthStencilState
    nullptr,//pColorBlendState
    nullptr,//pDynamicState
    VK_NULL_HANDLE,//layout
    renderpass,//renderpass
    0,//subpass
    VK_NULL_HANDLE,//basePipelineHandle
    0//basePipelineIndex
};

result = vkCreateGraphicsPipelines(device,VK_NULL_HANDLE,1,&graphicsPipelineCreateInfo,nullptr,&pipeline);