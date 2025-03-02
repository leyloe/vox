cmake_minimum_required(VERSION 3.30)

project(vox)

set(SOURCE_DIR Source)
set(INCLUDE_DIR Include)
set(THIRD_PARTY_SOURCE_DIR ThirdParty)

set(INCLUDES ${SOURCE_DIR} ${INCLUDE_DIR})

set(SOURCES
    ${THIRD_PARTY_SOURCE_DIR}/glad/glad.c
    ${THIRD_PARTY_SOURCE_DIR}/stb/stb.c
    ${SOURCE_DIR}/Main.cpp
    ${SOURCE_DIR}/App.cpp
    ${SOURCE_DIR}/Engine/Window.cpp
    ${SOURCE_DIR}/Engine/GraphicsContext.cpp
    ${SOURCE_DIR}/Engine/EBO.cpp
    ${SOURCE_DIR}/Engine/VBO.cpp
    ${SOURCE_DIR}/Engine/VAO.cpp
    ${SOURCE_DIR}/Engine/Shader.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

target_link_libraries(${PROJECT_NAME}
    glfw
    glm::glm
)

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDES})