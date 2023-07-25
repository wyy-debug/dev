typedef struct vertex_t
{
    vmath::vec4 position;
    vmath::vec3 normal;
    vmath::vec2 texcoord;
}vertex;

static const VkVertexInputBindingDescription vertexInputBindings[]=
{
    {0,sizeof(vertex),VK_VERTEX_INPUT_RATE_VERTEX}//buffer
};
static const VkVertexInputAttributeDesciption vertexAttributes[]=
{
    {0,0,VK_FORMAT_R32G32B32A32_SLOAT,0},//Position
    {1,0,VK_FORMAT_R32G32B32_SFLOAT,offsetof(vertex,normal)},//normal
    {2,0,VK_FORMAT_R32G32_SFLOAT,offsetof(vertex,texcoord)}//Texcoord
};
static const VkPipelineVertexInputStateCreateInfo vertexInputStateCreateInfo = 
{
    VK_STRICTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO,//sType
    nullptr,//pNext
    0,//flags
    vkcore::utils::arraysize(vertexInputBindings),//vertexBindingDescriptionCount
    vertexInputBindings;//pVertexBindingDesciptions
    vkcore::utils::arraysize(vertexAttributes),//vertexAttributeDesciptionCount
    vertexAttributes//pVertexAttributeDesciptions
}