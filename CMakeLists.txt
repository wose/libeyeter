cmake_minimum_required(VERSION 2.8.11)
project(libeyeter)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenCV REQUIRED)

enable_testing()

add_subdirectory(3rdparty/googletest)

include_directories(
    include
    3rdparty/pugixml/src
)

add_subdirectory(src)

add_subdirectory(t)
