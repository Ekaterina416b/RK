#include "../src/Pizzas/Pizzas.h"
#include <gtest/gtest.h>
#include <memory>

TEST(PizzasTest, PizzaBaseMethods) {
    PizzasExample::Pizza pizza;
    // Just verify the methods can be called without crashing
    EXPECT_NO_THROW(pizza.prepare());
    EXPECT_NO_THROW(pizza.bake());
    EXPECT_NO_THROW(pizza.cut());
    EXPECT_NO_THROW(pizza.box());
}

TEST(PizzasTest, FactoryCreationValidTypes) {
    auto cheese = PizzasExample::PizzaFactory::createPizza("cheese");
    EXPECT_NE(cheese, nullptr);

    auto pepperoni = PizzasExample::PizzaFactory::createPizza("pepperoni");
    EXPECT_NE(pepperoni, nullptr);

    auto clam = PizzasExample::PizzaFactory::createPizza("clam");
    EXPECT_NE(clam, nullptr);

    auto veggie = PizzasExample::PizzaFactory::createPizza("veggie");
    EXPECT_NE(veggie, nullptr);
}

TEST(PizzasTest, FactoryCreationInvalidType) {
    auto invalid = PizzasExample::PizzaFactory::createPizza("invalid");
    EXPECT_EQ(invalid, nullptr);
}

TEST(PizzasTest, OrderPizzaProcess) {
    testing::internal::CaptureStdout();
    auto pizza = PizzasExample::orderPizzaEx("pepperoni");
    std::string output = testing::internal::GetCapturedStdout();
    // No output expected since methods are empty, just verify pizza was created
    EXPECT_NE(pizza, nullptr);
}
