

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


    //线性图像
    void vkGetImageSubresourceLayout(
        VkDevice    device,
        VkImage     image,
        const VkIamgeSubresource* pSubresource,
        VkSubresourceLayout*    pLayout
    );

    typedef struct VkImageSubresource{
        VkImageAspectFlags aspectMask;
        uint32_t mipLevel;
        uint32_t arrayLayer;
    }VkImageSubresource;

    typedef struct VkSubresourceLayout {
        VkDeviceSize offset;
        VkDeviceSize size;
        VkDeviceSize rowPitch;
        VkDeviceSize arrayPitch;
        VkDeviceSize depthPitch;
    }VkSubresoureLayout;


    //资源视图

    VkResult vkCreateBufferView(
        VkDevice device,
        const VkBufferViewCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkBufferView* pView
    );

    typedef struct VkBufferViewCreateInfo {
        VkStructureType sType;
        const void* pNext;
        VkBufferViewCreateFlags flags;
        VkBuffer buffer;
        VkFormat format;
        VkDeviceSize offset;
        VkDeviceSize range;
    }VkBufferViewCreateInfo;

    // 图像视图
    VkResult vkCreateImageView(
        VkDevice device,
        const VkImageViewCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkImageView* pView
    );

    typedef struct VkImageViewCreateInfo{
        VkStructType sType;
        const void* pNext;
        VkImageViewCreateFlags flags;
        VkImage image;
        VkImageViewType viewType;
        VkFormat format;
        VkComponentMapping components;
        VkImageSubresourceRange subresourceRange;
    }VkImageViewCreateInfo;

    typedef struct VkComponentMapping{
        VkComponentSwizzle r;
        VkComponentSwizzle g;
        VkComponentSwizzle b;
        VkComponentSwizzle a;
    }VkComponentMapping;

    typedef struct VkImageSubresourceRange{
        VkImageAspectFlags aspectMask;
        uint32_t baseMipLevel;
        uint32_t levelCount;
        uint32_t baseArrayLayer;
        uint32_t layerCount;
    }VkImageSubresourceRange;

    //销毁资源
    void vkDestroyBuffer(
        VkDevice device,
        VkBuffer buffer,
        const VkAllocationCallbacks* pAllocator
    );

    void vkDestroyBufferView(
        VkDevice device,
        VkBufferView bufferView,
        const VkAllocationCallbacks* pAllocator
    );

    void vkDestroyImage(
        VkDevice device,
        VkImage image,
        const VkAllocationCallbacks* pAllocator
    );

    void vkDestroyImageView(
        VkDevice device,
        VkImageView imageView,
        const VkAllocationCallbacks* pAllocator
    );

    //设备内存管理
    VkResult vkAllocateMemory(
        VkDevice device,
        const VkMemoryAllocateInfo* pAllocateInfo,
        const VkAllocationCallbacks pAllocator,
        VkDeviceMemory* pMemory
    );

    typedef struct VkMemoryAllocateInfo{
        VkStructureType sType;
        const void* pNext;
        VkDeviceSize allocationSize;
        uint32_t memoryTypeIndex;
    }VkMemoryAllocateInfo;

    void vkFreeMemory(
        VkDevice device,
        VkDeviceMemory memory,
        const VkAllocationCallbacks* pAllocator
    );

    void vkGetDeviceMemoryCommitment(
        VkDevice device,
        VkDeviceMemory memory,
        VkDeviceSize* pCommittedMemoryInBytes
    );

    //CPU访问设备内存
    VkResult vkMapMemory(
        VkDevice device,
        VkDeviceMemory memory,
        VkDeviceSize offest,
        VkDeviceSize size,
        VkMemoryMapFlags flags,
        void** ppData
    );

    //解除映射
    void vkUnmapMemory(
        VkDevice device,
        VkDeviceMemory memory
    );
    //刷新缓存
    vkFlushMappedMemoryRanges(
        VkDevice device,
        uint32_t memoryRangeCount,
        const VkMappedMemoryRange* pMemoryRanges
    );

    typedef struct VkMappedMemoryRange{
        VkStructureType sType;
        const void* pNext;
        VkDeviceMemory memory;
        VkDevice offest;
        VkDevice size;
    }VkMappedMemoryRnage;

    VkResult vkInvalidateMappedMemoryRanges(
        VkDevice device,
        uint32_t memoryRangeCount,
        const VkMappedMemoryRange* pMemoryRanges
    );

    //绑定内存到资源
    void vkGetBufferMemoryRequirements(
        VkDevice device,
        VkBuffer buffer,
        VkMemoryRequirements* pMemoryRequirements
    );

    void vkGetImageMemoryRequirements(
        VkDevice device,
        VkImage image,
        VkMemoryRequirements* pMemoryRequirements
    );

    void vkGetBufferMemoryRequirements(
        VkDevice devcie,
        VkBuffer buffer,
        VkMemoryRequirements* pMemoryRequirements
    );

    void vkGetBufferMemoryRequirements(
        VkDevice devcie,
        VkImage image,
        VkMemoryRequirements* pMemoryRequirements
    );

    typedef struct VkMemoryRequirements{
        VkDeviceSize size;
        VkDeviceSize alignment;
        uint32_t memoryTypeBits;
    }VkMemoryRequirements;

    //队列参数
    typedef struct VkDeviceQueueCreateInfo{
        VkStructureType sType;
        const void*     pNext;
        VkDeviceQueueCreateFlags flags;
        uint32_t  queueFamilyIndex;
        uint32_t  queueCountl
        const float* pQueuePriorites;
    }VkDeviceQueueCreateInfo;

    void vkGetDeviceQueue(
        VkDevice device,
        uint32_t queueFamilyIndex,
        uint32_t queueIndex,
        VkQueue* pQueue
    );
    
    //创建命令缓冲区
    VkResult VkCreateCommandPool(
        VkDevice device,
        const VkCommandPoolCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkCommandPool* pCommandPool
    );

    typedef struct VkCommandBufferAllocateInfo{
        VkStructureType sType,
        const void*     pNext;
        VkCommandPoolCreateFlags flags;
        uint32_t    queueFamilyIndex;
    }VkCommandBufferAllocateInfo;
    //分配新的缓冲区
    VkResult VkAllocateCommandBuffers(
        VkDevice device,
        const VkCommandBufferAllocateInfo* pAllocateInfo,
        VkCommandBuffer*    pCommandBuffers
    );

    typedef struct VkCommandBuffer{
        VkStrctureType sType;
        const void* pNext;
        VkCommandPool pool;
        VkCommandBufferLevel level;
        uint32_t commandBufferCount;
    }VkCommandBuffer;

    //释放命令缓冲区
    void VkFreeCommandBuffers(
        VkDevice device,
        VkCommandPool commandPool,
        uint32_t commandBufferCount,
        const VkCommandBuffer* pCommandBuffers
    );

    //释放命令缓冲区所有资源
    void VkDestroyCommandPool(
        VkDevice device,
        VkCommangPool commandPool,
        const VkAllocationCallbacks* pAllocator
    );


    //记录命令
    VkResult VkBeginCommandBuffer (
        VkCommandBuffer     commandBuffer,
        const VkCommandBufferBeginInfo* pBeginInfo
    );

    typedef struct VkEndCommandBufferInfo{
        VkStructureType sType;
        const void*     pNext;
        VkCommandBufferUsageFlags flags;
        const VkCommandBufferInheritanceInfo* pInheritanceInfo;
    }VkCommandBufferBeginInfo;

    //在缓冲区间复制数据

    void VkCmdCopyBuffer(
        VkCommandBuffer     commandBuffer,
        VkBuffer            srcBuffer,
        VkBuffer            dstBuffer,
        uint32_t            regionCount,
        const VkBufferCopy* pRegions
    );

    typedef struct VkBuffer{
        VkDeviceSize srcOffset;
        VkDeviceSize dstOffset;
        VkDeviceSize size;
    }VkBufferCopy;

    //发送命令给设备
    VkResult VkEndCommandBuffer(VkCommandBuffer commandBuffer);

    //回收利用命令缓冲区
    VkResult VkResetCommandBuffer(VkCommandBuffer commandBuffer,VkCommandBufferResetFlags flags);

    //一次性重置命令缓冲区
    VkResult VkResetCommandPool(VkDevice device,VkCommandPool commandPool,VkCommandPoolResetFlags flags);

    //命令提交给队列
    VkResult VkQueueSubmit(
        VkQueue     queue,
        uint32_t    submitCount,
        const VkSubmitInfo* pSubmits,
        VkFence     fence
    );

    typedef struct VkSubmitInfo{
        VkStuctureType  sType;
        const void*     pNext;
        uint32_t        waitSemaphoreCount;
        const VkSemaphore* pWaitSemaphores;
        const VkPipelineStageFlags* pWaitDstStageMask;
        uint32_t        commandBufferCount;
        const VkCommandBuffer* pCommandBuffers;
        uint32_t    signalSemaphoreCount;
        const VkSemaphore*  pSignalSemaphores;
    }VkSubmitInfo;

    VkResult VkQueueWaitIdle(VkQueue queue);

    VkResult VkDeviceWaitIdle(VkDevice device);
    //管线屏障
    //同步和改变状态的主要命令
    void vkCmdPiplineBarrier(
        VkCommandBufer commandBuffer,
        VkPipelineStageFlags srcStageMask,
        VkPipelineStageFlags dstStageMask,
        VkDependencyFlags   dependencyFlags,
        uint32_t memoryBarrierCount,
        uint32_t bufferMemoryBarrierCount,
        const VkBufferMemoryBarrier* pBufferMemoryBarriers,
        uint32_t imageMemoryBarrierCount,
        const VkImageMemoryBarrier* pImageMemoryBarriers
    );

    //全局内存屏障
    typedef struct VkMemoryBarrier{
        VkStructureType sType;
        const void* pNext;
        VkAccessFlags srcAccessMask;
        VkAccessFlags dstAccessMask;
    }VkMemoryBarrier;

    //缓冲区内存屏障
    typedef struct VkBufferMemoryBarrier{
        VkStructureType sType;
        const void* pNext;
        VkAccessFlags srcAccessMask;
        VkAccessFlags dstAccessMask;
        uint32_t srcQueueFamilyIndex;
        uint32_t dstQueueFamilyIndex;
        VkBuffer buffer;
        VkDeviceSize offest;
        VkDeviceSize size;   
    }VkBufferMemoryBarrier;

    //图像内存屏障
    typedef struct VkImageMemoryBarrier{
        VkStructureType sType;
        const void*     pNext;
        VkAccessFlags   scrAccessMask;
        VkAccessFlags   dsrAccessMask;
        VkImageLayout   oldLayout;
        VkImageLayout   newLayout;
        uint32_t        srcQueueFamilyIndex;
        uint32_t        dsrQueueFamilyIndex;
        VkImage         image;
        VkImageSubresourceRange subresourceRange;
    }VkImageMemoryBarrier;

    //清除和填充缓冲区
    //填入缓冲区
    void vkCmdFillBuffer(
        VkCommandBuffer commandBuffer,
        VkBuffer dstBuffer,
        VkDeviceSize dstOffset,
        VkDeviceSize size,
        uint32_t    data
    );
    
    //把数据放入缓冲区对象
    vkCmdUpdateBuffer(
        VkCommandBuffer commandBuffer,
        VkBuffer dstBuffer,
        VkDeviceSize dstOffest,
        VkDeviceSize dataSize,
        const uint32_t* pData
    );
    
    //清空和填充图像
    void vkCmdClearColorImage(
        VkCommandBuffer commandBuffer,
        VkImage image,
        VkImageLayout imageLayout,
        const VkClearColorValue* pColor,
        uint32_t rangeCount,
        const VkImageSubresourceRange* pRanges
    );

    typedef union VkClearColorValue{
        float float32[4];
        int32_t int32[4];
        uint32_t uint32_t;
    }VkClearColorValue;

    typedef struct VkImageSubresourceRange{
        VkImageAspectFlags aspectMask;
        uint32_t    baseMipLevel;
        uint32_t    levelCount;
        uint32_t    baseArrayLayer;
        uint32_t    layerCount;
    }VkImageSubresouceRange;

    //清除深度-模板图像
    void vkCmdClearDepthStencilImage(
        VkCommandBuffer     commandBuffer,
        VkImage               image,
        VkImageLayout         imageLayout,
        const VkClearDepthStencilValue* pDepthStencil,
        uint32_t                rangeCount,
        const VkImageSubresourceRange* pRanges
    );

    typedef struct VkClearDepthStenciValue{
        float depth;
        uint32_t stencil;
    }VkClearDepthStenciValue;

    //复制图片数据
    void vkCmdCopyBufferToImage(
        VkCommandBuffer commandBuffer,
        VkBuffer srcBuffer,
        VkImage dstImage,
        VkImageLayout dstImageLayout,
        uint32_t regionCount,
        const VkBufferImageCopy* pRegions
    );

    typedef struct VkBufferImageCopy{
        VkDeviceSize bufferOffset;
        uint32_t    bufferRowLength;
        uint32_t    bufferImageLength;
        VkImageSubresourceLayers imageSubresource;
        VkOffset3D      imageOffset;
        VkExtent3D      imageExtent;
    }VkBufferImageCopy;

    typedef struct VkImageSubersourceLayers{
        VkImageAspectFlags  aspectMask;
        uint32_t    mipLevel;
        uint32_t    baseArrayLayer;
        uint32_t    layerCount;
    }VkImageSubresourceLayers;

    //从图像复制到缓冲区
    void vkCmdCopyImageToBuffer(
        VkCommandBuffer     commandBuffer,
        VkImage             srcImage,
        VkImageLayout       srcImageLayout,
        VkBuffer            dstBuffer,
        uint32_t                regionCount,
        const VkBufferImageCopy* pRegions
    );

    //图像之间复制
    void vkCmdCopyImage(
        VkCommandBuffer commandBuffer,
        VkImage srcImage,
        VkImageLayout srcImageLayout,
        VkImage dstImage,
        VkImageLayout dstImageLayout,
        uint32_t regionCount,
        const VkImageCopy* pRegions
    );

    typedef struct VkImageCopy {
        VkImageSubresourceLayers srcSubresource;
        VkOffset3D  srcOffset;
        VkImageSubresourceLayers dstSubresource;
        VkOffset3D  dstOffset;
        VkExtent3D  extent;
    }VkImageCopy;

    //拉伸图像
    void vkCmdBlitImage(
        VkCommandBuffer commandBuffer,
        VkImage srcImage,
        VkImageLayout srcImageLayout,
        VkImage dstImage,
        VkImageLayout dstImageLayout,
        unit32_t regionCount,
        const VkImageBlit* pRegions,
        VkFilter filter
    );

    typedef struct VkImageBlit {
        VkImageSubresourceLayers srcSubresource;
        VkOffset3D      srcOffset[2];
        VkImageSubresourceLayers dstSubresource;
        VkOffset3D      dstOffset[2];
    }VkImageBlit;
    //在windows展现
    //判断队列是否支持展示操作
    VkBool32 vkGetPhysicalDeviceWin32PresentationSupportKHR(
        VkPhysicalDevice    physicalDevice,
        uint32_t                queueFamilyIndex
    );
    //创建表面
    VkResult vkCreateWin32SurfaceKHR(
        VkInstance instance,
        const VkWin32SurfaceCreateInfoKHR* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkSurfaceKHR* pSurface
    );

    typedef struct VkWin32SurfaceCreateInfoKHR {
        VkStructure Type    sType;
        const void*         pNext;
        VkWin32SurfaceCreateFlagsKHR flags;
        HINSTANCE           hinstance;
        HWND              hwnd;
    }VkWin32SurfaceCreateInfoKHR;

    //在Xlib平台展示
    VkBool32 vkGetPhysicalDeviceXlibPresentationSupportKHR(
        VkPhysicalDevice    physicalDevice,
        uint32_t            queueFamilyIndex,
        Display*            dpy,
        VisualID            visualID
    );

    VkResult vkCreateXlibSurfaceKHR(
        VkInstance instance,
        const VkXlibSurfaceCreateInfoKHR* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkSurfaceKHR* pSurface
    );

    typedef struct VkXlibSurfaceCreateInfoKHR{
        VkStructureType sType;
        const void* pNext;
        VkXlibSurfaceCreateFlagsKHR flags;
        Display dpy;
        Window  window;
    }VkXlibSurfaceCreateInfoKHR;

    //在xcb上展示
    VkBool32 vkGetPhysicalDeviceXcbPresentationSupportKHR(
        VkPhysicalDevice physicalDevice,
        uint32_t queueFamilyIndex,
        xcb_connection_t* connection,
        xcb_visualid_t  visual_id
    );

    VkReslut vkCreateXcbSurfaceKHR(
        VkInstance instance,
        const VkXcbSurfaceCreateInfoKHR* pCreateInfo,
        const VkAllocationCallbacks*     pAllocator,
        VkSurfaceKHR* pSurface
    );

    typedef struct VbXcbSurfaceCreateInfoKHR{
        VkStructureType sType;
        const void*     pNext;
        VkXcbSurfaceCrateFlagsKHR flags;
        xcb_connection_t*   connection;
        xcb_window_t        window;
    }VkXcbSurfaceCreateInfoKHR;

    //交换链
    VkResult vkCreateSwapchainKHR(
        VkDevice device,
        const VkSwapchainCreateInfoKHR* pCreateInfo,
        const VkAllocationCallbacks*    pAllocator,
        VkSwapchainKHR* pSwapchain
    );

    typedef struct VkSwapchainCreateInfoKHR{
        VkStructureType sType,
        const void*     pNext,
        VkSwapchainCreateFlagsKHR flags,
        VkSurfaceKHR    surface,
        uint32_t    minImageCount,
        VkFormat    imageFormat,
        VkColorSpaceKHR imageColorSpace,
        VkExtent2D  imageExtent,
        uint32_t    imageArrayLayers,
        VkImageUsageFlags   imageUsage,
        VkSharingMode   imageSharingMode,
        uint32_t        queueFamilyIndexCount,
        const uint32_t* pQueueFamilyIndices,
        VkSurfaceTransformFlagBitsKHR   perTransform;
        VkCompositeAlphaFlagBitsKHR     compositeAlpha;
        VkPresentModeKHR                resentMode;
        VkBool32                        clipped;
        VkSwapchainKHR                  oldSwapchain;
    }VkSwapchainCreateInfoKHR;

    VkResult vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
        VkPhysicalDevice    physicalDevice,
        VkSurfaceKHR        surface,
        VkSurfaceCapabilitiesKHR    pSurfaceCapabilities
    );

    typedef struct VkSurfaceCapabilitiesKHR{
        uint32_t    minImageCount;
        uint32_t    maxImageCount;
        VkExtent2D  currentExtent;
        VkExtent2D  minImageExtent;
        VkExtent2D  maxImageExtent;
        uint32_t    maxImageArrayLayers;
        VkSurfaceTransformFlagsKHR supportedTransforms;
        VkSurfaceTransformFlagsBitsKHR  currentTransform;
        VkCompositeAlphaFlagsKHR        supportedCompositeAlpha;
        VkImageUsageFlags               supportedUsageFlags;
    }VkSurfaceCapabilitiesKHR;
    //获取图像局部
    VkResult vkGetSwapchainImagesKHR(
        VkDevice device,
        VkSwapchainKHR swapChain,
        uint32_t*   pSwapchainImageCount,
        VkImage*    pSwapchainImages
    );


    VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceFormatsKHR(
        VkPhysicalDevice    physicalDevice,
        VkSurfaceKHR        surface,
        uint32_t*           pSurfaceFormatCount,
        VkSurfaceFormatKHR* pSurfaceFormats
    );

    typedef struct VkSurfaceFormatKHR{
        VkFormat    format;
        VkColorSpaceKHR colorSpace;
    }VkSurfaceFormatKHR;
    //获取下一图像
    VkResult vkAcquireNextImageKHR(
        VkDevice    device,
        VkSwapchainKHR swapChain,
        uint64_t timeout,
        VkSemaphore semaphore,
        VkFence fence,
        uint32_t* pImageIndex
    );

    //全屏表面
    VkResult vkGetPhysicalDeviceDisplayPropertiesKHR(
        VkPhysicalDevice physicalDevice,
        uint32_t*   pPropertyCount,
        VkDisplayPropertiesKHR* pProperties
    );

    typedef struct VkDisplayPropertiesKHR {
        VkDisplayKHR display;
        const char* displayName;
        VkExtent2D  physicalDimensions;
        VkExtent2D  physicalResolution;
        VkSurfaceTransformFlagsKHR supportedTransforms;
        VkBool32 planeReordePossible;
        VkBool32 presistentContent;
    }VkDisplayPropertiesKHR;

    //查询设备支持的平面个数和类型
    VkResult vkGetPhysicalDeviceDisplayPlanePropertiesKHR(
        VkPhysicalDevice physicalDevice,
        uint32_t*   pPropertyCount,
        VkDisplayPlanePropertiesKHR* pProperties
    );

    typedef struct VkDisplayPlanePropertiesKHR {
        VkDisplayKHR currentDisplay,
        uint32_t currentStackIndex;
    }VkDisplayPlanePropertiesKHR;

    //获知哪个显示设备对平面可见
    VkResult vkGetDisplayPlaneSupportedDisplaysKHR(
        VkPhysical physicalDevice,
        uint32_t   planeIndex,
        uint32_t   pDisplayCount,
        VkDisplayKHR* pDisplays
    );

    //查询屏幕属性
    VkResult vkGetDisplayPlaneCapabilitiesKHR(
        VkPhysical physicalDevice,
        VkDisplayModeKHR mode,
        uint32_t  planeIndex,
        VkDisplayPlaneCapabilitiesKHR* pCapabilities
    );

    typedef struct VkDisplayPlaneCapabilitiesKHR {
        VkDisplayPlaneAlphaFlagsKHR     supportedAlpha;
        VkOffset2D                      minSrcPosition;
        VkOffset2D                      maxSrcPosition;
        VkExtent2D                      minSrcExtent;
        VkExtent2D                      maxSrcExtent;
        VkOffset2D                      minDstPosition;
        VkOffset2D                      maxDstPosition;
        VkExtent2D                      minDstExtent;
        VkExtent2D                      maxDstExtent;
    }VkDisplayPlaneCapabilitiesKHR;

    //获取每一个显示器预定义的显示模式
    VkResult vkGetDisplayModePropertiesKHR(
        VkPhysicalDevice    physicalDevice,
        VkDisplayKHR        display,
        uint32_t            pPropertyCount,
        VkDisplayModePropertiesKHR* pProperties
    );

    typedef struct VkDisplayModePropertiesKHR{
        VkDisplayModeKHR    displayMode;
        VkDisplayModeParametersKHR parameters;
    }VkDisplayModePropertiesKHR;


    typedef struct VkDisplayModeParmetersKHR {
        VkExtent2D  visibleRegion;
        uint32_t    refreshRate;
    }VkDisplayModeParmetersKHR;


    //创建新的显示模式
    VkResult vkCreateDisplayModeKHR(
        VkPhysicalDevice physicalDevice,
        VkDisplayKHR     display,
        const VkDisplayModeCreateInfoKHR* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkDisplayModeKHR*    pMode
    );

    typedef struct VkDisplayModeCreateInfoKHR {
        VkStuctureType sType;
        const void*     pNext;
        VkDisplayModeCreateFlagsKHR flags;
        VkDisplayModeParametersKHR modeParameters;
    }VkDisplayModeCreateInfoKHR;

    //指代窗口表面使用它
    VkResult vkCreateDisplayPlaneSurfaceKHR(
        VkInstance instance,
        const VkDisplaySurfaceCreateInfoKHR* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkSurfaceKHR* pSurface
    );

    typedef struct VkDisplaySurfaceCreateInfoKHR {
        VkStructureType sType;
        const void*     pNext;
        VkDisplaySurfaceCreateFlagsKHR flags;
        VkDisplayModeKHR               displayMode;
        uint32_t        planeIndex;
        uint32_t        planeStackIndex;
        VkSurfaceTransformFlagBitsKHR   transform;
        float           globalAlpha;
        VkDisplayPlaneAlphaFlagBitsKHR  alphaMode;
        VkExtent2D      imageExtent;
    }VkDisplaySurfaceCreateInfoKHR; 

    //执行展示
    //查询队列是否可以展示
    VkResult vkGetPhysicalDeviceSurfaceSupportKHR(
        VkPhysicalDevice physicalDevice,
        uint32_t        queueFamilyIndex,
        VkSurfaceKHR     surface,
        VkBool32*        pSupported
    );
    //提交到队列
    VkResult vkQueuePresentKHR(
        VkQueue     queue,
        const VkPresentInfoKHR* pPresentInfo
    );

    typedef struct VkPresentInfoKHR{
        VkSturctureType     sType;
        const void*         pNext;
        uint32_t            waitSemaphoreCount;
        const VkSemaphore*  pWaitSemphores;
        uint32_t            swapChainCount;
        const VkSwapchainKHR*   pSwapchains;
        const uint32_t*         pImageIndices;
        VkResult*               pResults;
    }VkPresentInfoKHR;
    //清除
    //销毁交换链
    void vkDestroySwapchainKHR(
        VkDevice device,
        VkSwapchainKHR swapchain,
        const VkAllocationCallbacks* pAllocator
    );

    //创建着色器对象模块
    VkResult vkCreateShaderModule(
        VkDevice device,
        const VkShaderModuleCreateInfo* pCreateInfo,
        const VkAllocationCallbacks*    pAllocator,
        VkShaderModule*                 pShaderModule
    );

    typedef struct VkShaderModuleCreateInfo {
        VkStructureType sType;
        const void*     pNext;
        VkShaderModuleCreateFlags flags;
        size_t codeSize;
        const uint32_t* pCode;
    }VkShaderModuleCreateInfo;

    //销毁释放资源
    void vkDestroyShaderModule(
        VkDevice device,
        VkShaderModule shaderModule,
        const VkAllocationCallbacks* pAllocator
    );
    //创建管线
    VkResult vkCreateComputePipelines(
        VkDevice device,
        VkPipelineCache pipelineCache,
        uint32_t    createInfoCount,
        const VkComputePipelineCreateInfo* pCreateInfo,
        const VkAllocationCallbacks*    pAllocator,
        VkPipeline*     pPipelines
    );
    typedef struct VkComputePipelineCreateInfo {
        VkStructureType sType;
        const void* pNext;
        VkPipelineCreateFlags flags;
        VkPipelineLayout    layout;
        VkPipeline      basePipelineHandle;
        int32_t         basePipelineIndex;
    }VkComputePipelineCreateInfo;

    typedef struct VkPipelineShaderStageCreateInfo{
        VkStructureType     sType;
        const void*         pNext;
        VkPipelineShaderStageCreateFlags flags;
        VkShaderStageFlagBits       stage;
        VkShaderModule          module;
        const char*             pName;
        const VkSpecializationInfo*     pSpecializationInfo;
    }VkPipelineShaderStageCreateInfo;

    typedef struct VkSpecializationInfo {
        uint32_t     mapEntryCount;
        const VkSpecializationMapEntry* pMapEntries;
        size_t dataSize;
        const void* pData;
    }VkSpecializationInfo;

    typedef struct VkSpecializationMapEntry {
        uint32_t constantID;
        uint32_t offset;
        size_t size;
    }VkSpecializationMapEntry;

    //销毁管线
    void vkDestroyPipeline(
        VkDevice device,
        VkPipeline  pipeline
        const VkAllocationCallbacks* pAllocator
    );

    //加速管线
    //管线缓存
    VkResult vkCreatePipelineCache(
        VkDevice device,
        const VkPipelineCacheCreateInfo* pCreateInfo,
        const VkAllocationCallbacks*    pAllocator,
        VkPipelineCache*        pPipelineCache
    );

    typedef struct VkPipelineCacheCreateInfo {
        VkStructureType sType;
        const void* pNext;
        VkPipelineCacheCreateFlags flags;
        size_t  initalDataSize;
        const void* pInitalData;        
    }VkPipelineCacheCreateInfo;

    //从缓存中取出数据
    VkResult vkGetPipelineCacheData (
        VkDevice device,
        VkPipelineCache pipelinecache,
        size_t* pDataSize,
        void*   pData
    );

    //缓存头部布局
    typedef struct VkPipelineCacheHeader {
        uint32_t length;
        uint32_t version;
        uint32_t verdorID;
        uint32_t deviceID;
        uint32_t uuid[16];
    }VkPipelineCacheHeader;

    //合并缓存对象
    VkResult vkMergePipelineCaches(
        VkDevice device,
        VkPipelineCache dstCache,
        uint32_t srcCacheCount,
        const VkPipelineCache*  pSrcCaches
    );
    //销毁
    void vkDestoryPipelineCache(
        VkDevice device,
        VkPipelineCache pipelineCache,
        const VkAllocationCallbacks* pAllocator
    );

    //绑定管线
    void vkCmdBindPipeline(
        VkCommandBuffer commandBuffer,
        VkPipelineBindPoint pipelineBindPoint,
        VkPipeline pipeline
    );
    //执行工作
    //使用计算管线分发全局工作组
    void vkCmdDispatch(
        VkCommandBuffer buffer,
        uint32_t x,
        uint32_t y,
        uint32_t z
    );

    //间接分发
    void vkCmdDispatchIndirect(
        VkCommandBuffer commandBuffer,
        VkBuffer buffer,
        VkDeviceSize offset
    );

    typedef struct VkDispatchIndirectCommand{
        uint32_t x;
        uint32_t y;
        uint32_t z;
    }VkDispatchIndirectCommand;
    //描述符集
    //创建描述符集
    VkResult vkCreateDescriptorSetLayout(
        VkDevice device,
        const VkDescriptorSetLayoutCreateInfo* pCreateInfo,
        const VkAllocationCallbacks*           pAllocator,
        VkDescriptorSetLayout*                 pSetLayout
    );

    typedef struct VkDescriptorSetLayoutCreateInfo {
        VkStructureType     sType;
        const void*         pNext;
        VkDescriptorSetLayoutCreateFlags flags;
        uint32_t            bindingCount;
        const VkDescriptorSetLayoutBinding* pBindings;
    }VkDescriptorSetLayoutCreateInfo;

    typedef struct VkDescriptorSetLayoutBinding {
        uint32_t binding;
        VkDescriptorType descriptorType;
        uint32_t descriptorCount;
        VkShaderStageFlags stageFlags;
        const*  VkSampler* pImmutableSmaplers;
    }VkDescriptorSetLayoutBinding;

    //将描述集打包到管线中
    VkResult vkCreatePipelineLayout(
        VkDevice device,
        const VkPipelineLayoutCreateInfo* pCreateInfo,
        const VkAllocatioCallbacks* pAllocator,
        VkPipelineLayout*   pPipelineLayout
    );

    typedef struct VkPipelineLayoutCreateInfo{
        VkStructureType sType;
        const void* pNext;
        VkPipelineLayoutCreateFlags flags;
        uint32_t    setLayoutCount;
        const VkDescriptorSetLayout*    pSetLayouts;
        uint32t pushConstantRangCount;
        const VkPushConstantRange*  pPushConstantRanges;
    }VkPipelineLayoutCreateInfo;
    //销毁管线布局对象
    void vkDestroyPipelineLayout(
        VkDevice device,
        VkPipelineLayout pipelineLayout,
        const VkAllocationCallbacks* pAllocator
    );
    //销毁描述符集布局对象
    void vkDestroyDescriptorSetLayout(
        VkDevice device,
        VkDescriptorSetLayout descriptorSetLayout,
        const VkAllocationCallbacks* pAllocator
    );
    //绑定资源到描述符集
    //创建描述符集缓冲区
    VkResult vkCreateDescriptorPool(
        VkDevice device,
        const VkDescriprotPoolCreateInfo*   pCreate,
        const VkAllocationCallbacks* pAllocator,
        VkDescriptorPool*   pDescriptorPool
    );

    typedef struct VkDescripotrPoolCreateInfo{
        VkStructureType sType;
        const void*     pNext;
        VkDescriptorPoolCreateFlags flags;
        uint32_t maxSets;
        unit32_t poolSizeCount;
        const VkDescriptorPoolSize* pPoolSize;
    }VkDescriptorPoolInfo;

    typedef struct VkDescriptorPoolSize{
        VkDescriptorType type;
        uint32_t    descriptorCount;
    }VkDescriptorPoolSize;
    //创建对象
    VkResult vkAllocateDescriptorSets(
        VkDevice device,
        const VkDescriptorSetAllocateInfo* pAllocateInfo,
        VkDescriptorSet*    pDescriptorSets
    );

    typedef struct VkDescriptorSetAllocateInfo {
        VkStructureType sType;
        const void* pNext;
        VkDescriptorPool descriptorPool;
        uint32_t descriptorSetCount;
        const VkDescriptorSetLayout* pSetLayouts;
    }VkDescriptorSetAllocateInfo;

    //释放描述集符
    VkResult vkFreeDescriptorSets(
        VkDevice device,
        VkDescriptorPool descriptorPool,
        uint32_t descriptorSetCount,
        const VkDescriptorSet*  pDescriptorSets
    );
    //重置缓冲池
    VkResult vkResetDescriptorPool(
        VkDevice device,
        VkDescriptorPool descriptorPool,
        VkDescriptorResetFlags flags
    );
    //销毁对象
    void DestroyDescriptorPool(
        VkDevice deivce,
        VkDescriptorPool descriptorPool,
        const VkAllocationCallbacks pAllocator
    );
    //复制或写入字符集
    void vkUpdeteDescriptorSets(
        VkDevice device,
        uint32_t descriptorWriteCount,
        const VkWriteDwscriptorSet* pDescriptorWrites;
        uint32_t    descriptorCopyCount,
        const VkCopyDescriptorSet*  pDescriptorCopies
    )
    
    typedef struct VkWriteDescriptorSet {
        VkStructureType sType;
        const void*     pNext;
        VkDescriptorSet dstSet;
        unit32_t dstBinding;
        unit32_t dstArrayElement;
        uint32_t descriptorType;
        const VkDescriptorImageInfo*    pImageInfo;
        const VkDescriptorBufferInfo*   pBufferInfo;
        const VkBufferView* pTexelBufferView; 
    }VkWriteDescriptorSet;

    typedef struct VkDescriptorImageInfo{
        VkSampler sampler;
        VkImageView imageView;
        VkImageLayout imageLayout;
    }VkDescriptorImageInfo;

    typedef struct VkDescriptorBufferInfo{
        VkBuffer buffer;
        VkDeviceSize offset;
        VkDeviceSize range;
    }VkDescriptorBufferInfo;

    typedef strucet VkCopyDescriptorSet {
        VkStructureType sType;
        const void* pNext;
        VkDescriptorSet srcSet;
        uint32_t    srcBinding;
        uint32_t    srcArrayElement;
        VkDescriptorSet dstSet;
        uint32_t    dstBinding;
        uint32_t    dstArrayElement;
        uint32_t    descriptorCount;
    }VkCopyDescriptorSet;
    //绑定描述符集到缓冲区
    void vkCmdBindDesriptorSets(
        VkCommandBuffer commanBuffer,
        VkPipelineBinfPoint pipelineBingPoint,
        VkPipelineLayout layout,
        uint32_t firstSet,
        uint32_t descriptorSetCount,
        const VkDescriptorSet* pDescriptorSets,
        uint32_t dynamicOffsetCount,
        const uint32_t* pDynamicOffsets
    );
    //推送常量
    typedef struct VkPushConstantRange{
        VkShaderStageFlags stageFlags;
        uint32_t offset;
        uint32_t size;
    }VkPushConstantRange;
    //更新一个或多个推送常量
    void vkCmdPushConstants(
        VkCommandBuffer commandBuffer,
        VkPipelineLayout layout,
        VkShaderStageFlags stageFlags,
        uint32_t    offset,
        uint32_t    size,
        const void* pValues
    );
    //采样图像
    //绑定采样器
    VkResult vkCreateSampler(
        VkDevice device,
        const VkSamplerCreateInfo*  pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkSampler* pSampler
    );

    typedef struct VkSamplerCreateInfo{
        VkStructType sType;
        const void* pNext;
        VkSamplerCreateFlags flags;
        VkFilter magFilter;
        VkFilter minFilter;
        VkSamplerMipmapMode mipmapMode;
        VkSamplerAddressMode addressModeU;
        VkSamplerAddressMode addressModeV;
        VkSamplerAddressMode addressModeW;
        float mipLodBias;
        VkBool32 anisotropyEnable;
        float maxAnisotropy;
        VkBool32 compareEnable;
        VkCompareOp compareOp;
        float minLod;
        float maxLod;
        VkBorderColor borderColor;
        VkBool32 unnormalizedCoordinates;    
    }VkSamplerCreateInfo;


    //绘制命令
    void vkCmdDraw(
        VkCommandBuffer commandBuffer,
        uint32_t    vertexCount,
        uiny32_t    instanceCount,
        uint32_t    firstIndex,
        uint32_t    firstInstance
    );
    
    //创建渲染通道
    VkResult vkCreateRenderPass(
        VkDevice device,
        const VkRenderPassCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkRenderPass* pRenderPass
    );

    typedef struct VkRenderPassCreateInfo{
        VkStructureType sType;
        const void*     pNext;
        VkRenderPassCreateFlags flags;
        uint32_t    attachmentCount;
        const VkAttachmentDescription* pAttachments;
        uint32_t    subpassCount;
        const VkSubpassDesription* pSubpasses;
        uint32_t    dependencyCount;
        const VkSubpassDependency*  pDependencies;
    }VkRenderPassCreateInfo;

    typedef struct VkAttachmentDescription{
        VkAttachmentDescriptionFlags flags;
        VkFormat format;
        VkSamplerCountFlagBits samples;
        VkAttachmentLoadOp loadOp;
        VkAttachmentStoreOp storeOp;
        VkAttachmentLoadOp  stencilLoadOp;
        VkAttachmentStoreOp  stencilStoreOp;
        VkImageLayout   initialLayout;
        VkImageLayout   finalLayout;
    }VkAttachmentDescription;


    typedef struct VkSubpassDescription{
        VkSubpassDescriptionFlags flags;
        VkPipelineBindPoint pipelineBindPoint;
        uint32_t    inputAttachmentCount;
        const VkAttachmentReference*    pInputAttachments;
        uint32_t    colorAttachmentCount;
        const VkAttachmentReference* pColorAttachments;
        const VkAttachmentReference* pResolveAttachments;
        const VkAttachmentReference* pDepthStencilAttachment;
        uint32_t preserveAttachmentCount;
        const uint32_t* pPreserveAttachments;
    }VkSubpassDescription;

    typedef struct VkAttachmentRefence{
        uint32_t attachment;
        VkImageLayout layout;
    }VkAttachmentRefence;


    typedef struct VkSubpassDependency{
        uint32_t srcSubpass;
        uint32_t dstSubpass;
        VkPipelineStageFlags srcStageMask;
        VkPipelineStageFlags dstStageMask;
        VkAccessFlags srcAccessMask;
        VkAccessFlags dstAccessMask;
        VkDependencyFlags dependencyFlags;
    }VkSubpassDependency;

    //销毁渲染通道对象
    void vkDestroyRenderPass(
        VkDevice device,
        VkRenderPass renderPass,
        const VkAllocationCallBack* pAllocator
    );
    //帧缓冲区
    //创建帧缓冲区
    VkResult vkCreateFramebuffer(
        VkDevice device,
        const VkFramebufferCreateInfo* pCreateInfo,
        const VkAllocationCallbacks*   pAllocator,
        VaFramebuffer* pFramebuffer
    );

    typedef struct VkFramebufferCreateInfo{
        VkStructure sType;
        const void* pNext;
        VkFramebufferCreateFlags flags;
        VkRenderPass renderPass;
        uint32_t attachmentCount;
        const VkImageView*  pAttachments;
        uint32_t width;
        uint32_t height;
        uint32_t layers;
    }VkFramebufferCreateInfo;

    //销毁帧缓冲区
    void vkDestroyFramebuffer(
        VkDevice device,
        VkFramebuffer framebuffer,
        const VkAllocationCallbacks* pAllocator,
    )

    //创建一个简单的图形管线
    //创建图形管线
    VkResult vkCreateGraphicsPipelines(
        VkDevice device,
        VkPipelineCache pipelineCache,
        uint32_t createInfoCount,
        const VkGraphicsPipelineCreateInfo* pCreateInfos,
        const VkAllocationCallbacks* pAllocator,
        VkPipeline* pPipelines
    );

    typedef struct VkGraphicsPipelineCreateInfo{
        VkStructureType sType;
        const void* pNext;
        VkPipelineCreateFlags flags;
        uint32_t    stageCount;
        const VkPipelineShaderStageCreateInfo*  pStages;
        const VkPipelineVertexInputStateCreateInfo* pVertexInputState;
        const VkPipelineInputAssemblyStateCreateInfo* pInputAssemblyState;
        const VkPipelineTessellationStateCreateInfo*  pTessellationState;
        const VkPipelineViewportStateCreateInfo* pViewportState;
        const VkPipelineRasterizationStateCreateInfo* pRaterizationState;
        const VkPipelineMultisampleStateCreateInfo* pMultsampleState;
        const VkPipelineDepthStencilStateCreateInfo* pDepthStencilState;
        const VkPipelineColorBlendStateCreateInfo* pColorBlendState;
        const VkPipelineDynamicStateCreateInfo* pDynamicState;
        VkPipelineLayout layout;
        VkRenderPass renderPass;
        uint32_t subpass;
        VkPipeline basePipelineHandle;
        int32_t basePipelineIndex;
    }VkGraphicsPipelineCreateInfo;

    //图形着色器阶段
    typedef struct VkPipeLineStateCreateInfo{
        VkStructureType sType;
        const void* pNext;
        VkPipelineShaderStageCreateFlags flags;
        VkShaderStageFlagBits stage;
        VkShaderModule module;
        const char* pName;
        const VkSpecilalizationInfo* pSepcializationInfo;
    }VkPipeLineStateCreateInfo;


    typedef struct VkPipelineVertexInputStateCreateInfo{
        VkStructureType sType;
        const void* pNext;
        VkPipelineVertexInputStateCreatefFlags flags;
        uint32_t vertexBindingDescription;
        const VkVertexInputBindingDesription* pVertexBingingDesciptions;
        uint32_t vertexAttributreDescriptionCount;
        const VkVertexInputAttributeDescription* pVertexAttributeDescriptions;
    }VkPipelineVertexInputStateCreateInfo;


    typedef struct VkVertexInputBindingDesciption {
        uint32_t binding;
        uint32_t stride;
        VkVertexInputRate inputRate;
    }VkVertexInputBindingDescription;

    typedef struct VkVertexInputAttributeDescription{
        uint32_t location;
        uiny32_t binding;
        VkFormat format;
        uint32_t offset;
    }VkVertexInputAttributeDesciption;
    //输入组装
    typedef struct VkPipelineInputAssemblyStateInfo{
        VkStructureType sType;
        const void* pNext;
        VkPipelineInputAssemblyStateCreateFlags flags;
        VkPrimitiveTopology topology;
        VkBool32 primitiveResatrtEnable;
    }VkPipelineInputAssemblyStateInfo;
    //细分状态
    typedef struct VkPipelineTessellationStateCreateInfo{
        VkStructureType sType;
        const void* pNext;
        VkPipelineTessellationStateCreateFlags flags;
        uint32_t patchControlPoints;
    }VkPipelineTessellationStateCreateInfo;

    //视口状态
    typedef struct VkPipelineViewportStateCreateInfo{
        VkStructureType sType;
        const void* pNext;
        VkPipelineViewportStateCreateFlags flags;
        uint32_t    viewportCount;
        const VkViewport* pViewport;
        uint32_t    scissorCount;
        const VkRect2D* pScissors;
    }VkPipelineViewportStateCreateInfo;


    typedef struct VkViewport{
        float x;
        float y;
        float width;
        float height;
        float minDepth;
        float maxDepth;
    }VkViewport;

    typedef struct VkRect2D{
        VkOffset2D offset;
        VkExtent2D extent;
    }VkRect2D;
    
    //光栅化
    typedef struct VkPipelineRasterizationStateCreateInfo{
        VkStructureType sType;
        const void* pNext;
        VkPipelineRaseterizationStateCreateFlags flags;
        VkBool32 depthClampEnable;
        VkBool32 reasteriizerDiscardEnable;
        VkPolygonMode polygonMode;
        VkCullModeFlags cullMode;
        VkFrontFace frontFace;
        VkBool32 depthBiasEnable;
        float depthBiasConstantFactor;
        float depthBiasClamp;
        float depthBiasSlopeFactor;
        float lineWidth;
    }VkPipelineRasterizationStateCreateInfo;

    //多重采样状态
    typedef struct VkPipelineMultisampleStateCreateInfo{
        VkStructure sType;
        const void* pNext;
        VkPipelineMultisampleStateCreateFlags flags;
        VkSampleCountFlagBits rasterizationSamples;
        VkBool32    sampleShadingEnable;
        float   mimSampleShading;
        const VkSampleMask* pSampleMask;
        VkBool32    alphaToCoverageEnable;
        VkBool32    alphaToOneEnable;
    }VkPipelineMultisampleStateCreateInfo;
    
    //深度和模板状态
    typedef struct VkPipelineDepthStencilStateCreateInfo{
        VkStructure sType;
        const void* pNext;
        VkPipelineDepthStencilStateCreateFlags flags;
        VkBool32    depthTestEnable;
        VkBool32 depthWriteEnable;
        VkCompareOp depthCompareOp;
        VkBool32    depthBoundsTestEnable;
        VkBool32    stencilTestEnable;
        VkStencilOpState front;
        VkStencilOpState back;
        float minDepthBounds;
        float maxDepthBounds;
    }VkPipelineDepthStencilStateCreateInfo;

    //颜色混合状态
    typedef struct VkPipelineColorBlendStateCreateInfo{
        VkStructureType sType;
        const void*     pNext;
        VkPipelineColorBlendStateCreateFlags flags;
        VkBool32    logicOpEnable;
        VkLogicOp   logicOp;
        uint32_t    attachmentCount;
        const VkPipelineColorBlendAttachmentState* pAttachments;
        float   blendConstants[4];
    }VkPipelineColorBlendStateCreateInfo;

    typedef struct VkPipelineColorBlendAttchmentState{
        VkBool32 blendEnable;
        VkBlendFactor srcColorBlendFactor;
        VkBlendFactor dstColorBlendFactor;
        VkBlendOp   colorBlendOp;
        VkBlendFactor srcAlphaBlendFactor;
        VkBlendFactor dstAlphaBlendFactor;
        VkBlendOp   alphaBlendOp;
        VkColorComponentFlags colorWriteMask;
    }VkPipelineColorBlendAttchmentsState;

    //动态状态
    typedef struct VkPipelineDynamicStateCreateInfo {
        VkStructureType sType;
        const void* pNext;
        VkPipelineDynamicStateCreateFlags flags;
        uint32_t    dynamicStateCount;
        const VkDynamicState*   pDynamicStates;
    }VkPipelineDynamicStateCreateInfo;

    //准备绘制
    //设置当前的渲染对象
    void vkCmdBeginRenderPass(
        VkCommandBuffer commandBuffer,
        const VkRenderPassBeginInfo* pRenderPassBegin,
        VkSubpassContents contents
    );
    typedef struct VkRenderPassBeginInfo{
        VkStructureType sType;
        const void* pNext;
        VkRenderPass renderPass;
        VkFramebuffer framebuffer;
        VkRect2D    renderArea;
        uint32_t    clearValueCount;
        const VkClearValue* pClearValues;
    }VkRenderPassBeginInfo;

    typedef union VkClearValue{
        VkClearColorValue color;
        VkClearDepthStencilValue depthStncil;
    }VkClearValue;

    typedef union VkClearColorValue{
        float float32[4];
        int32_t int32[4];
        uint32_t uint32[4];
    }VkClearColorValue;

    typedef struct VkClearDepthStencilValue{
        float depth;
        uint32_t stencil;
    }VkClearDepthStencilValue;

    //终止渲染
    void vkCmdEndRenderPass(
        VkCommandBuffer commandBuffer
    );
    
    //顶点数据
    //把缓冲区当作顶点数据
    void vkCmdBindVertexBuffers(
        VkCommandBuffer comandBuffer,
        uint32_t firstBinding,
        uint32_t bindingCount,
        const VkBuffer* pBuffers,
        const VkDeviceSize* pOffsets
    )
    
    //索引绘制
    void vkCmdDrawIndexed(
        VkCommandBuffer commandBuffer,
        uint32_t    indexCount,
        uint32_t    instanceCount,
        uint32_t    firstIndex,
        int32_t     vertexOffset,
        uint32_t    firstInstance
    );

    void vkCmdBindIndexBuffer(
        VkCommandBuffer commandBuffer,
        VkBuffer buffer,
        VkDeviceSize offset,
        VkIndexType indexType
    );


    typedef struct VkPipelineInputAssemblyStateCreateInfo{
        VkStructureType     sType;
        const void*         pNext;
        VkPipelineInputAssemblyStateCreateFlags flags;
        VkPrimitiveTopology     topology;
        VkBool32        primitiveRestartEnable;
    }VkPipelineInputAssemblyStateCreateInfo;
    
    //间接绘制
    void vkCmdDrawIndirect(
        VkCommandBuffer commandBuffer,
        VkBuffer buffer,
        VkDeviceSize offset,
        uint32_t    drawCount,
        uint32_t    stride
    );


    typedef struct VkDrawIndirectCommand{
        uint32_t vertexCount;
        uint32_t instanceCount;
        uint32_t firstVertex;
        uint32_t firstInstance;
    }VkDrawIndirectCommand;

    //索引间接绘制
    void vkCmdDrawIndexedIndirect(
        VkCommandBuffer commandBuffer,
        VkBuffer buffer,
        VkDevice offset,
        uint32_t drawCount,
        uint32_t stride
    );

    typedef struct VkDrawIndexedIndirectCommand{
        uint32_t    indexCount;
        uint32_t    instanceCount;
        uint32_t    firstIndex;
        int32_t     vertexOffest;
        uint32_t    firstInstance;
    }VkDrawIndexedIndirectCommand;

    //表面细分配置

    typedef struct VkPipelineTessellationStateCreateInfo{
        VkStructureType sType;
        const void*     pNext;
        VkPipelineTessellationStateCreateFlags flags;
        uint32_t    patchControlPoints;
    }VkPipelineTessellationStateCreteInfo;

    typedef struct VkRect2D {
        VkOffset2D offset;
        VkExtent2D extent;

    }VkRect2D;

    typedef struct VkOffset2D {
        int32_t x;
        int32_t y;
    }VkOffset2D;

    typedef struct VkExtent2D {
        uint32_t width;
        uint32_t height;
    }VkExtent2D;
    //修改裁剪区域
    void vkCmdSetScissor(
        VkCommandBuffer commandBuffer,
        uint32_t firstScissor,
        const VkRect2D* pScissors
    );
    //深度测试模板
    typedef struct VkPipelineDepthStencilStateCreateInfo{
        VkStructureType sType;
        const void*     pNext;
        VkPipelineDepthStencilStateCreateFlags flags;
        VkBool32    depthTestEnable;
        VkBool32    depthWriteEnable;
        VkCompareOp    depthCompareOp;
        VkBool32    depthBoundsTestEnable;
        VkBool32    stencilTestEnable;
        VkStencilOpState front;
        VkStencilOpState back;
        float minDepthBounds;
        float maxDepthBounds;
    }VkPipelineDepthStencilStateCreateInfo;

    //深度最大最小范围设置
    void vkCmdSetDepthBounds(
        VkCommandBuffer commandBuffer,
        float minDepthBounds,
        float maxDepthBounds
    );

    //深度偏差
    typedef struct VkPipelineRasterizationStateCreateInfo{
        VkStructureType sType;
        const void*     pNext;
        VkPipelineRasterizationStateCreateFlags flags;
        VkBool32        depthClampEnabel;
        VkBool32        rasterizeDiscardEnable;
        VkPolygonMode   poloygonMode;
        VkCullModeFlags cullMode;
        VkFrontFace     frontFace;
        VkBool32        depthBiasEnable;
        float           depthBiasConstantFactor;
        float           depthBiasClamp;
        float           depthBiasSlopeFactor;
        float           lineWidth;
    }VkPipelineRasterizationStateCreateInfo;


    //深度偏差方程参数设置
    void vkCmdSetDepthBias(
        VkCommandBuffer commandBuffer,
        float   depthBiasConstantFactor,
        float   depthBiasClamp,
        float   depthBiasSlopeFactor
    );

    //模板测试
    typedef struct VkStencilOpState{
        VkStencilOp failOp;
        VkStencilOp passOp;
        VkStencilOp depthFailOp;
        VkCompareOp compareOp;
        uint32_t compareMask;
        uint32_t writeMask;
        uint32_t refence;
    }VkStencilOpState;

    //多重采样渲染
    //返回某种格式的信息
    VkResult vkGetPhysicalDeviceImageFormatProperties(
        VkPhysicalDevice physicalDevice,
        VkFormat         format;
        VkImageType      type;
        VkImageTiling    tiling;
        VkImageUsageFlags usage;
        VkImageCreateFlags flags;
        VkImageFormatProperties* pImageFormatProperties
    );

    //多重采样解析
    //将多重采样图像解析
    void vkCmdResolvImage(
        VkCommandBuffer commandBuffer,
        VkImage srcImage,
        VkImageLayout srcImageLayout,
        VkImage dstImage,
        VkImageLayout dstImageLayout,
        uint32_t regionCount,
        const VkImageResolve* pRegions
    );

    typedef struct VkImageResolve{
        VkImageSubresourceLayers srcSubersource;
        VkOffset3D      srcOffset;
        VkImageSubresourceLayers dstSubresource;
        VkOffset3D      dstOffset;
        VkExtent3D      extent;
    }VkImageResolve;
    
    //颜色混合
    typedef struct VkPipelineColorBlendAttachmentState {
        VkBool32    blendEnable;
        VkBlendFactor srcColorBlendFactor;
        VkBlendFactor dstColorBlendFactor;
        VkBlendOp     colorBlendOp;
        VkBlendFactor srcAlphaBlendFactor;
        VkBlendFactor dstAlphaBlendFactor;
        VkBlendOp     alphaBlendOp;
        VkColorCompoentFlags colorWriteMask;
    }VkPipelineColorBlendAttachmentState;

    //改变混合常量
    void vkCmdSetBlendConstants(
        VkCommandBuffer commandBuffer,
        const float blendConstants[4]
    );

    //栅栏
    VkResult vkCreateFence(
        VkDevice device,
        const VkFenceCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkFence*    pFence
    );

    typedef struct VkFenceCreateInfo {
        VkStructureType sType;
        const void*     pNext;
        VkFenceCreateFlags flags;
    }VkFenceCreateInfo;
    
    //销毁释放
    void vkDestroyFence(
        VkDevice device,
        VkFence  fence,
        const VkAllocationCallbacks* pAllocator
    );

    VkResult vkQueueSubmit(
        VkQueue     queue,
        uint32_t    submitCount,
        const VkSubmitInfo* pSubmits,
        VkFence     fence
    );

    VkResult vkGetFenceStatus(
        VkDevice device,
        VkFence fence
    );

    VkResult vkWaitForFences(
        VkDevice device,
        uint32_t fenceCount,
        const VkFence* pFences,
        VkBool32 waitAll,
        uint64_t timeout
    );

    VkResult vkResetFences(
        VkDevice device,
        uint32_t fenceCount,
        const VkFence* pFences
    );

    //事件
    VkResult vkCreateEvent(
        VkDeivce device,
        const VkEventCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkEvent* pEvent
    );

    typedef struct VkEventCreateInfo {
        VkStructureType sType;
        const void* pNext;
        VkEventCreateFlags flags
    }VkEventCreateInfo;

    void vkDestroyEvent(
        VkDevice device,
        VkEvent event,
        const VkAllocationCallbacks* pAllocator
    );

    VkResult vkSetEvent{
        VkDevice device,
        VkEvent event
    };

    VkResult vkGetEventStatus(
        VkDevice device,
        VkEvent event
    );

    void vkCmdSetEvent(
        VkCommandBuffer commandBuffer,
        VkEvent event,
        VkPipelineStageFlags stageMask
    );

    void vkCmdResetEvent(
        VkCommandBuffer commandBuffer,
        VkEvent event,
        VkPipelineStageFlags stageMask
    );

    void vkCmdWaitEvents(
        VkCommand commandBuffer,
        uint32_t eventCount,
        const VkEvent*  pEvents,
        VkPipelineStageFlags srcStageMask,
        VkPipelineStageFlags dstStageMask,
        uint32_t memoryBarrierCount,
        const VkMemoryBarrier* pMemoryBarriers,
        uint32_t bufferMemoryBarrierCount,
        const VkBufferMemoryBarrier* pBufferMemoryBarriers,
        uint32_t imageMemoryBarrierCount,
        const VkImageMemoryBarrier* pImageMemoryBarriers
    );

    //信号量
    VkResult vkCreateSemaphore(
        VkDevice device,
        const VkSemaphoreCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkSemaphore* pSemaphore
    );

    typedef struct VkSemaphoreCreateInfo {
        VkStuctureType sType;
        const void* pNext;
        VkSemaphoreCreateFlags flags;
    }VkSemaphoreCreateInfo;

    void VkDestorySemaphore(
        VkDevice device,
        VkSemaphore semaphore,
        const VkAllocationCallbacks* pAllocator
    );

    VkResult vkQueueSubmit(
        VkQueue queue,
        uint32_t submitCount,
        const VkSubmitInfo* pSubmits,
        VkFence fence
    );

    typedef struct VkSubmitInfo{
        VkStuctureType sType;
        const void*    pNext;
        const VkSemaphore* pWaitSemaphores;
        const VkPipelineStageFlags* pWaitDstStageMask;
        uint32_t commandBufferCount;
        const VkCommandBuffer* pCommandBuffers;
        uint32_t signalSempahoreCount;
        const VkSemaphore* pSignalSemaphores;
    }VkSubmitInfo;

    //创建查询池
    VkResult vkCreateQueryPool(
        VkDevice device,
        const VkQueryPoolCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkQueryPool* pQueryPool
    );

    typedef struct VkQueryPoolCreateInfo {
        VkStructType sType;
        const void* pNext;
        VkQueryPoolCreateFlags flags;
        VkQueryType  queryType;
        uint32_t     quertCount;
        VkQueryPipelineStatisticFlags pipelineStatistics;
    }VkQueryPoolCreateInfo;

    void vkDestoryQueryPool(
        VkDevice device,
        VkQueryPool queryPool,
        const VkAllocationCallbacks* pAllocator
    );

    void vkCmdResetQueryPool(
        VkCommandBuffer commandBuffer,
        VkQueryPool queryPool,
        uint32_t firstQuery,
        uiny32_t queryCount
    );

    void vkCmdBeginQuery(
        VkCommandBuffer commandBuffer,
        VkQueryPool queryPool,
        uint32_t firstQuery,
        uint32_t queryCount
    );


    void vkCmdBeginQuery(
        VkCommandBuffer commandBuffer,
        VkQueryPool queryPool,
        uint32_t query,
        VkQueryControlFlags flags
    );

    VkResult vkGetQueryPoolResults(
        VkDevice device,
        VkQueryPool queryPool,
        uint32_t firstQuery,
        uint32_t queryCount,
        size_t  dataSize,
        void*   pData,
        VkDeviceSize stride,
        VkQueryResultFlags flags
    );

    void vkCmdCopyQueryPoolResults(
        VkCommandBuffer commandBuffer,
        VkQueryPool queryPool,
        uint32_t    firstQuery,
        uint32_t    queryCount,
        VkBuffer    dstBuffer,
        VkDeviceSize dstOffset,
        VkDeviceSzie stride,
        VkQueryResultFlags flags
    );

    void vkCmdWriteTimestamp(
        VkCommandBuffer commandBuffer,
        VkPipelineStageFlagBits pipelineStage,
        VkQueryPool queryPool,
        uint32_t query
    );


    typedef struct VkRenderPassCreateInfo{
        VkStructureType sType;
        const void* pNext;
        VkRenderPassCreateFlags flags;
        uint32_t attachmentCount;
        const VkAttchmentDescription* pAttachments;
        uint32_t subpassCount;
        const VkSubpassDescription* pSubpasses;
        uint32_t dependecyCount;
        const VkSubpassDependency* pDependencies;
    }VkRenderPassCreateInfo;

    typedef struct VkSubpassDescription{
        VkSubpassDescriptionFlags flags;
        VkPipelineBindPoint     pipelineBindPoint;
        uint32_t                inputAttachmentCount;
        const VkAttachmentRefence* pInputAttachments;
        uint32_t    colorAttachmentCount;
        const VkAttachmentRefence* pColorAttachments;
        const VkAttachmentRefence* pResolveAttachments;
        const VkAttachmentRefence* pDepthStencilAttachment;
        uint32_t preserveAttachmentCount;
        const uint32_t* pPreserveAttachments;
    }VkSubpassDescription;

    //附件内容
    //附件初始化
    //清除渲染通道上的颜色附件
    void vkCmdClearAttachments(
        VkCommandBuffer commandBuffer,
        uint32_t    attachmentCount,
        const VkClearAttachment*    pAttachments,
        uint32_t    rectCount,
        const VkClearRect* pRects
    );

    typedef struct VkClearAttachment {
        VkImageAspectFlags aspectMask;
        uint32_t    colorAttachment;
        VkClearAttachment clearValue;
    }VkClearAttachment;

    typedef union VkClearValue {
        VkClearColorValue color;
        VkClearDepthStencilValue depthStencil;
    }VkClearValue;

    typedef struct VkClearRect {
        VkRect2D rect;
        uint32_t baseArrayLayer;
        uint32_t layerCount;
    }VkClearRect;

    //查询所使用的渲染区域和实现的支持渲染区域粒度匹配
    void vkGetRenderAreaGranularity(
        VkDeivce device,
        VkRenderPass renderPass,
        VkExtent2D*  pGranularity
    );
    //副命令缓冲区
    void vkCmdExecuteCommands(
        VkCommandbuffer commandBuffer,
        uint32_t    commandBufferCount,
        const VkCommandBuffer* pCommandBuffers
    );

    typedef struct VkCommandBufferInheritanceInfo{
        VkStructureType sType;
        const void* pNext;
        VkRenderPass renderPass;
        uint32_t subpass;
        VkFramebuffer framebuffer;
        VkBool32    occlusionQueryEnable;
        VkQueryControlFlags queryFlags;
        VkQueryPipelineStatisticFlags pipelineStatistics;
    }VkCommandBufferInheritanceInfo;
}
