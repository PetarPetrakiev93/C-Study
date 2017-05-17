#include<iostream>
#include<sstream>

using namespace std;

int occurences(const string& text, const string& search) {
	string temp = text;
	int occ = 0;
	while (temp.find(search) != string::npos)
	{
		if (temp.find(search) != string::npos) {
			occ++;
			temp = temp.substr(temp.find(search) + search.length());
		}
	}
	return occ;
}

int main() {
	string s;
	cout << "Enter a string:" << endl;
	getline(cin, s);
	cout << "Enter search phrase:" << endl;
	string search;
	getline(cin, search);
	cout << occurences(s, search) << endl;

	return 0;
}