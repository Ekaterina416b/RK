# Для каждого теста используйте этот шаблон:
add_executable(conceptual_example_tests ConceptualExampleTests.cpp)
target_link_libraries(conceptual_example_tests
    FactoryPattern
    gtest_main  # Изменено с GTest::GTest на gtest_main
)

add_executable(documents_tests DocumentsTests.cpp)
target_link_libraries(documents_tests
    FactoryPattern
    gtest_main
)

add_executable(mobile_phones_tests MobilePhonesTests.cpp)
target_link_libraries(mobile_phones_tests
    FactoryPattern
    gtest_main
)

add_executable(pizzas_tests PizzasTests.cpp)
target_link_libraries(pizzas_tests
    FactoryPattern
    gtest_main
)

add_executable(points_tests PointsTests.cpp)
target_link_libraries(points_tests
    FactoryPattern
    gtest_main
)
