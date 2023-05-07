cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

project(my_linalg VERSION 0.0.1)

if(SKBUILD)
  message(STATUS "The project is built using scikit-build")
  endif()

# Pybind11
find_package(pybind11 REQUIRED)

pybind11_add_module(_my_linalg pycpp/cpp/my_linalg.cpp)

install(TARGETS _my_linalg DESTINATION pycpp/my_linalg)

