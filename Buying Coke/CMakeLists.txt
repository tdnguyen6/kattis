cmake_minimum_required(VERSION 3.0.0)
project("Buying Coke" VERSION 0.1.0)

add_executable(buying-coke src/buying-coke.cpp)

find_package(Boost 1.71.0 REQUIRED COMPONENTS unit_test_framework)

enable_testing()

add_executable(demo_test tests/demo.cpp)

target_link_libraries(demo_test
    Boost::unit_test_framework
)

target_compile_definitions(demo_test
    PRIVATE
        BOOST_TEST_DYN_LINK
)

add_test(test1 demo_test)