// example.cpp: Leonidas Tsaprounis
// Description: the example from https://pybind11.readthedocs.io/en/stable/basics.html#first-steps 
// To compile and use as a python module:
// $ c++ -O3 -Wall -shared -std=c++11 -undefined dynamic_lookup $(python3 -m pybind11 --includes) example.cpp -o example$(python3-config --extension-suffix)

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
namespace py = pybind11;

int add(int i, int j) {
  return i + j;
}

float dot_product(py::array_t<double> arr1, py::array_t<double> arr2) {
  float result = 0;
  py::buffer_info buff1 = arr1.request();
  py::buffer_info buff2 = arr2.request();
  int length = buff1.shape[0];
  double *ptr1 = (double *) buff1.ptr;
  double *ptr2 = (double *) buff2.ptr; 
  for (int i=0; i<length; i++) {
    result += ptr1[i] * ptr2[i];
  }
  return result;
}

py::array_t<double> array_sum(py::array_t<double> arr1, py::array_t<double> arr2) {
  py::buffer_info buff1 = arr1.request();
  py::buffer_info buff2 = arr2.request();
  int length = buff1.shape[0];
  // define the result variable. 
  py::array_t<double> result = py::array_t<double>(buff1.size);
  py::buffer_info buff_result = result.request();
  double *ptr1 = (double *) buff1.ptr;
  double *ptr2 = (double *) buff2.ptr; 
  double *ptr3 = (double *) buff_result.ptr; 
  #pragma omp parallel for simd
  for (int i=0; i<length; i++) {
    ptr3[i] = ptr1[i] + ptr2[i]; 
  }
  return result;
}


PYBIND11_MODULE(_my_linalg, m) {
  m.doc() = "pybind11 example plugin"; // module docstring
  m.attr("example_attr") = "An example attr";
  m.def("add", &add, "A function that adds two numbers", py::arg("i"), py::arg("j"));
  m.def(
    "dot_product",
    &dot_product,
    "dot product of 2 simple numpy arrays",
    py::arg("arr1"),
    py::arg("arr2")
  );
  m.def(
    "array_sum",
    &array_sum,
    "Sums 2 numpy arrays",
    py::arg("arr1"),
    py::arg("arr2")
  );
}

