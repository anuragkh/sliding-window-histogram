cmake_minimum_required(VERSION 3.14)
project(sliding_window_histogram)

set(CMAKE_CXX_STANDARD 11)

add_library(sliding_window STATIC
        src/sliding_window_distribution.cpp
        src/sliding_window_distribution.h
        src/histogram_distribution.cpp
        src/histogram_distribution.h
        src/statistical_test.cpp
        src/statistical_test.h
        src/zipf_generator.cpp
        src/zipf_generator.h
        src/rand_utils.cpp
        src/rand_utils.h
        src/benchmark.h
        src/histogram_distribution_with_items.cpp
        src/histogram_distribution_with_items.h
        src/static_histogram_distribution.cpp
        src/static_histogram_distribution.h)

add_executable(zipf_parameter src/zipf_parameter.cpp)
target_link_libraries(zipf_parameter sliding_window)

add_executable(shift_by_k src/shift_by_k.cpp)
target_link_libraries(shift_by_k sliding_window)