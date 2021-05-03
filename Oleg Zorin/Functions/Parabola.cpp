#include "Parabola.h"

double Parabola::f(double x)
{
    return x*x - 2*x + 1;
}

double Parabola::pf(double x)
{
    return 2*x - 2;
}
