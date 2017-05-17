#include<iostream>
#include<fstream>
#include <string>
using namespace std;

int main() {
	
	ifstream fileInput1("input1.txt");
	ifstream fileInput2("input2.txt");
	string text1, text2;
	string line1, line2;
	while (getline(fileInput1, line1)) {
		text1 += line1 + '\n';
	}
	while (getline(fileInput2, line2)) {
		text2 += line2 + '\n';
	}

	if (text1 == text2) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	return 0;
}