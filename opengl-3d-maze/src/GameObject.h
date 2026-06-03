#pragma once
#include "ObjectRenderer.h"

class GameObject
{
public:
    glm::vec3 Position, Size, Velocity, Colour, Rotation;

    bool CanCollide;
    bool Destroyed;

    Texture ObjectTexture;

    GameObject();

    GameObject(
        Texture texture,
        glm::vec3 pos, 
        glm::vec3 size, 
        glm::vec3 colour = glm::vec3(1.0f), 
        glm::vec3 velocity = glm::vec3(0.0f),
        glm::vec3 rotation = glm::vec3(0.0f)
    );

    virtual void Draw(ObjectRenderer& renderer);
};

