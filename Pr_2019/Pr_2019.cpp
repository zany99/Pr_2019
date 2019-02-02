// Pr_2019.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// Praktika_2019.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void quicksort(int *mas, int first, int last)
{
	int mid, count;
	int f = first, l = last;
	mid = mas[(f + l) / 2];
	do
	{
		while (mas[f] < mid) f++;
		while (mas[l] > mid) l--;
		if (f <= l)
		{
			count = mas[f];
			mas[f] = mas[l];
			mas[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) quicksort(mas, first, l);
	if (f < last) quicksort(mas, f, last);
}
void Swap(int *Mas, int i)
{
	int temp;
	temp = Mas[i];
	Mas[i] = Mas[i - 1];
	Mas[i - 1] = temp;
}
//Shaker
void ShakerSort(int *Mas, int Start, int N)
{
	int Left, Right, i;
	Left = Start;
	Right = N - 1;
	while (Left <= Right)
	{
		for (i = Right; i >= Left; i--)
			if (Mas[i - 1] > Mas[i]) Swap(Mas, i);
		Left++;
		for (i = Left; i <= Right; i++)
			if (Mas[i - 1] > Mas[i]) Swap(Mas, i);
		Right--;
	}
}
int main()
{
	using namespace std;
	const int N = 10;
	int array[N];
	srand(time(0));
	cout << "Random array:";
	for (int i = 0; i < N; ++i) {
		array[i] = rand() % 20 - 10;
		cout << array[i] << "  ";
	}
	cout << endl;


	int max = array[0];
	int min = array[0];
	int maxI;
	int minI;
	for (int i = 0; i < N; ++i)
	{
		if (array[i] > max)
		{
			max = array[i];
			maxI = i + 1;
		}
	}
	for (int i = 0; i < N; ++i)
	{
		if (array[i] < min)
		{
			min = array[i];
			minI = i + 1;
		}
	}
	cout << "MIN = " << min << " Index = " << minI << endl;
	cout << "MAX = " << max << " Index = " << maxI << endl;

	//Bulbashka
	for (int j = 0; j < N - 1; j++) {
		for (int i = 0; i < N - 1; i++) {
			if (array[i] > array[i + 1]) {
				int tmp = array[i];
				array[i + 1] = tmp;


			}
		}
	}
	cout << "Bulbashka =   ";
	for (int i = 0; i < N; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

	//VStavka
	int key = 0, j = 0;
	for (int i = 1; i < N; i++)
	{
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
	}
	cout << "Vstavka   =   ";
	for (int i = 0; i < N; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

	//Vuborom
	int x, k;
	for (int i = 0; i < N; i++) {
		k = i; x = array[i];

		for (j = i + 1; j < N; j++)
			if (array[j] < x) {
				k = j; x = array[j];
			}

		array[k] = array[i];
		array[i] = x;
	}
	cout << "Vuborom   =   ";
	for (int i = 0; i < N; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
	//Quick 
	int first = 0; int last = N - 1;
	quicksort(array, first, last);
	cout << "Quick     =   ";
	for (int i = 0; i < N; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
	//Shaker sort
	ShakerSort(array, 1, N);
	cout << "Shaker    =   ";
	for (int i = 0; i < N; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

	//Line
	int requiredKey = 0;
	int nElement = 0;
	cout << "What number? ";
	cin >> requiredKey;

	nElement = linSearch(array, requiredKey, N);

	if (nElement != -1)
	{
		cout << "Number " << requiredKey << " Index " << nElement << endl;
	}
	else
	{
		cout << "Fuck" << endl;
	}
	return 0;
}

int linSearch(int arr[], int requiredKey, int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] == requiredKey)
			return i;
	}
	return -1;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"
// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
