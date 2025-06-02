cmake_minimum_required(VERSION 3.0)
# project(MyTests) # Не нужно, если это поддиректория и проект уже определен в главном CMakeLists.txt

# include_directories(${PROJECT_SOURCE_DIR}/src)

# Создание исполняемых файлов тестов И регистрация для ctest:
add_executable(conceptual_example_tests ConceptualExampleTests.cpp)
target_link_libraries(conceptual_example_tests FactoryPattern gtest_main)
add_test(NAME conceptual_example_tests_run COMMAND conceptual_example_tests)

add_executable(documents_tests DocumentsTests.cpp)
target_link_libraries(documents_tests FactoryPattern gtest_main)
add_test(NAME documents_tests_run COMMAND documents_tests)

add_executable(mobile_phones_tests MobilePhonesTests.cpp)
target_link_libraries(mobile_phones_tests FactoryPattern gtest_main)
add_test(NAME mobile_phones_tests_run COMMAND mobile_phones_tests)

add_executable(pizzas_tests PizzasTests.cpp)
target_link_libraries(pizzas_tests FactoryPattern gtest_main)
add_test(NAME pizzas_tests_run COMMAND pizzas_tests)

add_executable(points_tests PointsTests.cpp)
target_link_libraries(points_tests FactoryPattern gtest_main)
add_test(NAME points_tests_run COMMAND points_tests)
