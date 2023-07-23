//描述了合体的图像-采样器。其中有一个集合，两个互斥的绑定
static const VkDevicescriptorSetLayoutBinding Samplers[] = 
{
    {
        0,//相对于绑定的起始位置
        VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER,//合体的图像-采样器
        1, //创建一个绑定
        VK_SHADER_STAGE_ALL; //在所有阶段都能使用
        nullptr//没有静态的采样器
    },
    {
        2, //相当于绑定的起始位置
        VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER,//合体的图像-采样器
        1,//创建一个绑定
        VK_SHADER_STAGE_ALL;//在所有阶段都能使用
        nullptr//没有静态的采样器
    }
};
//这是uniform块。其实有一个集合，一个绑定
static const VkDescriptorSetLayoutBinding UniformBlock = 
{
    0,//相对于绑定的起始位置
    VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,//Uniform内存块
    1,//创建一个绑定
    VK_SHADER_SATGE_ALL,//在所有阶段都能使用
    nullptr //没有
};
//现在创建两个描述符集布局
static const VkDescriptorSetLayoutCreateInfo createInfoSamplers = 
{
    VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO,
    nullptr,
    0,
    2,
    &Samplers[0]
};
static const VkDescriptorSetLayoutCreateInfo createInfoUniforms = 
{
    VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO,
    nullptr,
    0,
    1,
    &UniformBlock
};
//该数组持有两个集合布局
VkDescriptorSetLayerout setLayouts[2];

vkCreateDescriptorSetLayout(device,&createInfoSamplers,nullptr,&setLayouts[0]);
vkCreateDescriptorSetLayout(device,&createInfoUniforms,nullptr,&setLayouts[1]);
//现在创建管线布局
const VkPipelineLayoutCreateInfo pipelineLayoutCreateInfo = {
    VK_STRUCTURE_TYPE_PIPELINR_LAYOUT_CREATE_INFO,
    nullptr,
    0,
    2,
    setLayouts,
    0,
    nullptr
};

VkPipelineLayout pipelineLayout;
vkCreatePipelineLayout(device,&pipelineLayoutCreateInfo,nullptr,pipelineLayoutCreateInfo);