
#ifndef ELABORATOTIMER_TIMER_H
#define ELABORATOTIMER_TIMER_H

#include <functional>
#include <thread>
#include <atomic>
#include <string>

class Timer {
public:
    using TickCB = std::function<void(int)>; // chiamato ogni secondo
    using FinishCB = std::function<void()>;    // chiamato a 0

    explicit Timer();

    ~Timer();

    void start(int totalSec);

    void stop();


    bool isFinished() const;

    bool isRunning() const;

    int remaining() const;    // secondi rimasti
    std::string remainingStr() const; // H:M:S

    void onTick(TickCB cb);

    void onFinish(FinishCB cb);

private:
    void workerLoop();

    void tick();               // decrementa di 1 s

    std::thread worker;
    std::atomic<int> secondsLeft{0};
    std::atomic<bool> running{false};

    TickCB tickCb;
    FinishCB finishCb;
};

#endif //ELABORATOTIMER_TIMER_H
