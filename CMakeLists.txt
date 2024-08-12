cmake_minimum_required(VERSION 3.5)
project(tictactoe VERSION 1.0 LANGUAGES C CXX)


set(SOURCES
    main.cpp
    src/board.cpp
    src/board.h
    src/bot.cpp
    src/bot.h
)


add_executable(tictactoe ${SOURCES} project.rc)

target_compile_features(tictactoe PRIVATE cxx_std_20)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)./