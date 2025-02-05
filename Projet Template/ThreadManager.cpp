#include "ThreadManager.h"

ThreadManager::~ThreadManager()
{
    waitAll();
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
