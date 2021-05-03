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
	Parabola f;
	Cos g;
	algNewton N;
	algSecant S;
	Solver My(&f, &N);
	double root = My.Solve();


	cout << "Root = " << root << endl;

	return 0;
}