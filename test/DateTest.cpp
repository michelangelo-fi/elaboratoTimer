
#include "Date.h"

#include <gtest/gtest.h>

TEST(DateTest, Validity){
    EXPECT_TRUE(Date(29,2,2024).isValid()); // bisestile
    EXPECT_FALSE(Date(31,4,2024).isValid());
}

TEST(DateTest, IsoFormat){
    Date d(3,7,1998);
    EXPECT_EQ(d.toIso(), "1998-07-03");
}
