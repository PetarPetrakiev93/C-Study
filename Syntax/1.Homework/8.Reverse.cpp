#include<iostream>

using namespace std;

int reverse(int n)
{
	int reverse = 0;
	int reminder;
	while (n != 0)
	{
		reminder = n % 10;
		reverse = reverse * 10 + reminder;
		n /= 10;
	}
	
	return reverse;
}

int main() 
{
	int n;
	cin >> n;
	cout << reverse(n) << endl;
}