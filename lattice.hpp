#ifndef LATTICE_H
#define LATTICE_H

#include "complex.hpp"

class Lattice
{
public:
	State[] lattice;
	Lattice();
	Lattice(const& unsigned _float L,
		const& unsigned int N,
		const& _float dt);

	unsigned _float L;
	unsigned int N;
	_float dt;
}

class State
{
public:
	Complex state;
	inline _float probability();
	void evolve(_float const& dt);
}

#endif // LATTICE_H
