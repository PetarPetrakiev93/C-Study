#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int min = INT32_MAX;
	int max = INT32_MIN;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;

		if (temp > max) {
			max = temp;
		}

		if (temp < min) {
			min = temp;
		}
	}

	cout << "Max number: " << max << endl;
	cout << "Min number: " << min << endl;

	return 0;
}