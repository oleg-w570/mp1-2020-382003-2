#pragma once
#include "Method.h"
class algSecant :
    public Method
{
public:
    double GetNext(Func* F, double x_prev, double x_0 = 0.0) override;
};

