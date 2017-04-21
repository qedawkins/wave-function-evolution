#include "complex.hpp"
#include <quadmath.h>
#include <cstdio>

#define PRINT_BUFFER_SIZE 128

Complex::Complex()
{
	real = 0;
	im = 0;
}
Complex::Complex(__float128 const& r)
{
	real = r;
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

	char real_buf[PRINT_BUFFER_SIZE];
	char im_buf[PRINT_BUFFER_SIZE];
	quadmath_snprintf(real_buf, PRINT_BUFFER_SIZE, "%+-#*.20Qe", width, real);
	quadmath_snprintf(im_buf, PRINT_BUFFER_SIZE, "%+-#*.20Qe", width, im);
	printf("%s + %si\n", real_buf, im_buf);

}

void Complex::operator=(Complex const& other)
{
	this->real = other.real;
	this->im = other.im;
}

void Complex::operator+=(Complex const& other)
{
	this->real += other.real;
	this->im += other.im;
}

void Complex::operator-=(Complex const& other)
{
	this->real -= other.real;
	this->im -= other.im;
}

Complex Complex::operator+(Complex const& other)
{
	return Complex(this->real + other.real, this->im + other.im);
}

Complex Complex::operator-(Complex const& other)
{
	return Complex(this->real - other.real, this->im - other.im);
}

Complex Complex::operator*(Complex const& other)
{
	return Complex(this->real * other.real - this->im * other.im, 
		this->real * other.im + this->im * other.real);
}

Complex Complex::operator/(Complex const& other)
{
	return Complex((this->real * other.real + this->im * other.im)/(other.real*other.real + other.im*other.im),
		(this->im*other.real - this->real*other.im)/(other.real*other.real + other.im*other.im));
}
template <typename T>
Complex operator+ (const T& s, const Complex& c)
{
	return Complex(c.real + s, c.im + s);
}
template <typename T>
Complex operator- (const T& s, const Complex& c)
{
	return Complex(c.real - s, c.im - s);
}
template <typename T>
Complex operator* (const T& s, const Complex& c)
{
	return Complex(c.real*s,c.im*s);
}
template <typename T>
Complex operator/ (const T& s, const Complex& c)
{
	return Complex(c.real/s,c.im/s);
}
