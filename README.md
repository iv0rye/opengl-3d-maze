# OpenGL 3D Maze
My first program made in OpenGL, made with GLFW and OpenGL from scratch in C++ to render a traversable maze. 

Implemented with OOP, in a game engine structure.

## Dependencies
Dependencies are handled by CMake, so nothing needs installing by hand:
- [GLFW](https://www.glfw.org/) and [GLM](https://github.com/g-truc/glm) are downloaded automatically when CMake configures the project.
- [glad](https://glad.dav1d.de/) and [stb_image](https://github.com/nothings/stb) are included in the repo.

You only need [CMake](https://cmake.org/download/) (3.24+), Git, and a C++20 compiler (e.g. Visual Studio with the "Desktop development with C++" workload).

## How to Run
### Visual Studio
1. Clone the repo
2. In Visual Studio, choose **File > Open > Folder** and open the repo folder (VS detects `CMakeLists.txt`)
3. Select `opengl-3d-maze.exe` as the startup item and run

### Command line
```
cmake -S . -B build
cmake --build build --config Debug
```
Then run `build/Debug/opengl-3d-maze.exe`. Assets are copied next to the executable on each build.
