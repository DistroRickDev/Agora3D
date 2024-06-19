project(window-manager)

set(WINDOW_MANAGER_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

if(${USE_SFML})
    add_subdirectory(sfml-window-manager)
endif()