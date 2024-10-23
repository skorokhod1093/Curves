cmake_minimum_required(VERSION 3.20)

project(CurvesLibrary)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(CurvesLibrary SHARED
    src/Circle.cpp
    src/Ellipse.cpp
    src/Helix.cpp
)

target_include_directories(CurvesLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
