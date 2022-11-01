#include <iostream>
#include <iomanip>
#include <time.h>
#include <vector>

using namespace std;

void Create(int* t, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
		t[i] = Low + rand() % (High - Low + 1);
}


void Print(int* t, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << t[i];
	cout << endl;
}


int Dob(int* t, const int size, int mini, int maxi)
{
	int S = 1;
	for (int i = mini; i < maxi; i++)
			S *= t[i];
	return S;

}
int Max(int* t, const int size)
{
	int max = t[0];
	for (int i = 1; i < size; i++)
		if (abs(t[i]) > max)
			max = t[i];
	return max;
}
int Max1(int* t, const int size)
{
	int index = 0;
	int max = t[0];
	int i = 1;
	for (int i = 1; i < size; i++)
		if ((abs(t[i])) > abs(max)){
			max = t[i];
			index = i;
		}
	return index;
}

int Min(int* t, const int size)
{
	int min = t[0];
	for (int i = 1; i < size; i++)
		if ((abs(t[i])) < abs(min)) 
			min = t[i];
	return min;
}
int Min1(int* t, const int size)
{
	int index = 0;
	int min = t[0];
	for (int i = 1; i < size; i++)
		if ((abs(t[i])) < abs(min)) {
			min = t[i];
			index = i;
		}
	return index;
}

int Sum(int* t, const int size)
{
	int S = 0;
	for (int i = 0; i < size; i++)
		if (t[i] > 0)
		{
			S += t[i];
		}
	return S;
}

void Sort(int* t, const int size)
{
	for (int i = 0; i < size - 1; i++) // індекс початку невпорядкованої частини
	{
		int min = t[i]; // пошук мінімального елемента
		int imin = i; // невпорядкованої частини
		for (int j = i + 1; j < size; j++)
			if (min < t[j])
			{
				min = t[j];
				imin = j;
			}
		t[imin] = t[i]; // обмін місцями мінімального та першого
		t[i] = min; // елементів невпорядкованої частини
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int n;
    cin >> n;
	int* t = new int[n];

	int Low = -5;
	int High = 12;
	
	Create(t, n, Low, High);
	Print(t, n);
	cout << "max" << Max(t, n) << endl;
	cout << "min" << Min(t, n) << endl;


	cout<< "syma" << Sum(t, n) << endl;
	Min1(t, n);
	cout << "i max " << Max1(t, n) << endl;
	cout << "i min " << Min1(t, n) << endl;
	int mim = Min1(t, n);
	int mam = Max1(t, n);
	if (mim > mam)
	{
		int g = mam;
		mam = mim;
		mim = mam;
	}
	cout <<  "dobytok = " << Dob(t, n, mim, mam) << endl;
	Sort(t, n);
	Print(t, n);
	return 0;
}
