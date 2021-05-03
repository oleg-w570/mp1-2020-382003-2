#pragma once
#include <math.h>
#include "func.h"
class Cos :
    public Func
{
public:
    double f(double x) override;
    double pf(double x) override;
};

