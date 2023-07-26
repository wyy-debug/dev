struct PushConstantData
{
    vmath::mat4 mvp_matrix;
    float displacement_scale;
};
static const VkDescriptorSetLayoutBinding descriptorBindings[] =
{
    //唯一的绑定是可采样的图像和采样器的结合
    {
        0,
        VK_DESRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER,
        1,
        VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT,
        nullptr
    }
};
static const VkDescriptorSetLayoutCreateInfo descriptorSetLayoutCreateInfo = 
{
    VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO,
    nullptr,
    0,
    vkcore::utils::arraysize(descriptorBindings),
    descriptorBindings
};
vkCreateDesriptorSetLayout(getDevice(),&descriptorSetLayoutCreateInfo,nullptr,&m_descriptorSetLayout);
//定义推送一个常量的范围
static const VkPushConstantRange pushConstantRange[] = 
{
    //将数据推送至评估着色器
    {
        VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT,
        0,
        sizeof(PushConstantData)
    }
};

VkPipelineLayoutCreateInfo pipelineLayoutCreateInfo = 
{
    VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO,
    nullptr,
    0,
    1,
    &m_descriptorSetLayout,
    vkcore::utils::arraysize(PushConstantData)
    pushConstantRange
};
result = vkCreatePipelineLayout(getDevice(),&pipelineLayoutCreateInfo,nullptr,&m_pipelineLayout);