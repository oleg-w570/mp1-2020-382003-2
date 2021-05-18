#pragma once
#include <string>
#include <iostream>

using namespace std;

class Creation
{
protected:
	string name;
	string author;
	string genre;
	int year;
public:
	Creation()
	{
		name = "none";
		author = "none";
		genre = "none";
		year = 0;
	}
	Creation(string _author, string _name, string _genre = "none", int _year = 0) 
		: name(_name), author(_author), genre(_genre), year(_year)
	{}
	virtual void Use() = 0;
	virtual void Print() = 0;
	

};

class Book : public Creation
{
protected:
	int pages;
public:
	Book() : pages(0) {}

	Book(string _author, string _name, string _genre = "none", int _year = 0, int _pages = 0)
		: Creation(_author, _name, _genre, _year), pages(_pages) {}

	void Use() override
	{
		cout << "Reading..." << endl;
	}

	void Print() override
	{
		cout << author << ". " << name << "." << endl << "Genre: " << genre << ", year: " << year << ", pages: " << pages << endl;

	}
};

class Music : public Creation
{
protected:
	int time;
public:

	Music() : time(0) {}

	Music(string _author, string _name, string _genre = "none", int _year = 0, int _time = 0)
		: Creation(_author, _name, _genre, _year), time(_time) {}

	void Use() override
	{
		cout << "lalalala..." << endl;
	}

	void Print() override
	{
		cout << author << " - " << name << ", " << time << " sec" << endl << "Genre: " << genre << ", year: " << year << endl;
	}
};