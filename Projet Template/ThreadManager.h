#pragma once
#include <thread>
#include <vector>
#include <functional>
#include <future>

class ThreadManager {
public:
    ThreadManager() = default;
    ~ThreadManager();

    template<typename Func, typename... Args>
    auto addTask(Func&& func, Args&&... args) -> std::future<decltype(func(args...))> {
        auto task = std::make_shared<std::packaged_task<decltype(func(args...))()>>(
            std::bind(std::forward<Func>(func), std::forward<Args>(args)...));
        std::future<decltype(func(args...))> result = task->get_future();
        std::thread([task]() { (*task)(); }).detach();
        return result;
    }

    void waitAll();

private:
    std::vector<std::future<void>> futures;
};
