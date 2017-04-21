#include <string>
#include <vector>
#include <fftw3.h>
#include "complex.hpp"
#include <cstdio>

using std::vector;

int main(int argc, char** argv)
{

	printf("Testing complex number printing...\n");

	int a = 60;
	int b = 125;
	printf("Should read: %d + %di\n", a, b);
	Complex c(a, b);
	c.print();
	printf("Done\n");

    return 0;

}
