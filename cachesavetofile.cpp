VkResult SaveCacheToFile(vkDevice device,VkPipelineCache cache,const char* fileName)
{
    size_t cacheDataSize;
    VkResult result  = VK_SUCCESS;
    //判断缓存数据的大小
    result = vkGetPipelineCacheData(device,cache,&cacheDataSize,nullptr);
    if(result == VK_SUCCESS && cacheDataSize != 0)
    {
        FILE* pOutputFile;
        void* pData;

        //为缓存数据分配一个临时存储区
        result = VK_ERROR_OUT_OF_HOST_MEMORY;
        pData = malloc(cacheDataSize);

        if(pData != nullptr)
        {
            //从缓存里获取实际的数据
            result = vkGetPipelineCacheData(device,cache,&cacheDataSize,pData);
            if(result == VK_SUCCESS)
            {
                pOutputFile = fopen(fileName,"wb");
                if(pOutputFile != nullptr)
                {
                    fwrite(pData,1,cacheDataSize,pOutputFile);
                    fclose(pOutputFile);
                }
                free(pData);
            }
        }
    }
    return result;
}