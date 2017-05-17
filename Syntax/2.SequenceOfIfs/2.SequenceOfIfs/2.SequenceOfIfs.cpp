#include<iostream>

using namespace std;

int main() {
	int first, second, third;
	cin >> first >> second >> third;

	if ((first < 0 && second > 0 && third > 0) ||
		(first > 0 && second < 0 && third > 0) ||
		(first > 0 && second > 0 && third < 0))
	{
		cout << "-" << endl;
	}
	else if (first < 0 && third < 0 && second < 0) 
	{
		cout << "-" << endl;
	}
	else 
	{
		cout << "+" << endl;
	}

	return 0;
}