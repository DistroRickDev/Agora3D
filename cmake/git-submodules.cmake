find_package(Git QUIET)

add_custom_target(GIT_SUBMODULE_UPDATE)

function(init_and_update_git_submodules)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    if(NOT EXISTS ${dir}/CMakeLists.txt)
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive --remote
                WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
                COMMAND_ERROR_IS_FATAL ANY)
    endif()
endif()

if(${USE_GLFW})
    add_subdirectory(${CMAKE_SOURCE_DIR}/external/glfw)
elseif(${USE_SDL})
    add_subdirectory(${CMAKE_SOURCE_DIR}/external/sdl)
elseif(${USE_SFML})
    message(STATUS "Using SFML")
    add_subdirectory(${CMAKE_SOURCE_DIR}/external/sfml)
    set(SFML_DIR "${CMAKE_SOURCE_DIR}/external/sfml")
endif()
if(${USE_GLM})
    add_subdirectory(${CMAKE_SOURCE_DIR}/external/glm)
endif()

endfunction()