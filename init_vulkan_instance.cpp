VkResult vkapp::init()
{
    VkResult result = VK_SUCCESS;
    VkApplicationInfo appInfo = {};
    VkInstanceCreateInfo instanceCreateInfo = {};

    //通用的应用程序消息结构体
    appInfo.sType = VK_STRUCETURE_TYPE_APPLOCATION_INFO;
    appInfo.pApplicationName = "Application";
    appInfo.applicationVersion = 1;
    appInfo.apiVersion = VK_MAKE_VERSION(1,0,0);

    //创建实例
    instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instanceCreateInfo.pApplicationInfo = &appInfo;

    if(result == VK_SUCCESS)
    {
        //判断设备数量
        uint32_t physicalDeviceCount = 0;
        vkEnumeratePhysicalDevices(m_instance,&physicalDeviceCount,nullptr);

        if(result == VK_SUCCESS)
        {
            //调整设备大小，获取物理设备句柄
            m_physicalDevices.resize(physicalDeivceCount);
            vkEnumeratePhysicalDevices(m_instance,&physicalDeviceCount,&m_physicalDevices[0]);
        }
    }
    return result;
}