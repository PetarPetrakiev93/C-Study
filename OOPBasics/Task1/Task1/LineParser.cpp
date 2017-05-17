#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class LineParser {
private:
	string input;
	int length;

public:
	LineParser(const string& line) :
		input(line),
		length(0) {
	}

	int* getNumbers(){
		stringstream snumbers;
		snumbers << this->input;
		int templength = 0;
		int number;
		int* numbers = new int[this->length];
		while (snumbers >> number) {
			templength++;
			if (templength > this->length) {
				int oldLen = this->length;
				this->length++;
				int* oldInts = numbers;
				numbers = new int[this->length];
				for (int i = 0; i < oldLen; i++) {
					numbers[i] = oldInts[i];
				}
				delete(oldInts);
			}
			numbers[templength - 1] = number;
		}
		snumbers.str("");
		return numbers;
	}

	string* getStrings() {
		stringstream ss;
		ss << this->input;
		int tempLen = 0;
		string s;
		string* strings = new string[this->length];
		while (ss >> s) {
			tempLen++;
			if (tempLen > this->length) {
				int oldLen = this->length;
				this->length++;
				string* oldStrings = strings;
				strings = new string[this->length];
				for (int i = 0; i < oldLen; i++) {
					strings[i] = oldStrings[i];
				}
				delete[] oldStrings;
			}
			strings[tempLen - 1] = s;
		}
		ss.str("");
		return strings;
	}

	char* getChars() {
		char* charArr = new char[this->input.length()];
		int tempLen = this->input.length();
		int index = 0;
		for (int i = 0; i < this->input.length(); i++) {
			if (this->input[i] == ' ') {
				tempLen--;
			}
			else {
				charArr[index] = this->input[i];
				index++;
			}
		}
		this->length = tempLen;
		return charArr;
	}

	int getLength() const {
		return this->length;
	}
};

int main() {
	string s;
	getline(cin, s);
	LineParser lp = LineParser(s);
	char* numbersOutput = lp.getChars();
	for (int i = 0; i < lp.getLength(); i++) {
		cout << numbersOutput[i] << endl;
	}
}