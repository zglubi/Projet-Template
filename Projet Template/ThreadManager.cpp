#include "ThreadManager.h"

ThreadManager::~ThreadManager()
{
    waitAll();
}

void ThreadManager::waitAll() 
{
    for (auto& future : futures)
    {/*
        while (!future.valid()) 
        {
        }
        future.get();*/
        future.wait();
    }
}
