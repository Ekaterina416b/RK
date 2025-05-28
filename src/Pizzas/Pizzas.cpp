#include "Pizzas.h"

namespace PizzasExample {

    void Pizza::prepare() {}
    void Pizza::bake() {}
    void Pizza::cut() {}
    void Pizza::box() {}

    std::shared_ptr<IPizza> PizzaFactory::createPizza(std::string type) {
        if (type == "cheese") return std::make_shared<CheesePizza>();
        if (type == "pepperoni") return std::make_shared<PepperoniPizza>();
        if (type == "clam") return std::make_shared<ClamPizza>();
        if (type == "veggie") return std::make_shared<VeggiePizza>();
        return nullptr;
    }

    std::shared_ptr<IPizza> orderPizzaEx(std::string type) {
        auto pizza = PizzaFactory::createPizza(type);
        if (pizza) {
            pizza->prepare();
            pizza->bake();
            pizza->cut();
            pizza->box();
        }
        return pizza;
    }

    void test_pizza_01() {
        std::shared_ptr<IPizza> pizza = orderPizzaEx("pepperoni");
    }
}
