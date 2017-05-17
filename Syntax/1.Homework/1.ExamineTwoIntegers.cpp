#include<iostream>

using namespace std;

int main() {
	int first, second;
	cin >> first >> second;

	if (first > second) {
		int temp;
		temp = first;
		first = second;
		second = temp;
	}
	cout << first << endl;
	cout << second << endl;
	return 0;
}