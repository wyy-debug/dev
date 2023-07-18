class allocator
{
    public:
        inline operator VkAllocationCallbacks() const{
            VkAllocationCallbacks result;
            result.pUserData = (void*)this;
            result.pfnAllocation = &Allocation;
            result.pfnReallocation = &Reallocation;
            result.pfnFree = &Free;
            result.pfnInternalAllocation = nullptr;
            result.pfnInternalFree = nullptr;

            return result;
        };
    private:
    	static void* VKAPI_CALL Allocation(
            void*   pUserData,
            size_t  size,
            size_t  alignment,
            VkSystemAllocationScope allocationScope
        );
        
        static void* VKAPI_CALL Reallocation(
            void*   pUserData,
            void*   pOriginal,
            size_t  size,
            size_t  alignment,
            VkSystemAllocationScope allocationScope
        );

        static void VKAPI_CALL Free(
            void*   pUserData,
            void*   pMemory
        );

        void* Allocation(
            size_t size,
            size_t alignment,
            VkSystemAllocationScope allocationScope
        );

        void* Reallocation(
            void* pOriginal,
            size_t size,
            size_t alignment,
            VkSystemAllocationScope allocationScope
        );

        void Free(void* pMemory);
}