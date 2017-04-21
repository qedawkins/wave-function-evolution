#include "complex.hpp"
#include <quadmath.h>
#include <cstdio>
#include <type_traits>
#include <cmath>

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

__float128 Complex::magsq() const
{
	return powq(real, 2.0) + powq(im, 2.0);
}
__float128 Complex::mag() const
{
	return sqrtq(this->magsq());
}

void Complex::print() const
{

	int width = 20;

	char real_buf[PRINT_BUFFER_SIZE];
	char im_buf[PRINT_BUFFER_SIZE];
	quadmath_snprintf(real_buf, PRINT_BUFFER_SIZE, "%#*.20Qe", width, real);
	quadmath_snprintf(im_buf, PRINT_BUFFER_SIZE, "%#*.20Qe", width, im);
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
/*
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
*/
/** Arithmetic for bulit-in types **/
template <typename T>
static typename std::enable_if<std::is_scalar<T>::value, int>::type
operator+ (const T& s, const Complex& c)
{
	return Complex(c.real + s, c.im + s);
}
template <typename T>
static typename std::enable_if<std::is_scalar<T>::value, int>::type
operator- (const T& s, const Complex& c)
{
	return Complex(c.real - s, c.im - s);
}
template <typename T>
static typename std::enable_if<std::is_scalar<T>::value, int>::type
operator* (const T& s, const Complex& c)
{
	return Complex(c.real*s,c.im*s);
}
template <typename T>
static typename std::enable_if<std::is_scalar<T>::value, int>::type
operator/ (const T& s, const Complex& c)
{
	return Complex(c.real/s,c.im/s);
}
template <typename T>
static typename std::enable_if<std::is_scalar<T>::value, int>::type
operator^ (const T& s, const Complex& c)
{
	return Complex(s)^c;
}

/** Arithmetic for Complex type **/
Complex operator+ (const Complex& a, const Complex& b)
{
	return Complex(a.real + b.real, a.im + b.im);
}
Complex operator- (const Complex& a, const Complex& b)
{
	return Complex(a.real - b.real, a.im - b.im);
}
Complex operator* (const Complex& a, const Complex& b)
{
	return Complex(a.real * b.real - a.im * b.im,
		a.real * b.im + a.im * b.real);
}
Complex operator/ (const Complex& a, const Complex& b)
{
	return Complex((a.real * b.real + a.im * b.im)/(b.real*b.real + b.im*b.im),
		(a.im*b.real - a.real*b.im)/(b.real*b.real + b.im*b.im));
}
Complex operator^ (const Complex& _a, const Complex& _b)
{

	__complex128 a = 0;
	__complex128 b = 0;
	__real__ a = _a.real;
	__imag__ a = _a.im;
	__real__ b = _b.real;
	__real__ b = _b.im;

	__complex128 c = cpowq(a, b);

	return Complex(
			__real__ c,
			__imag__ c
	);

}
