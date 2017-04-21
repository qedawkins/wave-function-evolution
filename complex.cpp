#include "complex.hpp"
#include "quadmath.h"
#include <cstdio>

#define PRINT_BUFFER_SIZE 512

Complex::Complex()
{
	real = 0;
	im = 0;
}
Complex::Complex(__float128 const& r, __float128 const& i)
{
	real = r;
	im = i;
}

void Complex::print() const
{

	int width = 20;

	char real_buf[128];
	char im_buf[128];
	quadmath_snprintf(real_buf, 128, "%+-#*.20Qe", width, real);
	quadmath_snprintf(im_buf, 128, "%+-#*.20Qe", width, im);
	printf("%s + %si\n", real_buf, im_buf);

}

Complex Complex::operator=(Complex const& other)
{
	return Complex(other.real, other.im);
}
Complex Complex::operator+(Complex const& other)
{
	return Complex(this->real + other.real, this->im + other.im);
}
void Complex::operator+=(Complex const& other)
{
	this->real += other.real;
	this->im += other.im;
}
