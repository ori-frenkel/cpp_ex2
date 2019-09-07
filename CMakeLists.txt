cmake_minimum_required(VERSION 3.12)
project(cppEx2S)

set(CMAKE_CXX_STANDARD 14)

find_package (Boost REQUIRED COMPONENTS filesystem)


add_executable(cppEx2S FractalDrawer.cpp Fractal.cpp Fractal.h)

target_link_libraries(cppEx2S
        ${Boost_SYSTEM_LIBRARY} ${Boost_FILESYSTEM_LIBRARY})