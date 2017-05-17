#include <iostream>
#include <sstream>
#include <cstdio>
using namespace std;

int * parseNumbers(const string& str, int& resultLength);
int* realloc(int* p, int& len);

int main()
{
	char c;
	int arrayLenght = 0, rows;
	string inputData;
	cin >> rows;
	int i = 0;
	while (i <= rows)
	{
		c = getchar();
		inputData += c;
		if (c == '\n')
			i++;
	}
	for (int i = 0; i<inputData.length(); i++)
	{
		if (inputData[i] == '\n')
			inputData[i] = ' ';
	}

	int* numbers = parseNumbers(inputData, arrayLenght);
	int sum = 0;
	for (int i = 1; i<arrayLenght + 1; i++)
	{
		sum += *(numbers + i);
	}
	cout << sum << endl;
	return 0;
}

int * parseNumbers(const string& str, int& i)
{
	istringstream inputStream(str);
	int n = 2, number;

	int* arr = new int[n];
	while (inputStream >> number)
	{
		i++;
		if (i == n)
		{
			arr = realloc(arr, n);
		}
		arr[i] = number;
	}

	return arr;
}

int* realloc(int* p, int& len)
{
	int oldLen = len;
	len *= 2;
	int* newInt = new int[len];
	for (int i = 0; i<oldLen; i++)
	{
		newInt[i] = p[i];
	}
	delete(p);
	return newInt;
}