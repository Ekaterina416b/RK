cmake_minimum_required(VERSION 3.14)
project(FactoryPattern)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Надежный способ подключения GTest
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.13.0  # Используем проверенную версию
)
FetchContent_MakeAvailable(googletest)

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

# CPack Configuration
include(InstallRequiredSystemLibraries)

set(CPACK_PACKAGE_NAME "factorypattern")
set(CPACK_PACKAGE_VENDOR "MyVendor")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Factory Pattern Example")
set(CPACK_PACKAGE_VERSION "1.0.0")

# Обязательные поля для DEB пакета
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Your Name <your.email@example.com>")  # <- ДОБАВЬТЕ ЭТО
set(CPACK_PACKAGE_CONTACT "Your Name <your.email@example.com>")  # Альтернативный вариант

# Debian-specific settings
set(CPACK_GENERATORS "DEB")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libstdc++6")
set(CPACK_DEBIAN_PACKAGE_SECTION "devel")
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")

# Установка файлов
install(TARGETS factory_pattern RUNTIME DESTINATION bin)
install(TARGETS FactoryPattern LIBRARY DESTINATION lib)
install(DIRECTORY src/ DESTINATION include/FactoryPattern FILES_MATCHING PATTERN "*.h")

include(CPack)
