#include "Timer.h"
#include <gtest/gtest.h>
#include <thread>
#include <chrono>


TEST(TimerCtor, RejectsNegative) {
    Timer t;
    EXPECT_THROW(t.start(-1), std::invalid_argument);
}

TEST(TimerFlow, FinishesAlone) {
    Timer t;
    t.start(2);                                     // 2 secondi
    std::this_thread::sleep_for(std::chrono::milliseconds(2500));
    EXPECT_TRUE(t.isFinished());
    EXPECT_EQ(t.remaining(), 0);
}

TEST(TimerStop, StopsEarly) {
    Timer t;
    t.start(5);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    t.stop();
    EXPECT_FALSE(t.isRunning());
    EXPECT_GT(t.remaining(), 0);
}

TEST(TimerFormat, RemainingStr) {
    Timer t;
    t.start(3661);                       // 1 h 1 m 1 s
    EXPECT_EQ(t.remainingStr(), "01:01:01");
    t.stop();
}
