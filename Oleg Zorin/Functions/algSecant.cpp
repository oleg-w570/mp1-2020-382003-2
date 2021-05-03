#include "algSecant.h"

double algSecant::GetNext(Func* F, double x_prev, double x_0)
{
    return x_prev - F->f(x_prev) * (x_prev - x_0) / (F->f(x_prev) - F->f(x_0));
}
