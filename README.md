# Quantum State Evolution
## Installation
Execute `cmake .` in the root of the project to generate the Makefile. You may need to install FFTW3 for CMake to complete.
To compile the code, run `make`.
To install the code for the entire system, run `make install` after running `make`.
## Post-installation
To clean CMake installation files, you can use `clean_cmake.sh`.
## Options
Passing `-DNO_QUADMATH=TRUE` to cmake will prevent linkage to libquadmath.
