# Включение GoogleTest
find_package(GTest REQUIRED)
include(GoogleTest)

# ConceptualExample tests
add_executable(conceptual_example_tests ConceptualExampleTests.cpp)
target_link_libraries(conceptual_example_tests FactoryPattern GTest::GTest GTest::Main)
add_test(NAME ConceptualExampleTest COMMAND conceptual_example_tests)

# Documents tests
add_executable(documents_tests DocumentsTests.cpp)
target_link_libraries(documents_tests FactoryPattern GTest::GTest GTest::Main)
add_test(NAME DocumentsTest COMMAND documents_tests)

# MobilePhones tests
add_executable(mobile_phones_tests MobilePhonesTests.cpp)
target_link_libraries(mobile_phones_tests FactoryPattern GTest::GTest GTest::Main)
add_test(NAME MobilePhonesTest COMMAND mobile_phones_tests)

# Pizzas tests
add_executable(pizzas_tests PizzasTests.cpp)
target_link_libraries(pizzas_tests FactoryPattern GTest::GTest GTest::Main)
add_test(NAME PizzasTest COMMAND pizzas_tests)

# Points tests
add_executable(points_tests PointsTests.cpp)
target_link_libraries(points_tests FactoryPattern GTest::GTest GTest::Main)
add_test(NAME PointsTest COMMAND points_tests)