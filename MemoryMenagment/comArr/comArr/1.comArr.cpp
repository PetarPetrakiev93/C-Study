#include <iostream>
#include <string>

using namespace std;
const int defaultLength = 100;
bool compArr(int arr1[], int length1, int arr2[], int length2) {
	if (length1 != length2) {
		return false;
	}
	else {
		for (int i = 0; i< length1; i++)
		{
			if (arr1[i] != arr2[i]) {
				return false;
			}
		}
	}
	return true;
}

int main()
{
	int length1;
	int length2;
	cin >> length1;
	cin >> length2;

	int numbers1[defaultLength];
	int numbers2[defaultLength];

	cout << "Enter numbers1: " << endl;
	for (int i = 0; i < length1; i++) {
		cin >> numbers1[i];
	}
	cout << "Enter numbers2: " << endl;
	for (int i = 0; i < length2; i++) {
		cin >> numbers2[i];
	}

	if (compArr(numbers1, length1, numbers2, length2)) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
}