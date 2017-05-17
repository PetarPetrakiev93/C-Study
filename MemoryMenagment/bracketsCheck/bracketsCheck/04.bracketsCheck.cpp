#include<iostream>
#include<sstream>

using namespace std;

bool check(const string& text) {
	int openningBrackets = 0;
	int closingBrackets = 0;
	for (int i = 0; i < text.length(); i++) {
		if (text[i] == '(') {
			openningBrackets++;
		}
	}
	for (int i = 0; i < text.length(); i++) {
		if (text[i] == ')') {
			closingBrackets++;
		}
	}
	if (openningBrackets == closingBrackets) {
		return true;
	}
	return false;
}

int main() {
	string expression;
	cout << "Enter expession:" << endl;
	getline(cin, expression);
	if (check(expression) == true) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	
}