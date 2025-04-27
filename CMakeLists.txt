cmake_minimum_required(VERSION 3.22)
project(miinitaja LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB ALL_SRCS CONFIGURE_DEPENDS
        "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable(miinitaja ${ALL_SRCS})

target_include_directories(miinitaja
        PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)
