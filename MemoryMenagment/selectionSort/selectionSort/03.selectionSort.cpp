#include <iostream>
using namespace std;

void selctionSort(int numbers[], int beginning, int end) {
	for (int i = beginning; i <= end - 1; i++) {
		int min = i;
		for (int j = i + 1; j <= end; j++) {
			if (numbers[min]> numbers[j]) {
				min = j;
			}
		}
		if (numbers[i] != numbers[min]) {
			int temp = numbers[i];
			numbers[i] = numbers[min];
			numbers[min] = temp;
		}
	}
}
const int defaultLength = 100;
int main()
{
	cout << "Enter sequence length: " << endl;
	int length;
	cin >> length;
	int numbers[defaultLength];
	cout << "Enter numbers: " << endl;
	for (int i = 0; i < length; i++) {
		cin >> numbers[i];
	}
	cout << "Enter beginning index" << endl;
	int beginning;
	int end;
	cin >> beginning;
	cout << "Enter end index" << endl;
	cin >> end;
	selctionSort(numbers, beginning, end);

	for (int i = 0; i < length; i++) {
		cout << numbers[i] << endl;
	}
}