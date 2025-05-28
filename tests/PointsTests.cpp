#include "../src/Points/Points.h"
#include <gtest/gtest.h>
#include <cmath>

constexpr double EPSILON = 0.0001;

TEST(PointsTest, Factory03Cartesian) {
    auto point = Factory03::Point::NewCartesian(3.0, 4.0);
    std::ostringstream oss;
    oss << point;
    EXPECT_EQ(oss.str(), "x: 3 y: 4");
}

TEST(PointsTest, Factory03Polar) {
    auto point = Factory03::Point::NewPolar(5.0, M_PI_4); // 45 degrees
    std::ostringstream oss;
    oss << point;
    // 5 * cos(π/4) ≈ 3.53553, 5 * sin(π/4) ≈ 3.53553
    EXPECT_TRUE(oss.str().find("3.53553") != std::string::npos);
}

TEST(PointsTest, Factory04Cartesian) {
    auto point = Factory04::PointFactory::NewCartesian(2.5, 3.5);
    std::ostringstream oss;
    oss << point;
    EXPECT_EQ(oss.str(), "x: 2.5 y: 3.5");
}

TEST(PointsTest, Factory04Polar) {
    auto point = Factory04::PointFactory::NewPolar(10.0, M_PI/6); // 30 degrees
    std::ostringstream oss;
    oss << point;
    // 10 * cos(π/6) ≈ 8.66025, 10 * sin(π/6) = 5.0
    EXPECT_TRUE(oss.str().find("8.66025") != std::string::npos);
    EXPECT_TRUE(oss.str().find("5") != std::string::npos);
}

TEST(PointsTest, Factory05Cartesian) {
    auto point = Factory05::Point::Factory::NewCartesian(-1.0, 1.0);
    std::ostringstream oss;
    oss << point;
    EXPECT_EQ(oss.str(), "x: -1 y: 1");
}

TEST(PointsTest, Factory05Polar) {
    auto point = Factory05::Point::Factory::NewPolar(2.0, M_PI/3); // 60 degrees
    std::ostringstream oss;
    oss << point;
    // 2 * cos(π/3) = 1.0, 2 * sin(π/3) ≈ 1.73205
    EXPECT_TRUE(oss.str().find("1") != std::string::npos);
    EXPECT_TRUE(oss.str().find("1.73205") != std::string::npos);
}
