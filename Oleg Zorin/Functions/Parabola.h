#pragma once
#include "func.h"
class Parabola :
    public Func
{
public:
    double f(double x) override;
    double pf(double x) override;
};

