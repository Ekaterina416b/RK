#include "../src/ConceptualExample/ConceptualExample.h"
#include <gtest/gtest.h>

TEST(ConceptualExampleTest, ShapeCreation) {
    ConceptualExample::ShapeFactory factory;
    
    auto circle = factory.getShape(ConceptualExample::ShapeFactory::ShapeKind::Circle);
    ASSERT_NE(circle, nullptr);
    
    auto rectangle = factory.getShape(ConceptualExample::ShapeFactory::ShapeKind::Rectangle);
    ASSERT_NE(rectangle, nullptr);
    
    auto square = factory.getShape(ConceptualExample::ShapeFactory::ShapeKind::Square);
    ASSERT_NE(square, nullptr);
    
    EXPECT_THROW(factory.getShape(ConceptualExample::ShapeFactory::ShapeKind::None), std::runtime_error);
}

TEST(ConceptualExampleTest, DrawMethods) {
    testing::internal::CaptureStdout();
    
    ConceptualExample::Circle circle;
    circle.draw();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Circle") != std::string::npos);
    
    testing::internal::CaptureStdout();
    ConceptualExample::Rectangle rect;
    rect.draw();
    output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Rectangle") != std::string::npos);
    
    testing::internal::CaptureStdout();
    ConceptualExample::Square square;
    square.draw();
    output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Square") != std::string::npos);
}

TEST(ConceptualExampleTest, TestWithoutFactory) {
    testing::internal::CaptureStdout();
    ConceptualExample::test_without_factory();
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_TRUE(output.find("Rectangle") != std::string::npos);
    EXPECT_TRUE(output.find("Circle") != std::string::npos);
    EXPECT_TRUE(output.find("Square") != std::string::npos);
}

TEST(ConceptualExampleTest, TestWithFactory) {
    testing::internal::CaptureStdout();
    ConceptualExample::test_with_factory();
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_TRUE(output.find("Rectangle") != std::string::npos);
    EXPECT_TRUE(output.find("Circle") != std::string::npos);
    EXPECT_TRUE(output.find("Square") != std::string::npos);
}
