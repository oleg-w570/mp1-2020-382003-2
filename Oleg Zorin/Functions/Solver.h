#pragma once
#include <iostream>
#include "Func.h"
#include "Method.h"

class Solver
{
	Func* F;
	Method* M;
public:
	Solver(Func* _F, Method* _M);
	double Solve();
};

