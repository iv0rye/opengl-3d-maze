#include "ObjectRenderer.h"
#include "Shader.h"
#include <glad/glad.h>

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

    unsigned int VBO;

    // gen and bind buffers
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &this->VAO);

    glBindVertexArray(this->VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // set up vertex attrib pointers
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
