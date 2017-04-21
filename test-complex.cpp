#include "complex.hpp"
#include <quadmath.h>
#include <cstdio>
#include <cmath>


int main(int argc, char** argv)
{

	Complex a = genComplex(M_E, 0);
	Complex b = genComplex(0, 1);
	Complex c = cpowq(a, b * M_PI);

	cprint(c);

}
