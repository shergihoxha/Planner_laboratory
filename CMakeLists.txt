cmake_minimum_required(VERSION 3.20)
project(Planner_laboratory)

set(CMAKE_CXX_STANDARD 20)

# =========================
# GoogleTest
# =========================
include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

# Per Windows (importantissimo)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# =========================
# Libreria core (codice comune)
# =========================
add_library(planner_lib
        Activity.cpp
        Planner.cpp
)

target_include_directories(planner_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# =========================
# Applicazione principale
# =========================
add_executable(Planner_app
        main.cpp
)

target_link_libraries(Planner_app planner_lib)

# =========================
# Test
# =========================
enable_testing()

add_executable(Planner_tests
        tests/main_test.cpp
        tests/test_activity.cpp
        tests/test_planner.cpp
)

target_link_libraries(Planner_tests
        planner_lib
        gtest
        gtest_main
)

add_test(NAME PlannerTests COMMAND Planner_tests)
