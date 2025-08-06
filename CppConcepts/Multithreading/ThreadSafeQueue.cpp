#include <condition_variable>
#include <iostream>
#include <list>
#include <mutex>
#include <string>
#include <thread>

template <typename T>
class ThreadSafeQueue {

    public:

    void push(T data) {
        {
            std::unique_lock<std::mutex> lock(mMutex);
            mData.push_back(data);
        }

        mConditionVar.notify_one();
    }

    T pop() {
        std::unique_lock<std::mutex> lock(mMutex);
        mConditionVar.wait(lock, [this]() {return !mData.empty();});
        T data = mData.front();
        mData.pop_front();
        return data;
    }

    size_t size() {
        std::unique_lock<std::mutex> lock(mMutex);
        return mData.size();
    }

    bool empty() {
        std::unique_lock<std::mutex> lock(mMutex);
        return mData.empty();
    }

    private:
    
    std::mutex mMutex;
    std::condition_variable mConditionVar;
    std::list<T> mData;
};


int main() {
    ThreadSafeQueue<std::string> queue;
    const std::vector<std::string> data = {"first", "second", "third", "forth", "fifth"};
    
    std::thread write_thread([&queue, &data]() {
        for (auto &e : data) 
            queue.push(e);
    });        


    std::thread read_and_delete_thread([&queue](size_t count) {
        for (size_t i=0; i < count; i++) 
            std::cout << queue.pop() << "\n";             
    }, data.size());

    write_thread.join();
    read_and_delete_thread.join();

    return 0;    
}

