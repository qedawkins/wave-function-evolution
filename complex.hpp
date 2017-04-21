class Complex
{

public:
	__float128 real;
	__float128 im;

	Complex(__float128 const&, __float128 const&);

	void print() const;

};
