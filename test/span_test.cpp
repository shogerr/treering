#include <gtest/gtest.h>
#include <span>

TEST (SpanTest, BasicTest)
{

    auto update_span = [](std::span<double> &xs) {
        for (auto &x: xs)
            x += 1;
    };

    EXPECT_EQ(0, 0);
}
