#include "Vector.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#define EPS 1e-10

Vector::Vector(int n)
{
	if (n <= 0)
		throw std::exception("Size must be > 0");

	value = new double[n];
	size = n;
	for (int i = 0; i < n; i++)
	{
		value[i] = 0.0;
	}
}

Vector::Vector(int n, double * v)
{
	if (n <= 0)
		throw std::exception("Size must be > 0");

	value = new double[n];
	size = n;
	for (int i = 0; i < n; i++)
	{
		value[i] = v[i];
	}
}

Vector::Vector(int n, int max)
{
	if (n <= 0)
		throw std::exception("Size must be > 0");

	
	value = new double[n];
	size = n;
	for (int i = 0; i < n; i++)
	{
		value[i] = (double)(rand() % max); 
	}
}

Vector::Vector(const Vector & v)
{
	size = v.size;
	value = new double[size];
	for (int i = 0; i < size; i++)
	{
		value[i] = v.value[i];
	}
}

Vector::~Vector()
{
	delete[] value;
}

Vector & Vector::operator=(const Vector & v)
{
	if (this == &v)
		return *this;
	else if (size == v.size)
	{
		for (int i = 0; i < size; i++)
			value[i] = v.value[i];
		return *this;
	}
	else
	{
		delete[] value;

		size = v.size;
		value = new double[size];
		for (int i = 0; i < size; i++)
			value[i] = v.value[i];
		return *this;
	}
}

Vector Vector::operator+(const Vector & v) const
{
	int max = (size > v.size) ? size : v.size;
	int min = (size > v.size) ? v.size : size;
	Vector res(max);
	for (int i = 0; i < min; i++)
		res.value[i] = value[i] + v.value[i];
	if (size > v.size)
		for (int i = min; i < max; i++)
			res.value[i] = value[i];
	else
		for (int i = min; i < max; i++)
			res.value[i] = v.value[i];
	return res;
}

Vector Vector::operator-(const Vector & v) const
{
	int max = (size > v.size) ? size : v.size;
	int min = (size > v.size) ? v.size : size;
	Vector res(max);
	for (int i = 0; i < min; i++)
		res.value[i] = value[i] - v.value[i];
	if (size > v.size)
		for (int i = min; i < max; i++)
			res.value[i] = value[i];
	else
		for (int i = min; i < max; i++)
			res.value[i] = -v.value[i];
	return res;
}

Vector & Vector::operator-=(const Vector & v)
{
	int max = (size > v.size) ? size : v.size;
	int min = (size > v.size) ? v.size : size;
	int i = 0;
	double* res = new double[max];
	for (i = 0; i < min; i++)
		res[i] = value[i] - v.value[i];
	if (size > v.size)
		for (i = min; i < max; i++)
			res[i] = value[i];
	else
		for (i = min; i < max; i++)
			res[i] = -v.value[i];
	delete[] value;
	size = max;
	value = res;
	return *this;
}

Vector & Vector::operator+=(const Vector & v)
{
	int max = (size > v.size) ? size : v.size;
	int min = (size > v.size) ? v.size : size;
	int i = 0;
	double* res = new double[max];
	for (i = 0; i < min; i++)
		res[i] = value[i] + v.value[i];
	if (size > v.size)
		for (i = min; i < max; i++)
			res[i] = value[i];
	else
		for (i = min; i < max; i++)
			res[i] = v.value[i];
	delete[] value;
	value = res;
	size = max;
	return *this;
}

Vector & Vector::operator=(double p)
{
	for (int i = 0; i < size; i++)
		value[i] = p;
	return *this;
}

Vector operator*(double p, const Vector& v)
{
	Vector res(v.size);
	for (int i = 0; i < v.size; i++)
	{
		res.value[i] = p * v.value[i];
	}
	return res;
}

Vector operator*(const Vector& v, double p)
{
	Vector res(v.size);
	for (int i = 0; i < v.size; i++)
	{
		res.value[i] = v.value[i] * p;
	}
	return res;
}

double & Vector::operator[](int i)
{
	if (i < 0 || i >= size)
		throw std::exception("Wrong number of value");
	return value[i];
}

const double& Vector::operator[](int i) const
{
	if (i < 0 || i >= size)
		throw std::exception("Wrong number of value");
	return value[i];
}

bool Vector::operator==(const Vector& v) const
{
	if (size != v.size)
		return false;

	int i = 0;
	while (i < size)
	{
		if (abs(value[i] - v.value[i]) < EPS)
			i++;
		else
			return false;
	}
	return true;
}

bool Vector::operator!=(const Vector& v) const
{
	if (size != v.size)
	{
		return true;
	}

	for (int i = 0; i < size; i++)
	{
		if (abs(value[i] - v.value[i]) > EPS)
		{
			return true;
		}
	}
	return false;
}

int Vector::GetSize() const
{
	return size;
}

void Vector::swap(int a, int b)
{
	double tmp = value[a];
	value[a] = value[b];
	value[b] = tmp;
}

std::ostream & operator<<(std::ostream & os, const Vector & v)
{
	os.width(7);
	os.precision(2);
	for (int i = 0; i < v.size; i++)
		os << std::fixed << v.value[i] << " ";
	return os;
}

std::istream& operator>>(std::istream& is, const Vector& v)
{
	for (int i = 0; i < v.size; i++)
	{
		std::cout << "[" << i << "] = ";
		is >> v.value[i];
	}
	return is;
}