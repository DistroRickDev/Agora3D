cmake_minimum_required(VERSION 3.4...3.28 FATAL_ERROR)
project(game_engine)

include(cmake/git-submodules.cmake)

init_and_update_git_submodules()

set(GLOBAL_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(graphics)
