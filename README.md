# Python-cpp-experiments
My experiments with C++ extensions for python using pybind11.

# Notes:
To build the cpp package execute the following:
- `cd pycpp/cpp`
- `mkdir build`
- `cd build` 
- `cmake .. -DPYTHON_EXECUTABLE=$(python3 -c "import sys; print(sys.executable)") -DCMAKE_INSTALL_PREFIX:PATH=..`
- `make`

The python module will be located in the build folder.

Notes:
- -DCMAKE_INSTALL_PREFIX:PATH is set to .. to make the path in the install command in
the CMakeLists.txt file relative to the location of the file.

