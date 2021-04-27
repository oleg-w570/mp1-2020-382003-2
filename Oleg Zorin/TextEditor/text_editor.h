#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

class text_editor
{	
	vector<string> voc;
	string text;
public:
	void Print();
	void input();
	void output();
	void fix();
	void replacement();
	int count_word();

};

