
#include "Timer.h"
#include <gtest/gtest.h>

TEST(TimerTest, Countdown){
    Timer t; t.start(3);
    t.tick(); // partendo da 3 mi rimarranno 2 secondi
    EXPECT_EQ(t.remaining(),2);
    t.tick(); // 1
    t.tick(); // 0
    EXPECT_TRUE(t.isFinished());
    EXPECT_EQ(t.remainingStr(), "00:00:00");
}

