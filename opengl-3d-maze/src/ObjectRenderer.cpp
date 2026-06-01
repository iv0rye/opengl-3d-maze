#include "ObjectRenderer.h"
#include "Shader.h"
#include <glad/glad.h>
#include <glm/ext/matrix_transform.hpp>

ObjectRenderer::ObjectRenderer(Shader shader) : shader(shader)
{
    initRenderData();
}

ObjectRenderer::~ObjectRenderer()
{
    glDeleteVertexArrays(1, &this->VAO);
}

void ObjectRenderer::DrawObject(Texture& texture, glm::vec3 position, glm::vec3 size, glm::vec3 rotate, glm::vec3 colour)
{
    this->shader.Use();

    glm::mat4 model = glm::mat4(1.0f);

    // final translation
    model = glm::translate(model, position);

    // rotation
    model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.5f * size.z));

    // TODO: make it a quartenion to avoid gimbal lock pls!!!
    model = glm::rotate(model, rotate.x, glm::vec3(1, 0, 0));
    model = glm::rotate(model, rotate.y, glm::vec3(0, 1, 0));
    model = glm::rotate(model, rotate.z, glm::vec3(0, 0, 1));

    model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, -0.5f * size.z));

    // scale
    model = glm::scale(model, size);

    // set uniforms, draw object
    this->shader.SetMat4D("model", model);
    this->shader.SetVec3D("objectColour", colour);

    glActiveTexture(GL_TEXTURE0);
    texture.Bind();

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
}

void ObjectRenderer::DrawObject(glm::vec3 position, glm::vec3 size, glm::vec3 rotate, glm::vec3 colour)
{
    this->shader.Use();

    glm::mat4 model = glm::mat4(1.0f);

    // final translation
    model = glm::translate(model, position);

    // rotation
    model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.5f * size.z));

    // TODO: make it a quartenion to avoid gimbal lock pls!!!
    model = glm::rotate(model, rotate.x, glm::vec3(1, 0, 0));
    model = glm::rotate(model, rotate.y, glm::vec3(0, 1, 0));
    model = glm::rotate(model, rotate.z, glm::vec3(0, 0, 1));

    model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, -0.5f * size.z));

    // scale
    model = glm::scale(model, size);

    // set uniforms, draw object
    this->shader.SetMat4D("model", model);
    this->shader.SetVec3D("objectColour", colour);

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
}

unsigned int ObjectRenderer::GetShaderId() const
{
    return this->shader.ID;
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

    // bind to none
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
