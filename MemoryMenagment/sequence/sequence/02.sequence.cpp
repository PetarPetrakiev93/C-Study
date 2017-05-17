#include <iostream>
using namespace std;
const int defaultLength = 100;
int main()
{
	int numbers[defaultLength];
	int length;
	cin >> length;


	cout << "Enter numbers: " << endl;
	for (int i = 0; i < length; i++) {
		cin >> numbers[i];
	}

	int beginning = 0;
	int end = 0;
	int lengthArr = 0;
	for (int i = 0; i < length; i++) {
		int tempLength = 0;
		for (int j = i; j < length; j++) {
			if (numbers[i] == numbers[j] && j < length - 1) {
				tempLength++;
			}
			else if (numbers[i] == numbers[j] && j == length - 1){
				tempLength++;
				break;
			}
			else {
				break;
			}
		}
		if (lengthArr < tempLength) {
			beginning = i;
			lengthArr = tempLength;
		}
	}

	for (int i = beginning; i < beginning + lengthArr; i++) {
		cout << numbers[i] << endl;
	}
}