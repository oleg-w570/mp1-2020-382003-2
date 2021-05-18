#pragma once
#include <iostream>
#define EPS 1E-10

template<typename T>
class Vector
{
	int size;
	T* value;
public:
	Vector(int n = 0) : size(n)
	{
		if (n < 0)
			throw std::exception("Size must be > 0");

		if (n > 0)
		{
			value = new T[n];
			for (int i = 0; i < n; i++)
			{
				value[i] = 0;
			}
		}
		else
		{
			value = new T;
		}
	}
	Vector(int n, T* v) : size(n)
	{
		if (n <= 0)
			throw std::exception("Size must be > 0");

		value = new T[n];
		for (int i = 0; i < n; i++)
		{
			value[i] = v[i];
		}
	}
	Vector(int n, T max) : size(n)
	{
		if (n <= 0)
			throw std::exception("Size must be > 0");


		value = new T[n];
		for (int i = 0; i < n; i++)
		{
			value[i] = rand() % max;
		}
	}
	Vector(const Vector& v) : size(v.size)
	{
		value = new T[size];
		for (int i = 0; i < size; i++)
		{
			value[i] = v.value[i];
		}
	}
	~Vector()
	{
		delete[] value;
	}
	Vector& operator=(const Vector& v)
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
			value = new T[size];
			for (int i = 0; i < size; i++)
				value[i] = v.value[i];
			return *this;
		}
	}
	Vector operator+(const Vector& v) const
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
	Vector operator-(const Vector& v) const
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
	Vector& operator-=(const Vector& v)
	{
		int max = (size > v.size) ? size : v.size;
		int min = (size > v.size) ? v.size : size;
		int i = 0;
		T* res = new T[max];
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
	Vector& operator+=(const Vector& v)
	{
		int max = (size > v.size) ? size : v.size;
		int min = (size > v.size) ? v.size : size;
		int i = 0;
		T* res = new T[max];
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
	Vector& operator=(T p)
	{
		for (int i = 0; i < size; i++)
			value[i] = p;
		return *this;
	}
	friend Vector operator*(T p, const Vector& v)
	{
		Vector res(v.size);
		for (int i = 0; i < v.size; i++)
		{
			res.value[i] = p * v.value[i];
		}
		return res;
	}
	friend Vector operator*(const Vector& v, T p)
	{
		Vector res(v.size);
		for (int i = 0; i < v.size; i++)
		{
			res.value[i] = v.value[i] * p;
		}
		return res;
	}
	T& operator[](int i)
	{
		if (i < 0 || i >= size)
			throw std::exception("Wrong number of value");
		return value[i];
	}
	const T& operator[](int i) const
	{
		if (i < 0 || i >= size)
			throw std::exception("Wrong number of value");
		return value[i];
	}
	bool operator==(const Vector& v) const
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
	bool operator!=(const Vector& v) const
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
	int GetSize() const
	{
		return size;
	}
	friend std::ostream& operator<<(std::ostream& os, const Vector& v)
	{
		os.width(7);
		os.precision(2);
		for (int i = 0; i < v.size; i++)
			os << std::fixed << v.value[i] << " ";
		return os;
	}
	friend std::istream& operator>>(std::istream& is, const Vector& v)
	{
		for (int i = 0; i < v.size; i++)
		{
			std::cout << "[" << i << "] = ";
			is >> v.value[i];
		}
		return is;
	}
	void swap(int a, int b)
	{
		T tmp = value[a];
		value[a] = value[b];
		value[b] = tmp;
	}
	void push_back(const T& L)
	{
		if (size == 0)
		{
			value[0] = L;
			size++;
		}
		else
		{
			T* tmp = new T[size + 1];
			for (int i = 0; i < size; i++)
			{
				tmp[i] = value[i];
			}
			tmp[size] = L;

			delete[] value;
			value = tmp;
			size++;
		}
	}
};
