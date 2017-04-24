#include "complex.hpp"
#include <cstdio>

#define PRINT_BUFFER_SIZE 128


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
    this->re(r);
    this->im(i);
}
Complex::Complex(_complex const& z)
{
    raw = z;
}

_float Complex::re() const
{
#ifndef USING_QUADMATH
    return raw.real();
#else
    return __real__ raw;
#endif
}
void Complex::re(_float const& r)
{
#ifndef USING_QUADMATH
    raw.real(r);
#else
    __real__ raw = r;
#endif
}

_float Complex::im() const
{
#ifndef USING_QUADMATH
    return raw.imag();
#else
    return __imag__ raw;
#endif
}
void Complex::im(_float const& r)
{
#ifndef USING_QUADMATH
    raw.imag(r);
#else
    __imag__ raw = r;
#endif
}

_float Complex::magsq() const
{
#ifndef USING_QUADMATH
    return pow(Re(raw), 2.0) + pow(Im(raw), 2.0);
#else
    return powq(Re(raw), 2.0) + powq(Im(raw), 2.0);
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

    printf("%.20Le + %.20Lei\n", Re(raw), Im(raw));

#else

    int width = 20;

    char real_buf[PRINT_BUFFER_SIZE];
    char im_buf[PRINT_BUFFER_SIZE];
    quadmath_snprintf(real_buf, PRINT_BUFFER_SIZE, "%#*.20Qe", width, Re(raw));
    quadmath_snprintf(im_buf, PRINT_BUFFER_SIZE, "%#*.20Qe", width, Im(raw));
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
    this->raw = std::pow(this->raw, other.raw);
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
Complex operator~ (const Complex& c)
{
/*#ifndef USING_QUADMATH
    return Complex(c.raw.real(), -c.raw.imag());
#else
    return Complex(__real__ c.raw, -(__imag__ c.raw));
#endif*/
    return Complex(~c.raw);
}
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
    return Complex(std::pow(a.raw, b.raw));
#else
    return Complex(cpowq(a.raw, b.raw));
#endif
}
