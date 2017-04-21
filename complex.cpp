#include "complex.hpp"
#include <quadmath.h>
#include <cstdio>
#include <type_traits>

#define PRINT_BUFFER_SIZE 128

#define re(Z) __real__ Z
#define im(Z) __imag__ Z

Complex::Complex()
{
	raw = 0;
}
Complex::Complex(_float const& r)
{
	raw = r;
}
Complex::Complex(_float const& r, _float const& i)
{
	re(raw) = r;
	im(raw) = i;
}
Complex::Complex(_complex const& z)
{
	raw = z;
}

_float Complex::magsq() const
{
#ifdef USING_QUADMATH
	return powq(re(raw), 2.0) + powq(im(raw), 2.0);
#else
	return pow(re(raw), 2.0) + pow(im(raw), 2.0);
#endif
}
_float Complex::mag() const
{
#ifdef USING_QUADMATH
	return sqrtq(this->magsq());
#else
	return sqrt(this->magsq());
#endif
}

void Complex::print() const
{

#ifdef USING_QUADMATH

	int width = 20;

	char real_buf[PRINT_BUFFER_SIZE];
	char im_buf[PRINT_BUFFER_SIZE];
	quadmath_snprintf(real_buf, PRINT_BUFFER_SIZE, "%#*.20Qe", width, re(z));
	quadmath_snprintf(im_buf, PRINT_BUFFER_SIZE, "%#*.20Qe", width, im(z));
	printf("%s + %si\n", real_buf, im_buf);

#else

	printf("Printing complex numbers has not been implemented for all systems.\n");

#endif

}

void Complex::operator=(Complex const& other)
{
	this->raw = other.raw;
}

void Complex::operator+=(Complex const& other)
{
	this->raw += other.raw;
}

void Complex::operator-=(Complex const& other)
{
	this->raw -= other.raw;
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
static typename std::enable_if<isComplex<T>::value, int>::type
operator+ (const T& s, const Complex& c)
{
	return Complex(c.raw + s);
}
template <typename T>
static typename std::enable_if<isComplex<T>::value, int>::type
operator- (const T& s, const Complex& c)
{
	return Complex(c.raw - s);
}
template <typename T>
static typename std::enable_if<isComplex<T>::value, int>::type
operator* (const T& s, const Complex& c)
{
	return Complex(c.raw * s);
}
template <typename T>
static typename std::enable_if<isComplex<T>::value, int>::type
operator/ (const T& s, const Complex& c)
{
	return Complex(c.raw / s);
}
template <typename T>
static typename std::enable_if<isPrimitiveComplex<T>::value, int>::type
operator^ (const T& s, const Complex& c)
{
	return c^Complex(s);
}

/** Arithmetic for Complex type **/
/*
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
*/
Complex operator^ (const Complex& a, const Complex& b)
{
#ifndef USING_QUADMATH
	return Complex(cpow(a.raw, b.raw));
#else
	return Complex(cpowq(a.raw, b.raw));
#endif
}
