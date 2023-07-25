typedef struct vertex_t
{
    vmath::vec3 normal;
    vmath::vec2 texcoord;
}vertex;

static const VkVertexInputBindingDescription vertexInputBindings[]=
{
    {0,sizeof(vmath::vec4),VK_VERTEX_INPUT_RATE_VERTEX},//缓冲区1
    {1,sizeof(vertex),VK_VERTEX_INPUT_RATE_VERTEX}//缓冲区2
};
static const VkVertexInputAttributeDescription vertexAttributes[] = 
{
    {0,0,VK_FORMAT_R32G32B32A32_SFLOAT,0},//position
    {1,1,VK_FORMAT_R32G32B32_SFLOAT,0},//normal
    {2,1,VK_FORMAT_R32G32_SFLOAT,sizeof(vmath::vec3)}//texcoord
};
static const VkPipelineVertexInputStateCreateInfo vertexInputInfoStateCreateInfo = 
{
    VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO,//sType
    nullptr,//pNext
    0,//flags
    vkcore::utils::arraySize(vertexInputBindings),//vertexBindingDescriptionCount
    vertexInputBindings,//pVertexBindingDescriptions
    vkcore::utils::arraySize(vertexAttributes),//vertexAttributeDescriptionCount
    vertexAttributes//pVertexAttributeDescriptions
}