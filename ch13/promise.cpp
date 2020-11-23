//
// Created by 刘时明 on 2020/11/22.
//
#include <future>

void promise_test(std::promise<int> &tep, int calc)
{
    int result = calc * 10;
    std::chrono::milliseconds wait_time(100);
    std::this_thread::sleep_for(wait_time);

    tep.set_value(result);
    printf("返回结果！\n");
}

void promise_demo()
{
    std::promise<int> int_promise{};
    std::thread t(promise_test, std::ref(int_promise), 22);
    t.join();

    std::future<int> future=int_promise.get_future();

    printf("result=%d \n",future.get());
}