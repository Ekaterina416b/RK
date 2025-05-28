# ConceptualExample tests
add_executable(conceptual_example_tests ConceptualExampleTests.cpp)
target_link_libraries(conceptual_example_tests 
    FactoryPattern 
    gtest_main
)
gtest_discover_tests(conceptual_example_tests)

# Documents tests
add_executable(documents_tests DocumentsTests.cpp)
target_link_libraries(documents_tests 
    FactoryPattern 
    gtest_main
)
gtest_discover_tests(documents_tests)

# MobilePhones tests
add_executable(mobile_phones_tests MobilePhonesTests.cpp)
target_link_libraries(mobile_phones_tests 
    FactoryPattern 
    gtest_main
)
gtest_discover_tests(mobile_phones_tests)

# Pizzas tests
add_executable(pizzas_tests PizzasTests.cpp)
target_link_libraries(pizzas_tests 
    FactoryPattern 
    gtest_main
)
gtest_discover_tests(pizzas_tests)

# Points tests
add_executable(points_tests PointsTests.cpp)
target_link_libraries(points_tests 
    FactoryPattern 
    gtest_main
)
gtest_discover_tests(points_tests)
