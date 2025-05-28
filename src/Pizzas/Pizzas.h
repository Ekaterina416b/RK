#ifndef PIZZAS_H
#define PIZZAS_H

#include <memory>
#include <string>

namespace PizzasExample {

    class IPizza {
    public:
        virtual ~IPizza() = default;
        virtual void prepare() = 0;
        virtual void bake() = 0;
        virtual void cut() = 0;
        virtual void box() = 0;
    };

    class Pizza : public IPizza {
    public:
        void prepare() override;
        void bake() override;
        void cut() override;
        void box() override;
    };

    class CheesePizza : public Pizza {};
    class GreekPizza : public Pizza {};
    class PepperoniPizza : public Pizza {};
    class ClamPizza : public Pizza {};
    class VeggiePizza : public Pizza {};

    class PizzaFactory {
    public:
        static std::shared_ptr<IPizza> createPizza(std::string type);
    };

    std::shared_ptr<IPizza> orderPizzaEx(std::string type);
    void test_pizza_01();
}

#endif // PIZZAS_H
