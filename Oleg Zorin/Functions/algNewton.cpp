#include "algNewton.h"

double algNewton::GetNext(Func* F, double x_prev, double x_0)
{
    return x_prev - F->f(x_prev) / F->pf(x_prev);
}
