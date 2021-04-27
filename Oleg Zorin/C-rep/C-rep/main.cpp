#include <iostream>
#include <vector>
#include <ctime>
#include "Matrix.h"
#include "Vector.h"
#include "Solver.h"
#include "Point.h"

using namespace std;

void labyrinth(matrix lab, int size)
{
	vector <point> track;

}


int main()
{
	matrix lab(5, 5);
	int size = 5;

	for (int i = 0; i < size; i++)
	{
		lab[0][i] = 1.0;
		lab[i][0] = 1.0;
		lab[size - 1][i] = 1.0;
		lab[i][size - 1] = 1.0;
	}
	lab[1][2] = 1.0;
	lab[2][2] = 1.0;









	cout << lab << endl;


	cout << "\nend";
	return 0;
}


//int main1()
//{
//	srand(unsigned int(time(NULL)));
//	try
//	{
//		matrix a(5, 5, 10);
//		Vector x(5), b(5, 10);
//		Solver ex(a, x, b);
//
//		ex.PrintM();
//		ex.Gauss();
//		ex.PrintAns();
//		cout << "Correct answer? - " << ex.Check() << endl;
//		cout << endl << "JACOBI:" << endl;
//		ex.Jacobi();
//	}
//	catch (const std::exception& exp)
//	{
//		cout << exp.what() << endl;
//	}
//	
//	cout << endl << "end";
//	return 0;
//}