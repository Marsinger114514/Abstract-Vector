cmake_minimum_required(VERSION 3.10)
project(work)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(work main.cpp test-string-diversity.cpp String.cpp TestString.cpp TestVector.cpp )
