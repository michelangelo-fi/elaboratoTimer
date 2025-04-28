find_package(GTest REQUIRED)

enable_testing()

set(TEST_SOURCES
        runTest.cpp
        DateTest.cpp
        TimeTest.cpp
        TimerTest.cpp
)

add_executable(unit_tests ${TEST_SOURCES})
target_link_libraries(unit_tests PRIVATE core GTest::gtest GTest::gtest_main)

add_test(NAME all_unit_tests COMMAND unit_tests)
