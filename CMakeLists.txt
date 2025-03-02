cmake_minimum_required(VERSION 3.30)

project(vox)

set(SOURCE_DIR Source)
set(INCLUDE_DIR Include)

set(INCLUDES ${SOURCE_DIR} ${INCLUDE_DIR})

set(SOURCES
    ${SOURCE_DIR}/glad.c
    ${SOURCE_DIR}/Main.cpp
    ${SOURCE_DIR}/App.cpp
    ${SOURCE_DIR}/Engine/Window.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

target_link_libraries(${PROJECT_NAME}
    glfw
    glm::glm
)

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDES})