#ifndef COMPLEX_H
#define COMPLEX_H

#ifdef IS_CLANG_BUILD

#include <cmath>

typedef __complex64 Complex;
typedef __float64 Float;

Complex cpowq(Complex, Complex);

#else

#include <quadmath.h>

typedef __complex128 Complex;
typedef __float128 Float;
//typedef __complex64 Complex;
//typedef long double complex Complex;

#endif

void cprint(Complex const&);

Complex genComplex(Float const&, Float const&);

#endif // COMPLEX_H
