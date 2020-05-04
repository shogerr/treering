#pragma once
#include <glm/glm.hpp>

namespace spiritualizer
{

class Entity
{
public:
    Entity() : position_({0.,0.,0.}) {}
    glm::vec3 Position() { return position_; }
private:
    glm::vec3 position_;
};

}
