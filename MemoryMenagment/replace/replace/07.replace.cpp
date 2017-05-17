#include<iostream>
#include<sstream>

using namespace std;

int main() {
	string text;
	cout << "Enter text:" << endl;
	getline(cin, text);
	string find;
	cout << "Enter find string:" << endl;
	getline(cin, find);
	string replace;
	cout << "Enter replace string:" << endl;
	getline(cin, replace);
	while (text.find(find) != -1) {
		text = text.replace(text.find(find), find.length(), replace);
	}
	cout << text << endl;
}