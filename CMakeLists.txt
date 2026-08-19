cmake_minimum_required(VERSION 3.20)

project(opengl-3d-maze LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm CONFIG REQUIRED)

add_executable(opengl-3d-maze
    opengl-3d-maze/src/Camera.cpp
    opengl-3d-maze/src/Game.cpp
    opengl-3d-maze/src/GameLevel.cpp
    opengl-3d-maze/src/GameObject.cpp
    opengl-3d-maze/src/MazeLevel.cpp
    opengl-3d-maze/src/MazeObject.cpp
    opengl-3d-maze/src/ObjectRenderer.cpp
    opengl-3d-maze/src/ResourceManager.cpp
    opengl-3d-maze/src/Shader.cpp
    opengl-3d-maze/src/Texture.cpp
    opengl-3d-maze/src/Window.cpp
    opengl-3d-maze/src/glad.c
    opengl-3d-maze/src/main.cpp
    opengl-3d-maze/include/stb_image/stb_image.cpp
)

target_include_directories(opengl-3d-maze PRIVATE
    opengl-3d-maze/include
    opengl-3d-maze/src
)

target_link_libraries(opengl-3d-maze PRIVATE
    glfw
    OpenGL::GL
    glm::glm
    ${CMAKE_DL_LIBS}
)

if(MSVC)
    target_compile_options(opengl-3d-maze PRIVATE /W3)
else()
    target_compile_options(opengl-3d-maze PRIVATE -Wall -Wextra -Wpedantic)
endif()

add_custom_command(TARGET opengl-3d-maze POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/opengl-3d-maze/assets
        $<TARGET_FILE_DIR:opengl-3d-maze>/assets
)
