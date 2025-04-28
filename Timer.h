
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

    explicit Timer(int totalSec = 0);

    ~Timer();

    void start(int totalSec);

    void stop();

    void tick();               // decrementa di 1 s

    bool isFinished() const;

    bool isRunning() const;

    int remaining() const;    // secondi rimasti
    std::string remainingStr() const; // H:M:S

    void onTick(TickCB cb);

    void onFinish(FinishCB cb);

private:
    void workerLoop();

    std::thread worker;
    std::atomic<int> secondsLeft{0};
    std::atomic<bool> running{false};

    TickCB tickCb;
    FinishCB finishCb;
};

#endif //ELABORATOTIMER_TIMER_H
