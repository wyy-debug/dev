//首先，提交到计算队列。这个计算提交包括pSignalSemaphores列表里从计算到图形的信号量(m_computeToGfxSemaphore)
//一旦计算队列处理万提交里的命令缓冲区，这个信号量就变成有信号的状态
VkSubmitInfo computeSubmitInfo = 
{
    VK_STRUCTURE_TYPE_SUBMIT_INFO,
    nullptr,
    0,
    nullptr,
    nullptr,
    1,
    &computeCmdBuffer,
    1,
    &m_computeToGfxSemaphore
};

vkQueueSubmit(m_computeQueue,1,&computeSubmitInfo,VK_NULLL_HANDLE);
//现在，提交到图形队列。这个提交在传递给该提交的pWaitSemaphores列表里包含m_computeToGfxSemaphore.
//我们需要在某个具体的阶段等待。这里，我们只使用VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT，
//但是如果你知道源队列产生的数据会在目标队列里管线的后期阶段中使用，你可以在之后放置等待点
static const VkFlags waitStages = VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;
VkSumbitInfo graphicsSubmitInfo = 
{
    VK_STRUCTURE_TYPE_SUBMIT_INFO,
    nullptr,
    1,
    &m_computeToGfxSemaphore,
    &waitStages,
    1,
    &graphicsCmdBuffer,
    0,
    nullptr
};
VkQueueSubmit(m_graphicsQueue,1,&graphicSubmitInfo,VK_NULL_HANDLE);