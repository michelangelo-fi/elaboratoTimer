
#include "Time.h"
#include <gtest/gtest.h>


TEST(TimeTest, To24) {
    Time t(1, 2, 3);
    EXPECT_EQ(t.to24(), "01:02:03");
}


TEST(TimeCtor, AcceptsValidTimes) {
    EXPECT_NO_THROW(Time(0, 0, 0));        // mezzanotte
    EXPECT_NO_THROW(Time(23, 59, 59));     // ultimo secondo del giorno
    EXPECT_NO_THROW(Time(1, 2, 3));        // generico
}


TEST(TimeCtor, RejectsInvalidTimes) {
    EXPECT_THROW(Time(40, 0, 0),  std::invalid_argument);  // ora non ammessa
    EXPECT_THROW(Time(24, 0, 0),  std::invalid_argument);  // ora 24 non ammessa
    EXPECT_THROW(Time(-1, 0, 0),  std::invalid_argument);  // ora negativa
    EXPECT_THROW(Time(23, 60, 0), std::invalid_argument);  // minuto 60
    EXPECT_THROW(Time(23,-1,  0), std::invalid_argument);  // minuto negativo
    EXPECT_THROW(Time(23, 59, 60),std::invalid_argument);  // secondo 60
    EXPECT_THROW(Time(23, 59,-1), std::invalid_argument);  // secondo negativo
}

TEST(TimeFormat, To24ProducesHHMMSS) {
    Time t1(1, 2, 3);
    EXPECT_EQ(t1.to24(), "01:02:03");

    Time t2(23, 59, 59);
    EXPECT_EQ(t2.to24(), "23:59:59");

    Time t3(0, 0, 0);
    EXPECT_EQ(t3.to24(), "00:00:00");  //padding, ovvero zeri di riempimento
}
