#include <iostream>
#include <string>

using namespace std;

class StringFormatter {
 private:
	 string& stringToFormat;
	 string formatPrefix;
 public:
	 StringFormatter(string& stringToFormat, const string& formatPrefix) :
		 stringToFormat(stringToFormat),
		 formatPrefix(formatPrefix) {

	 }

	 void format(string insertArr[], int insertArrSize) {
		 int numberOfPrefixes = 0;
		 int index = 0;
		 int prefixLength = this->formatPrefix.size();
		 string prefix = this->formatPrefix;
		 while (true) {
			 if (index != 0) {
				 index = (this->stringToFormat).find(prefix, index + prefixLength);
			 }
			 else {
				 index = this->stringToFormat.find(prefix, index);
			 }
			 if (index == string::npos) {
				 break;
			 }
			 numberOfPrefixes++;
		 }
		 
		 if (numberOfPrefixes < insertArrSize) {
			 throw "number of prefixes are less than then the insert array";
		 }
		 index = 0;
		 string temp = this->stringToFormat;
		 for (int i = 0; i < insertArrSize; i++) {
			 if (index != 0) {
				 index = temp.find(this->formatPrefix, index + prefix.size());
			 }
			 else {
				 index = temp.find(this->formatPrefix, index);
			 }
			 prefix = this->formatPrefix;
			 prefix += to_string(i);
			 temp = temp.replace(index, prefix.length(), insertArr[i]);
		 }
		 this->stringToFormat = temp;
	 }
	 void format(int insertArr[], int insertArrSize) {

	 }

};

int main() {
	string str = "Dear *:0, Our company *:1 wants to make you a Donation Of *:2 Million *:3 in good faith.Please send us a picture of your credit card";
	StringFormatter formatter(str,"*:");
	string arr[]{ "Ben Dover", "Totally Legit NonSpam Ltd", "13", "Leva" };
	formatter.format(arr, 4);
	cout << str << endl;
}