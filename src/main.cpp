#include "ConceptualExample/ConceptualExample.h"
#include "Documents/Documents.h"
#include "MobilePhones/MobilePhones.h"
#include "Pizzas/Pizzas.h"
#include "Points/Points.h"

int main() {
    
    test_conceptual_example();  // Функция объявлена в глобальном пространстве имён
    test_real_world_example_points();  // Функция объявлена в глобальном пространстве имён
    MobilePhonesExample::test_mobile_phones_01();
    MobilePhonesExample::test_mobile_phones_02();
    DocumentsExample::test_documents();
    PizzasExample::test_pizza_01();
    
    return 0;
}
