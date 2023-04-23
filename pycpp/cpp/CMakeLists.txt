cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

project(my_linalg VERSION 0.0.1)

# Pybind11
find_package(pybind11 REQUIRED)
pybind11_add_module(my_linalg my_linalg.cpp)

# add CARMA as a subdirectory
# add_subdirectory(carma)
# target_link_libraries(my_linalg PRIVATE carma::carma)

