#pragma once
#include "Func.h"

class Method
{
public:
	virtual double GetNext(Func* F, double x_prev, double x_0 = 0) = 0;
};

