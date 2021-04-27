#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include "text_editor.h"


void menu()
{
	cout << "============MENU============" << endl;
	cout << "| 1. Input text            |" << endl;
	cout << "| 2. Output text           |" << endl;
	cout << "| 3. Print text            |" << endl;
	cout << "| 4. Correct mistakes      |" << endl;
	cout << "| 5. Replacement           |" << endl;
	cout << "| 6. Counting word         |" << endl;
	cout << "| 0. Exit                  |" << endl;
	cout << "============================" << endl;
}

int main()
{
	int t = 0;
	text_editor my;
	do
	{
		menu();
		cout << endl << ">>> ";
		cin >> t;
		switch (t)
		{
		case 1: {
			my.input();
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			my.output();
			cout << "Done!" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			my.Print();
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			my.fix();
			system("cls");
			break;
		}
		case 5: {
			my.replacement();
			system("pause");
			system("cls");
			break;
		}
		case 6: {
			int k = my.count_word();
			cout << "The word was encountered " << k << " times" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 0: 
			break;
		default: {
			cout << "Incorrect value" << endl;
			system("pause");
			system("cls");
			break;
		}
		}

	} while (t != 0);
	
	
	return 0;
}