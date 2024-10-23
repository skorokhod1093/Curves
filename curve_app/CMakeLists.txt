cmake_minimum_required(VERSION 3.20)

project(CurvesApp)

add_executable(CurvesApp
               main.cpp
               src/CurveManager.cpp
)

find_package(OpenMP REQUIRED)
if(OpenMP_FOUND)
    target_link_libraries(CurvesApp PRIVATE CurvesLibrary OpenMP::OpenMP_CXX)
else()
    message(FATAL_ERROR "OpenMP not found!")
endif()

target_include_directories(CurvesApp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
