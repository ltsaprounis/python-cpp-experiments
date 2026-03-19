# Python-cpp-experiments
My experiments with C++ extensions for python using pybind11.

<img width="1428" alt="python_braces" src="https://github.com/ltsaprounis/python-cpp-experiments/assets/64217214/a04a3f1a-5efe-4d5d-a546-cdbc245b21cc">  

&nbsp;

**⚠️This code is very WIP and will change frequently and in unpredictable ways⚠️**

# Prerequisites

- **Python 3.8–3.10** with `pip` (version 22+ recommended for editable installs)
- **CMake** (>= 3.16)
- **Armadillo** C++ linear algebra library — install via your package manager:
  - macOS: `brew install armadillo`
  - Ubuntu/Debian: `sudo apt install libarmadillo-dev`
- **A C++17 compiler** (e.g. AppleClang, GCC, MSVC)

# Build

## Option 1: scikit-build-core (recommended)

1. Initialize git submodules (required for carma):

   ```bash
   git submodule update --init --recursive
   ```

2. Install the project in editable mode:

   ```bash
   pip install -e ".[dev]"
   ```

## Option 2: Manual cmake build

1. Initialize git submodules (required for carma):

   ```bash
   git submodule update --init --recursive
   ```

2. Install Python build dependencies:

   ```bash
   pip install "pybind11[global]>=2.6.0" "numpy>=1.14"
   ```

3. Build with cmake:

   ```bash
   mkdir build
   cd build
   cmake .. -DPYTHON_EXECUTABLE=$(python3 -c "import sys; print(sys.executable)") -DCMAKE_INSTALL_PREFIX:PATH=..
   make install
   ```

   > **Note:** `-DCMAKE_INSTALL_PREFIX:PATH` is set to `..` to make the path in the install
   > command in the CMakeLists.txt file relative to the location of the file.

# TODOs:
- [X] use scikit-build-core to compile the C++ modules
- [X] CI pipelines for tests
- [X] Update Makefile
- [X] remove sphinx docs (won't ever publish them for this project)
- [ ] Check how to automate the Armadillo installation either as a github submodule or using [cmake's FetchContent](https://cmake.org/cmake/help/latest/module/FetchContent.html#fetchcontent) like in [carma](https://github.com/RUrlus/carma/blob/2fbc2e6faf2e40e41003c06cbb13744405732b5f/integration_test/CMakeLists.txt#L36)
