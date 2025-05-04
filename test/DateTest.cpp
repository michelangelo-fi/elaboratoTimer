#include "Date.h"
#include <gtest/gtest.h>


TEST(DateCtor, AcceptsValidDates) {
    EXPECT_NO_THROW(Date(1, 1, 1970));      // epoca
    EXPECT_NO_THROW(Date(29, 2, 2024));     // 2024 bisestile
    EXPECT_NO_THROW(Date(31, 12, 1999));    // fine anno valido
}


TEST(DateCtor, RejectsInvalidDates) {
    EXPECT_THROW(Date(31, 4, 2024),  std::invalid_argument); // aprile 30 gg
    EXPECT_THROW(Date(29, 2, 2023),  std::invalid_argument); // 2023 non bisestile
    EXPECT_THROW(Date(0,  1, 2024),  std::invalid_argument); // giorno 0
    EXPECT_THROW(Date(15,13, 2024),  std::invalid_argument); // mese 13
    EXPECT_THROW(Date(10,10,-10),    std::invalid_argument); // anno negativo
}


TEST(DateIso, ProducesISOFormat) {
    EXPECT_EQ(Date(3, 7, 1998).toIso(), "1998-07-03");
    EXPECT_EQ(Date(9,11,  75).toIso(), "0075-11-09");  // padding a 4 cifre
}
