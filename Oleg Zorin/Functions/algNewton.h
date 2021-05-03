#pragma once
#include "Method.h"
class algNewton :
    public Method
{
public:
    double GetNext(Func* F, double x_prev, double x_0 = 0.0) override;
};

