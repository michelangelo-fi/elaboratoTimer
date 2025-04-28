
#include "Time.h"
#include <gtest/gtest.h>

TEST(TimeTest, Validity) {
    EXPECT_TRUE(Time(23, 59, 59).isValid());
    EXPECT_FALSE(Time(25, 0, 0).isValid());
}

TEST(TimeTest, To24) {
    Time t(1, 2, 3);
    EXPECT_EQ(t.to24(), "01:02:03");
}
