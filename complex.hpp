#ifndef USING_QUADMATH

#include <cmath>
#include <complex.h>

typedef long __complex__ double _complex;
typedef long double _float;

#else

#include <quadmath.h>

typedef __complex128 _complex;
typedef __float128 _float;

#endif

class Complex
{

	/*
	 * Class to abstract complex arithmetic
	 */

public:
	_complex raw;
	_float real();
	_float im();

	Complex();
	Complex(_float const&);
	Complex(_float const&, _float const&);
	Complex(_complex const&);

	void print() const;

	_float magsq() const;
	_float mag() const;

	void operator=  (const Complex&);
	void operator+= (const Complex&);
	void operator-= (const Complex&);
	void operator*= (const Complex&);
	void operator/= (const Complex&);

	/*
	Complex operator+ (const Complex&);
	Complex operator- (const Complex&);
	Complex operator* (const Complex&);
	Complex operator/ (const Complex&);
	*/

	friend Complex operator+ (const Complex&, const Complex&);
	friend Complex operator- (const Complex&, const Complex&);
	friend Complex operator* (const Complex&, const Complex&);
	friend Complex operator/ (const Complex&, const Complex&);
	friend Complex operator^ (const Complex&, const Complex&);

	friend Complex operator+ (const _complex&, const Complex&);
	friend Complex operator- (const _complex&, const Complex&);
	friend Complex operator* (const _complex&, const Complex&);
	friend Complex operator/ (const _complex&, const Complex&);
	friend Complex operator^ (const _complex&, const Complex&);

	/* To implement:
	 *	- Exponentiation
	 *	- Conjugation, Magnitude
	 *	- Other operations that may use
	 *	  implemented operations but should be
	 *	  written by themselves to reduce
	 *	  numerical instability
	 */

};

const Complex Complex_I = Complex(0, 1);
