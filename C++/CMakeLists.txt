cmake_minimum_required(VERSION 3.28)
project(ConcurrentImageColorChanger VERSION 1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SOURCES "src/*.cpp")

find_package(OpenCV REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})
include_directories(include)

target_link_libraries(${PROJECT_NAME} PRIVATE ${OpenCV_LIBS})
