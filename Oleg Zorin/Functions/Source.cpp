#include <iostream>
#include "Func.h"
#include "Method.h"
#include "algNewton.h"
#include "algSecant.h"
#include "Parabola.h"
#include "Cos.h"
#include "Solver.h"

using namespace std;

int main()
{
	Func* f;
	Method* M;
	f = new Parabola;
	M = new algNewton;

	Solver My(f, M);
	double root = My.Solve();


	cout << "Root = " << root << endl;

	return 0;
}