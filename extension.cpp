uint32_t numInstanceExtensions = 0;
std::vector<VkExtensionProperties> instanceExtensionProperties;

//查询实例扩展
vkEnumerateInstanceExtensionProperties(nullptr,&numInstanceExtensions,nullptr)
//如果有支持的扩展，查询它们的属性
if(numInstanceExtensions != 0)
{
    //申请内存
    instanceExtensionProperties.resize(numInstanceExtensions);
    vkEnumerateInstanceExtensionProperties(nullptr,
    &numInstanceExtensions,instanceExtensionProperties.data());
}