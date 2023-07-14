

int main(void)
{
    /***/
    /*创建实例*/
    typedef struct VkApplicationInfo {
        VkStructureType sType;//VK_STRUCTURE_TYPE-APPLICATION_INFO
        const void* pNext;//nullptr
        const char* pApplicationName;
        uint32_t applicationVersion;
        const char* pEngineName;
        uint32_t engineVersion;
        uint32_t apiVersion;
    }VkApplicationInfo;

    typedef struct VkInstanceCreateInfo{
        VkStructureType sType; //结构体类型
        const void* pNext; //扩展接口
        VkInstanceCreateFlags flags;//预留字段
        const VkApplicationInfo* pApplicationInfo;
        uint32_t enableLayerCount;//激活实例层的个数
        const char* const* ppEnableLayerName;//激活实例层的名字
        uint32_t    enableExtensionCount;//激活扩展层个数
        const char* const* ppEnableExtensionName;//激活扩展层名字
    }VkInstanceCreateInfo;

    VkResult vkCreateInstance(
        const VkInstanceCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkInstance* pInstance);

    /*查找设备*/
    VkResult vkEnumeratePhysicalDevices(
        VkInstance instance,
        uint32_t*  pPhysicalDeviceCount,
        VkPhysicalDevice* pPhysicalDevices
    );

    typedef struct VkPhysicalDeviceProperties {
        uint32_t    apiVersion;
        uint32_t    driverVersion;
        uint32_t    vendorID;
        uint32_t    deviceID;
        VkPhysicalDeviceType    deviceType;
        char    deviceName  [VK_MAX_PHYSICAL_DEVICE_NAME_SIZE];
        uint8_t pipelineCacheUUIDp[VK_UUID_SIZE];
        VkPhysicalDeviceLimits  limits;
        VkPhysicalDeviceSparseProperties    sparseProperties;
    }VkPhysicalDeviceProperties;

    //判断设备支持特性
    void vkGetPhysicalDeviceFeatures(
        VkPhysicalDevice    physicalDevice,
        vkPhysicalDeviceFeatures*   pFeatures
    );



    return 0
}



