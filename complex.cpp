#include "complex.hpp"
#include <quadmath.h>
#include <cstdio>

#define PRINT_BUFFER_SIZE 128

void cprint(Complex const& c)
{

	int width = 20;

	char real_buf[PRINT_BUFFER_SIZE];
	char im_buf[PRINT_BUFFER_SIZE];
	quadmath_snprintf(real_buf, PRINT_BUFFER_SIZE, "%#*.20Qe", width, __real__ c);
	quadmath_snprintf(im_buf, PRINT_BUFFER_SIZE, "%#*.20Qe", width, __imag__ c);
	printf("%s + %si\n", real_buf, im_buf);

}

Complex genComplex(Float const& a, Float const& b)
{
	Complex c;
	__real__ c = a;
	__imag__ c = b;
	return c;
}


/*
 * Clang re-definitions of quadmath functions
 */
Complex cpowq(Complex a, Complex b)
{
	return 0;
}
