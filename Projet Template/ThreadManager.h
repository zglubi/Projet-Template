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
    auto addTask(Func&& func, Args&&... args) -> std::future<decltype(func(args...))>;

    void waitAll();

private:
    std::vector<std::thread> threads;
    std::vector<std::future<void>> futures;
};
