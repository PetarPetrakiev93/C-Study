#include<iostream>
#include<sstream>
#include <ctype.h>
using namespace std;

void makeTitleCase(string& text) {
	bool isWord = false;
	int i = 0;
	while (i <= text.length()) {
		if (isalpha(text[i])) {
			text[i] = toupper(text[i]);
			isWord = true;
			while (isWord)
			{
				i++;
				if (!isalpha(text[i])) {
					isWord = false;
				}
			}
		}
		i++;
	}
}

int main() {
	string s;
	cout << "Enter a string:" << endl;
	getline(cin, s);
	makeTitleCase(s);
	cout << s << endl;
}