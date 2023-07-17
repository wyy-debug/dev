uint32_t    queueFamilyPropertyCount;
std::vector<VkQueueFamiltProperties> queueFamilyProperties;
VkPhysicalDeviceMemoryProperties physicalDeviceMemoryProperties;

//获取物理设备的内存属性

vkGetPhysicalDeviceMemoryPropertoes(m_physicalDevices[deviceIndex],&physicalDeviceMemoryProperties);


//首先查询物理设备支持的队列族的数量
vkGetPhysicalDeviceQueueFamilyProperties(m_phyDevices[0],&queueFamilyPropertyCount,nullptr);

//为队列属性结构体分配足够的空间
queueFamilyProperties.resize(queueFamilyPropertyCount);

//现在查询所有队列族的实际属性
vkGetPhysicalDeviceQueueFamilyProperties(
    m_physicalDevices[0],
    &queueFamilyPropertyCount,
    queueFamilyProperties.data()
);
