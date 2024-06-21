cmake_minimum_required(VERSION 3.5)

include_directories("src/include/")
include_directories("src/")

file(GLOB HEADERS "src/include/*.h")
file(GLOB MODULES "src/*.cpp")

project(tictactoe)
set(SOURCES ${HEADERS} ${MODULES})
add_executable(tictactoe ${SOURCES})