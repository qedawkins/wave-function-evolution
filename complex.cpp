#include "complex.hpp"
#include <cstdio>

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
#ifndef USING_QUADMATH
	return pow(re(raw), 2.0) + pow(im(raw), 2.0);
#else
	return powq(re(raw), 2.0) + powq(im(raw), 2.0);
#endif
}
_float Complex::mag() const
{
#ifndef USING_QUADMATH
	return sqrt(this->magsq());
#else
	return sqrtq(this->magsq());
#endif
}

void Complex::print() const
{
#ifndef USING_QUADMATH

	printf("Printing complex numbers has not been implemented for all systems.\n");

#else

	int width = 20;

	char real_buf[PRINT_BUFFER_SIZE];
	char im_buf[PRINT_BUFFER_SIZE];
	quadmath_snprintf(real_buf, PRINT_BUFFER_SIZE, "%#*.20Qe", width, re(raw));
	quadmath_snprintf(im_buf, PRINT_BUFFER_SIZE, "%#*.20Qe", width, im(raw));
	printf("%s + %si\n", real_buf, im_buf);

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
void Complex::operator*=(Complex const& other)
{
	this->raw *= other.raw;
}
void Complex::operator/=(Complex const& other)
{
	this->raw /= other.raw;
}
void Complex::operator^=(Complex const& other)
{
#ifndef USING_QUADMATH
	this->raw = cpow(this->raw, other.raw);
#else
	this->raw = cpowq(this->raw, other.raw);
#endif
}

/** Arithmetic for bulit-in types **/
Complex operator+ (const _complex& s, const Complex& c)
{
	return Complex(c.raw + s);
}
Complex operator- (const _complex& s, const Complex& c)
{
	return Complex(c.raw - s);
}
Complex operator* (const _complex& s, const Complex& c)
{
	return Complex(c.raw * s);
}
Complex operator/ (const _complex& s, const Complex& c)
{
	return Complex(c.raw / s);
}
Complex operator^ (const _complex& s, const Complex& c)
{
	return c^Complex(s);
}

/** Arithmetic for Complex type **/
Complex operator+ (const Complex& a, const Complex& b)
{
	return Complex(a.raw + b.raw);
}
Complex operator- (const Complex& a, const Complex& b)
{
	return Complex(a.raw - b.raw);
}
Complex operator* (const Complex& a, const Complex& b)
{
	return Complex(a.raw * b.raw);
}
Complex operator/ (const Complex& a, const Complex& b)
{
	return Complex(a.raw / b.raw);
}
Complex operator^ (const Complex& a, const Complex& b)
{
#ifndef USING_QUADMATH
	return Complex(cpow(a.raw, b.raw));
#else
	return Complex(cpowq(a.raw, b.raw));
#endif
}
