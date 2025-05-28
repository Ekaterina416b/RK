cmake_minimum_required(VERSION 3.10)
project(FactoryPattern)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включение автоматической загрузки GTest
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

# Main library
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

# Main executable
add_executable(factory_pattern src/main.cpp)
target_link_libraries(factory_pattern FactoryPattern)

# Tests
enable_testing()
add_subdirectory(tests)
