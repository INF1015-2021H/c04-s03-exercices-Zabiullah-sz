cmake_minimum_required(VERSION 3.0.0)
# La raison pour laquelle on fait une variable d'environnement VCPKG_ROOT.
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

# Le nom du projet.
project(Exercices)

# On met les fichiers sources (incluant les entêtes)
set(ALL_FILES
    "main.cpp"
    "Employee.hpp"
    "Employee.cpp"
    "Company.hpp"
    "Company.cpp"
    "tuples.hpp"
    "tuples.cpp")

add_executable(${PROJECT_NAME} ${ALL_FILES})

# Les flags de compilation. Ceux-ci reproduisent un peu le comportement de MSVC avec /W4.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -fsigned-char -Wall -Wextra -Wpedantic -Woverloaded-virtual -Wno-unknown-pragmas -Wno-enum-compare")

# Tous les package Vcpkg. Pour savoir quoi mettre, on fait "vcpkg install <le package>", puis on met ce qu'ils disent de mettre dans le CMakeLists.
find_package(cppitertools CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE cppitertools::cppitertools)
