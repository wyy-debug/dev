

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

    /*查找物理设备*/
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

    //判断物理设备支持特性
    void vkGetPhysicalDeviceFeatures(
        VkPhysicalDevice    physicalDevice,
        vkPhysicalDeviceFeatures*   pFeatures
    );

    //查询物理设备的内存类型和堆配置
    void vkGetPhysicalDeviceMemoryProperties(
        VkPhysicalDevice    physicalDevice,
        VkPhysicalDeviceMemoryProperties* pMemoryProperties);
    
    typedef struct VkPhysicalDeviceMemoryProperties{
        uint32_t    memoryTypeCount;//内存类型数量
        VkMemoryType    memoryTypes[VK_MAX_MEMORY_TYPES];
        uint32_t    memoryHeapCount;
        VkMemoryHeap    memoryHeaps[VK_MAX_MEMORY_HEAPS];
    }VkPhysicalDeviceMemoryProperties;

    typedef struct VkMemoryType{
        VkMemoryPropertyFlags   propertyFlags;
        uint32_t    heapIndex;
    }VkMemoryType;

    typedef struct VkMemoryHeap {
        VkDeviceSize        size;
        VkMemoryHeapFlags   flags;
    }VkMemoryHeap;

    //查询物理设备队列
    void vkGetPhysicalDeviceQueueFamilyProperties(
        VkPhysicalDevice    physicalDevice,
        uint32_t*           pQueueFamilyPropertyCount,
        VkQueueFamilyProperties* pQueueFamilyProperties
    );

    typedef struct VkQueueFamilyProperties{
        VkQueueFlgs queueFlags;
        uint32_t    queueCount;
        uint32_t    timestampValidBits;
        VkExtent3D  minImageTransferGranularity;
    }VkQueueFamilyProperties;

    //创建逻辑设备
    VkResult vkCreateDevice(
        VkPhysicalDevice    physicalDevice,
        const VkDeviceCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkDevice*              pDevice
    );

    typedef struct VkDeviceCreateInfo{
        VkStrucetureType    sType;
        const void*         pNext;
        VkDeviceCreateFlags flags;
        uint32_t    queueCreateInfoCount;
        const VkDeviceQueueCreatInfo*   pQueueCreateInfos;
        uint32_t enableedLayerCount;
        const char* const*  ppEnabledLayerNames;
        uint32_t    enabledExtensionCount;
        const char* const*  ppEnabledExtensionNames;
        const VkPhysicalDeviceFeratures* pEnableFeatures;
    }VkDeviceCrateInfo;

    typedef struct VkDeviceQueueCreateInfo{
        VkStuctureType  sType;
        const void*     pNext;
        VkDeviceQueueCreateFlags  flags;
        uint32_t    queueFamilyIndex;
        uint32_t    queueCount;
        const float*    pQueuePriorities;
    }VkDeviceQueueCreateInfo;

    //层
    //查询可用的层
    VkResult vkEnumerateInstanceLayerProperties(
        uint32_t*   pPropertyCount,
        VkLayerProperties* pProperties
    );

    VkResult vkEnumerateInstanceLayerProperties(
        VkPhysicalDevice    physicalDevice,
        uint32_t*   pPropertyCount,
        VkLayerProperties* pProperties
    );


    typedef struct VkLayerProperties
    {
        /* data */
        char layerName[VK_MAX_EXTENSION_NAME_SIZE];
        uint32_t specVersion;
        uint32_t implementationVersion;
        char description[VK_MAX_DESCRIPTION_SIZE];
    }VklayerProperties;
    

    //扩展
    VkResult vkEnumerateInstanceExtensionProperties(
        const char*     playerName,
        uint32_t*       pPropertyCount,
        VkExtensionProperties*  pProperties
    );

    typedef struct VkExtensionProperties
    {
        /* data */
        char extensionName[VK_MAX_EXTENSION_NAME_SIZE];
        uint32_t specVersion;
    }VkExtensionProperties;
    //查询支持的设备扩展
    VkResult vkEnumerateDeviceExtensionProperties(
        VkPhysical  physicalDevice,
        const char* pLayerName,
        uint32_t*   pPropertyCount,
        VkExtensionProperties* pProperties);

    VKAPI_ATTR void VKAPI_CALL vkVoidFunction(void);

    PFN_vkVoidFunction vkGetInstanceProcAddr(
        VkInstance         instance,
        const char*         pName
    );

    PFN_vkVoidFunction vlGetDeviceProAddr(
        VkDevice    deivce,
        const char* pName
    );
    
    //关闭程序
    VkResult vkDeviceWaitIdle(VkDevice device);

    void vkDestroyDevice(
        VkDevice deivce,
        const VkAllocationCallbacks* pAllocator
    );

    void vkDestoryInstance(
        VkInstance instance,
        const VkAllocationCallbacks* pAllocator
    );


    //VkAllocationCallbacks
    typedef struct  VkAllocationCallbacks
    {
        void*   pUserData;
        PFN_vkAllocationFunction    pfnAllocation;
        PFN_vkReallocationFunction  pfnReallocation;
        PFN_vkFreeFunction         pfnFree;
        PFN_vkInternalAllocationNotification    pfnInternalAllocation;
        PFN_vkInternalFreeNotification    pfnInternalFree;
        /* data */
    }VkAllocationCallbacks;
    

    void* VKAPI_CALL Allocation(
        void*   pUserData;
        size_t  size,
        size_t  alignment,
        VkSystemAllocationScope allocationScope);

    void* VKAPI_CALL Reallocation(
        void*   pUserData,
        void*   pOriginal,
        size_t  size,
        size_t  alignment,
        VkSystemAllocationScope allocationScope
    );

    void* VKAPI_CALL Free(
        void* pUserData,
        void* pMemory
    );
    void* VKAPI_CALL InternalAllocationNotification(
        void*   pUserData,
        size_t  size,
        VkInternalAllocationType allcationType,
        VkSystemAllocationScope allcationScope
    );
    void* VKAPI_CALL InternalFreeNotification(
        void*   pUserData,
        size_t size,
        VkInternalAllocationType allocationType,
        VkSystemAllocationScope allcationScope
    );
    return 0

    //缓冲区
    VkReslut vkCreateBuffer(
        VkDevice device,
        const VkBufferCreateInfo* pCreatInfo,
        const VkAllocationCallbacks* pAllocator,
        VkBuffer* pBuffer
    );

    typedef struct VkBufferCreateInfo {
        VkStructureType     sType;
        const void* pNext;
        VkBufferCreateFlags flags;
        VkDeviceSize size;
        VkBufferUsageFlags usage;
        VkSharingMode sharingMode;
        uint32_t queueFamilyIndexCount;
        const uint32_t* pQueueFamilyIndicesl
    }VkBufferCreateInfo;
    //查询格式
    void VkGetPhysicalDeviceFormatProperties(
        VkPhysicalDevice physicalDevice,
        VkFormat format,
        VkFormatProperties* pFormatProperties
    );

    typedef struct VkFormatProperties{
        VkFormateFeatureFlags linearTilingFeatures;
        VkFormateFeatureFlags optimalTilingFeatures;
        VkFormateFeatureFlags bufferFeatures;
    }VkFormatProperties;

    //获取更多格式信息
    VkResult vkGetPhysicalDeviceImageFormatProperties(
        VkPhysicalDevice physicalDevice,
        VkFormat format,
        VkImageType type,
        VkImageTiling tiling,
        VkImageUsageFlags usage,
        VkImageCreateFlags flags,
        VkImageFormatProperties* pImageFormatProperties
    );

    typedef struct VkImageFormatProperties {
        VkExten3D maxExtent;
        uint32_t maxMipLevels;
        uint32_t maxArrayLayers;
        VkSampleCountFlags sampleCounts;
        VkDeviceSize maxResoureSize;
    }VkImageFormatProperties;

    typedef struct VkExtent3D{
        uint32_t width;
        uint32_t height;
        uint32_t depth;
    }VkExtent3D;

    //图像
    VkResult vkCreateImage(
        VkDevice device,
        const VkImageCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocatpr,
        VkImage*    pImage
    );

    typedef struct VkImageCreateInfo {
        VkStructureType sType;
        const void* pNext;
        VkImageCreateFlags flags;
        VkImageType imageType;
        VkFormat format;
        VkExtent3D extent;
        uint32_t mipLevels;
        uint32_t arrayLayers;
        VkSampleCountFlagBits samples;
        VkImageTiling tilingl
        VkImageUsageFlags usage;
        VkSharingMode sharingMode;
        uint32_t queueFamilyIndexCount;
        const uint32_t* pQueueFamilyIndices;
        VkImageLayout initialLayout;
    }VkImageCreateInfo;
}



