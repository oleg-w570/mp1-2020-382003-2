#include <iostream>
#include <vector>
#include <ctime>
#include "Creation.h"
//#include "Matrix.h"
#include "Vector.h"
//#include "Solver.h"


using namespace std;


int main()
{
	srand(unsigned int(time(NULL)));
	try
	{
		Book B("Dostoevski", "Bratia Karamazovi");
		Music M("The Who", "Behind Blue Eyes");

		Vector<Creation*> a;
		a.push_back(&B);
		a.push_back(&M);
		a[0]->Print();
		a[1]->Print();



	}
	catch (const std::exception& exp)
	{
		cout << exp.what() << endl;
	}
	
	cout << endl << "end";
	return 0;
}