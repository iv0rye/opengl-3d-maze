# OpenGL 3D Maze
My first program made in OpenGL, made with GLFW and OpenGL from scratch in C++ to render a traversable maze. 

Implemented with OOP, in a game engine structure.

## Containerized developer environment (recommended)
This repository now includes a Dev Container in `.devcontainer/` with all required build dependencies preinstalled.

1. Clone this repository.
2. Open the folder in VS Code.
3. Run **Dev Containers: Reopen in Container**.
4. Build from inside the container:
   ```bash
   cmake -S . -B build -G Ninja
   cmake --build build
   ```
5. Run:
   ```bash
   ./build/opengl-3d-maze
   ```

## Local build dependencies
This project depends on:
- [GLFW](https://www.glfw.org/)
- [GLM](https://github.com/g-truc/glm)
- OpenGL development libraries

For Linux/macOS builds, CMake is provided at repo root (`CMakeLists.txt`).

For a more comprehensive OpenGL setup guide, refer to https://learnopengl.com/Getting-started/Creating-a-window.

## Visual Studio workflow (existing)
If you prefer the existing Visual Studio solution:
1. Clone repo
2. Ensure dependencies are available to the VS solution
3. Build `opengl-3d-maze.slnx`
4. Run
