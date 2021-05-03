#include "Solver.h"

Solver::Solver(Func* _F, Method* _M) :
	F(_F), M(_M)
{}

double Solver::Solve()
{
	double x_next = 3.0;
	double x_prev;
	do
	{
		x_prev = x_next;
		x_next = M->GetNext(F, x_next);
		std::cout << "X_Next = " << x_next << ", X_Prev = " << x_prev << ", Diff = " << x_next - x_prev << std::endl;
	} while (fabs(x_next - x_prev) > 1e-10);

	return x_next;
}
