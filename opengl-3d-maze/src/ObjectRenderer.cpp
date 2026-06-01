#include "ObjectRenderer.h"
#include "Shader.h"

ObjectRenderer::ObjectRenderer(Shader& shader)
{
}

ObjectRenderer::~ObjectRenderer()
{
}

void ObjectRenderer::initRenderData()
{
    float vertices[] = 
    {
        // pos coords          // tex coords
        // Back face
        -0.5f, -0.5f, -0.5f,   0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,   1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,   1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,   1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,   0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,   0.0f, 0.0f,
        // Front face
        -0.5f, -0.5f,  0.5f,   0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,   1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,   1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,   1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,   0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,   0.0f, 0.0f,
        // Left face
        -0.5f,  0.5f,  0.5f,   1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,   1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,   0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,   0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,   0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,   1.0f, 0.0f,
        // Right face
         0.5f,  0.5f,  0.5f,   1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,   1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,   0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,   0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,   0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,   1.0f, 0.0f,
         // Bottom face
         -0.5f, -0.5f, -0.5f,   0.0f, 1.0f,
          0.5f, -0.5f, -0.5f,   1.0f, 1.0f,
          0.5f, -0.5f,  0.5f,   1.0f, 0.0f,
          0.5f, -0.5f,  0.5f,   1.0f, 0.0f,
         -0.5f, -0.5f,  0.5f,   0.0f, 0.0f,
         -0.5f, -0.5f, -0.5f,   0.0f, 1.0f,
         // Top face
         -0.5f,  0.5f, -0.5f,   0.0f, 1.0f,
          0.5f,  0.5f, -0.5f,   1.0f, 1.0f,
          0.5f,  0.5f,  0.5f,   1.0f, 0.0f,
          0.5f,  0.5f,  0.5f,   1.0f, 0.0f,
         -0.5f,  0.5f,  0.5f,   0.0f, 0.0f,
         -0.5f,  0.5f, -0.5f,   0.0f, 1.0f
    };
}
