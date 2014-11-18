cmake_minimum_required(VERSION 2.8.4)
project(Some)

set(HEADERS
            api.hpp
            math.hpp
    )
set(SOURCE_FILES
            main.cpp
    )

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -pedantic -Wall -Wno-deprecated")
add_executable(Some ${SOURCE_FILES})
