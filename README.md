# Python-cpp-experiments
My experiments with C++ extensions for python using pybind11.

<img width="1428" alt="python_braces" src="https://github.com/ltsaprounis/python-cpp-experiments/assets/64217214/a04a3f1a-5efe-4d5d-a546-cdbc245b21cc">  

&nbsp;

**⚠️This code is very WIP and will change frequently and in unpredictable ways⚠️**

# Notes:
To build the cpp package execute the following:
- `mkdir build`
- `cd build` 
- `cmake .. -DPYTHON_EXECUTABLE=$(python3 -c "import sys; print(sys.executable)") -DCMAKE_INSTALL_PREFIX:PATH=..`
- `make install`

To build the project using [scikit-build-core](https://github.com/scikit-build/scikit-build-core) simply do `pip install -e .`

Notes:
- -DCMAKE_INSTALL_PREFIX:PATH is set to .. to make the path in the install command in
the CMakeLists.txt file relative to the location of the file.

# TODOs:
- [X] use scikit-build-core to compile the C++ modules
- [X] CI pipelines for tests
- [X] Update Makefile
- [X] remove sphinx docs (won't ever publish them for this project)
- [ ] Check how to automate the Armadillo installation either as a github submodule or using [cmake's FetchContent](https://cmake.org/cmake/help/latest/module/FetchContent.html#fetchcontent) like in [carma](https://github.com/RUrlus/carma/blob/2fbc2e6faf2e40e41003c06cbb13744405732b5f/integration_test/CMakeLists.txt#L36)
