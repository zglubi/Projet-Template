#include "ThreadManager.h"

ThreadManager::~ThreadManager()
{
    waitAll();
}

template<typename Func, typename... Args>
auto ThreadManager::addTask(Func&& func, Args&&... args) -> std::future<decltype(func(args...))> 
{
    auto task = std::make_shared<std::packaged_task<decltype(func(args...))()>>(std::bind(std::forward<Func>(func), std::forward<Args>(args)...));
    std::future<decltype(func(args...))> result = task->get_future();
    std::thread([task]() { (*task)(); }).detach();
    return result;
}

void ThreadManager::waitAll() 
{
    for (auto& future : futures)
    {
        if (future.valid()) 
        {
            future.get();
        }
    }
}
