cmake_minimum_required(VERSION 3.14)
project(FactoryPattern)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Надежный способ подключения GTest
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG main  # Используем main вместо конкретной версии
)
FetchContent_MakeAvailable(googletest)

# Включаем модуль GoogleTest
include(GoogleTest)

# Основная библиотека
add_library(FactoryPattern STATIC
    src/ConceptualExample/ConceptualExample.cpp
    src/Documents/Documents.cpp
    src/MobilePhones/MobilePhones.cpp
    src/Pizzas/Pizzas.cpp
    src/Points/Points.cpp
)

target_include_directories(FactoryPattern PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Основной исполняемый файл
add_executable(factory_pattern src/main.cpp)
target_link_libraries(factory_pattern FactoryPattern)

# Тесты
enable_testing()
add_subdirectory(tests)
