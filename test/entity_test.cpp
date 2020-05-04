#include <gtest/gtest.h>
#include "../include/entity.hpp"

TEST (EntityTest, SingleTest)
{
    ::spiritualizer::Entity entity;
    EXPECT_EQ(entity.Position(), glm::vec3({0,0,0}));
    EXPECT_EQ(entity.Position().x, 0);
    EXPECT_EQ(entity.Position().y, 0);
    EXPECT_EQ(entity.Position().z, 0);
}

TEST (EntityTest, ManyTest)
{
    using ::spiritualizer::Entity;

    //std::span<Entity> entity_span;
    EXPECT_EQ(0, 0);
}