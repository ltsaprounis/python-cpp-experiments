# Python-cpp-experiments
My experiments with C++ extensions for python using pybind11.

# Notes:
To build the cpp package execute the following:
- `mkdir build`
- `cd build` 
- `cmake .. -DPYTHON_EXECUTABLE=$(python3 -c "import sys; print(sys.executable)") -DCMAKE_INSTALL_PREFIX:PATH=..`
- `make install`

The python module will be located in the build folder.

Notes:
- -DCMAKE_INSTALL_PREFIX:PATH is set to .. to make the path in the install command in
the CMakeLists.txt file relative to the location of the file.
- The pyproject.toml file contains a section for scikit-build `[tool.scikit-build]`. There 
there are some settings that are there to help in development and should be changed in the future.
Namely build-dir should be changed to "" instead of "build" and logging should be at WARNING level.
- Editable installs work fine with scikit-build-core so far. There are some settings that I could borrow in
https://github.com/scikit-build/scikit-build-core in the Configuration section in the README.md.

