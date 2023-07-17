uint32_t numInstanceLayers = 0;
std::vector<VkLayerProperties> instanceLayerProperties;

//查询实例层
vkEnumerateInstanceLayerProperties(&numInstanceExtensions,nullptr);


//如果有支持的层，查询属性
if(numInstanceLayers != 0)
{
    instanceLayerProperties.resize(numInstanceLayers);
    vkEnumerateInstanceLayerProperties(nullptr,&numInstanceLayers,instanceLayerProperties.data());
}
