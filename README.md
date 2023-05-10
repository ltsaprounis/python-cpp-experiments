# Python-cpp-experiments
My experiments with C++ extensions for python using pybind11.

**⚠️This code is very WIP and will change frequently and in unpredictable ways⚠️**

# TODOs:
- [X] use scikit-build-core to compile the C++ modules
- [ ] CI pipelines for tests
- [ ] Update Makefile
- [ ] remove sphinx docs (won't ever publish them for this project)

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

