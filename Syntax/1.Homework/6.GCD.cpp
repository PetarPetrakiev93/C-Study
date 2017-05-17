#include<iostream>

using namespace std;

int main() 
{
	int first, second;

	cin >> first >> second;

	while (second != 0) 
	{
		int t = second;
		second = first % second;
		first = t;
	}
	
	cout << first << endl;
}