#include "stdio.h"
#include "stdlib.h"


int increments(int* inc, int Size)
{
	int i = -1, p1 = 1, p2 = 1, p3 = 1;
	do {
		if (++i % 2)
		{
			inc[i] = 8 * p1 - 6 * p2 + 1;
		}
		else
		{
			inc[i] = 9 * p1 - 9 * p3 + 1;
			p2 *= 2;
			p3 *= 2;
		}
		p1 *= 2;
	} while (3 * inc[i] < Size);
	if (Size > 3)
	{
		return i - 1;
	}
	else
	{
		return i;
	}

}

void ShellSortRS(int* A, int Size, int* ContrOfComp, int* ContrOfPer)
{
	int* inc;
	int S, i, counter, tmp;
	inc = (int*)malloc(sizeof(int)*40);
	S = increments(inc, Size);
	for (; S >= 0; S--)
	{
		for (i = inc[S]; i <= Size; i++)
		{
			counter = i;
			tmp = A[counter];
			while ((counter - inc[S] >= 0) && (tmp > A[counter - inc[S]]))
			{
				(*ContrOfComp)++;
				A[counter] = A[counter - inc[S]];
				(*ContrOfPer)++;
				counter -= inc[S];
			}
			A[counter] = tmp;
			(*ContrOfPer)++;
		}
	}
	free(inc);
}

void RandomArray(int* A, int Size)
{
	int i = 0, a = -10, b = 10;
	
	for (i = 0; i < Size; i++)
	{
		A[i] = rand() % (b - a) + a;
	}
}

void MemCopy(int* MainArray, int* CopyOfArray, int Size)
{
	int i;
	for (i = 0; i < Size; i++)
	{
		CopyOfArray[i] = MainArray[i];
	}
}

void Print(int* A, int Size)
{
	int i;

	for (i = 0; i < Size; i++)
	{
		printf("%d\t", A[i]);
	}
}

void SumArray(int* A, int Size, int* sum)
{
	int i;

	for (i = 0; i < Size; i++)
	{
		(*sum) += A[i];
	}
}

void main()
{
	int* A, * Acopy;
	int n = 100;
	int n1;
	int n2;
	int sum = 0;

	A = (int*)malloc(sizeof(int) * n);
	Acopy = (int*)malloc(sizeof(int) * n);
	RandomArray(A, n);
	Print(A, n);

	printf("\n===========================================================\n");

	MemCopy(A, Acopy, n);
	ShellSortRS(Acopy, n, &n1, &n2);
	Print(Acopy, n);

	printf("\n===========================================================\n");

	MemCopy(Acopy, A, n);
	Print(A, n);

	printf("\n===========================================================\n");

	SumArray(A, n, &sum);
	printf("sum = %d\n", sum);
}