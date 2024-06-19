project(sfml-window-manager)

add_library(${PROJECT_NAME} SfmlWindowManager.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${SFML_DIR} ${WINDOW_MANAGER_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Graphics)