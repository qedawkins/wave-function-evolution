#include "complex.hpp"
#include <cstdio>

int main(int argc, char** argv)
{

	printf("Testing complex number printing...\n");

	int a = 60;
	int b = 125;
	printf("Should read: %d + %di\n", a, b);
	Complex co(a, b);
	co.print();
	printf("Done\n");

	printf("Testing complex number addition...\n");

	int c = 720;
	int d = 230;

	Complex ca1(a, b);
	Complex ca2(c, d);
	Complex ca3;

	ca1.print();
	ca2.print();
	printf(">>> Summed together: ");
	ca3 = ca1+ca2;
	ca3.print();
	ca3 += ca2;
	ca3.print();
	ca3 -= (ca1 + ca2 * 2);
	ca3.print();

	printf("Testing use of I...\n");
	I.print();

	printf("Done\n");


	return 0;

}
