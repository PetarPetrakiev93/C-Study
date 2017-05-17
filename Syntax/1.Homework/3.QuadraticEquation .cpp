#include<iostream>
#include<cmath>

using namespace std;

int main() {
	double a, b, c;
	cin >> a >> b >> c;

	if ((pow(b, 2) - (4 * a * c)) > 0) 
	{
		double delimiter = 2 * a;
	
		double x1 = (-b + sqrt((pow(b, 2) - (4 * a * c)))) / delimiter;
		double x2 = (-b - sqrt((pow(b, 2) - (4 * a * c)))) / delimiter;
		cout << x1 << endl;
		cout << x2 << endl;
	}
	else if ((pow(b, 2) - (4 * a * c)) == 0) {
		double delimiter = 2 * a;
		double x = -b / delimiter;
		cout << x << endl;
	}
	
	return 0;
}