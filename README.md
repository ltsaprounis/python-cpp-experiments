# Python-cpp-experiments
Repo containing my experiments with writting C++ extensions for python with pybind11.

# Notes:
To build the cpp package execute the following:
- `cd pycpp/cpp`
- `mkdir build`
- `cd build` 
- `cmake .. -DPYTHON_EXECUTABLE=$(python3 -c "import sys; print(sys.executable)")`
- `make`

The python module will be located in the build folder.

