#pragma once
#include "Matrix.h"
#include "Vector.h"
class Solver
{
	matrix A;
	Vector x, b;
	int size;
public:
	Solver(const matrix& A, const Vector& x, const Vector& b);
	Solver();
	void Gauss();
	void PrintM();
	void PrintAns();
	bool Check();
	void Jacobi();
};
