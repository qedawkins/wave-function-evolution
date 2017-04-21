class Complex
{

public:
	__float128 real;
	__float128 im;

	Complex();
	Complex(__float128 const&, __float128 const&);

	void print() const;

	Complex operator=  (const Complex&);
	void operator+= (const Complex&);
	void operator-= (const Complex&);
	void operator*= (const Complex&);
	void operator/= (const Complex&);
	Complex operator+ (const Complex&);
	Complex operator- (const Complex&);
	Complex operator* (const Complex&);
	Complex operator/ (const Complex&);

};
