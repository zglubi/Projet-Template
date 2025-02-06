#pragma once
#include <thread>
#include <vector>
#include <functional>
#include <future>
#include <iostream>

using namespace std;
class ThreadManager {
public:
    ThreadManager() = default;
    ~ThreadManager();

    template<typename Func, typename... Args>
    auto addTask(Func&& func, Args&&... args) -> future<decltype(func(args...))> {
        auto task = make_shared<packaged_task<decltype(func(args...))()>>(
            bind(forward<Func>(func), forward<Args>(args)...));
        future<decltype(func(args...))> result = task->get_future();
        thread([task]() { (*task)(); }).detach();
        return result;
    }

    void waitAll();

private:
    vector<future<void>> futures;
};
