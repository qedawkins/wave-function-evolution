class Complex
{

	/*
	 *
	 * Class to implement complex number arithmetic
	 * with 128 bits of precision
	 *
	 */

public:
	__float128 real;
	__float128 im;

	Complex();
	Complex(__float128 const&);
	Complex(__float128 const&, __float128 const&);

	void print() const;

	__float128 magsq() const;
	__float128 mag() const;

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

	template <typename T>
	friend Complex operator+ (const T&, const Complex&);
	template <typename T>
	friend Complex operator- (const T&, const Complex&);
	template <typename T>
	friend Complex operator* (const T&, const Complex&);
	template <typename T>
	friend Complex operator/ (const T&, const Complex&);
	template <typename T>
	friend Complex operator^ (const T&, const Complex&);

	/* To implement:
	 *	- Exponentiation
	 *	- Conjugation, Magnitude
	 *	- Other operations that may use
	 *	  implemented operations but should be
	 *	  written by themselves to reduce
	 *	  numerical instability
	 */

};

const Complex I = Complex(0, 1);
