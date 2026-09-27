cmake_minimum_required(VERSION 3.24)

project(opengl-3d-maze LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---- dependencies (downloaded automatically at configure time) ----
include(FetchContent)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.4
    GIT_SHALLOW TRUE
)

FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG 1.0.1
    GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(glfw glm)

find_package(OpenGL REQUIRED)

# ---- game executable ----
set(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/opengl-3d-maze)

file(GLOB GAME_SOURCES CONFIGURE_DEPENDS
    ${PROJECT_DIR}/src/*.cpp
    ${PROJECT_DIR}/src/*.c
    ${PROJECT_DIR}/src/*.h
)

add_executable(opengl-3d-maze
    ${GAME_SOURCES}
    ${PROJECT_DIR}/include/stb_image/stb_image.cpp
)

# glad, KHR and stb_image are vendored in the repo
target_include_directories(opengl-3d-maze PRIVATE ${PROJECT_DIR}/include)

target_link_libraries(opengl-3d-maze PRIVATE glfw glm::glm OpenGL::GL)

# assets are loaded with relative paths ("assets/..."), so copy them next to the executable
add_custom_command(TARGET opengl-3d-maze POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_DIR}/assets
        $<TARGET_FILE_DIR:opengl-3d-maze>/assets
)

# run from the executable's folder when debugging in Visual Studio
set_target_properties(opengl-3d-maze PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY $<TARGET_FILE_DIR:opengl-3d-maze>
)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT opengl-3d-maze)
