#include "complex.hpp"
#include "quadmath.h"
#include <cstdio>

#define PRINT_BUFFER_SIZE 512

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
