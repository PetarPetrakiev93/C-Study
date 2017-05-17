#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	unsigned long long nFactor = 1;
	for (int i = 1; i <= n; i++) {
		nFactor = nFactor * i;
	}
	int trailingZero = 0;
	while (nFactor % 10 == 0) {
		nFactor = nFactor / 10;
		trailingZero++;
	}

	cout << trailingZero << endl;
}