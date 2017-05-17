#include <vector>
#include <sstream>
#include <string>
#include <map>
#include <iostream>

using namespace std;

int sumOfElements(vector<int> v, int startIndex, int endIndex) {
	int sum = 0;
	for (int i = startIndex; i < endIndex; i++) {
		sum += v[i];
	}
	return sum;
}

int avgOfElements(vector<int> v, int startIndex, int endIndex) {
	int sum = 0;
	
	for (int i = startIndex; i < endIndex; i++) {
		sum += v[i];
	}
	return sum/(endIndex - startIndex);
}

int minOfElements(vector<int> v, int startIndex, int endIndex) {
	int min = INT16_MAX;
	for (int i = startIndex; i < endIndex; i++) {
		if (min > v[i]) {
			min = v[i];
		}
	}
	return min;
}

int maxOfElements(vector<int> v, int startIndex, int endIndex) {
	int max = INT16_MIN;
	for (int i = startIndex; i < endIndex; i++) {
		if (max < v[i]) {
			max = v[i];
		}
	}
	return max;
}

int main() {
	vector<int> numbers;
	stringstream ss;
	string s;
	getline(cin, s);
	ss << s;
	int temp;
	while (ss >> temp) {
		numbers.insert(numbers.end(), temp);	
	}
	int p;
	cin >> p;
	map<string, int> commandMap;
	for (int i = 0; i < p; i++) {
		string command;
		cin >> command;
		int number;
		cin >> number;
		commandMap.insert(pair<string, int>(command, number));
	}
	vector<string> results;
	string tokens;
	cin >> tokens;
	while (tokens != "end") {
		int beginIndex, endIndex;
		cin >> beginIndex >> endIndex;
		string r;
		int result;
		switch (commandMap.find(tokens)->second)
		{
		case 0:
			result = sumOfElements(numbers, beginIndex, endIndex);
			break;
		case 1:
			result = avgOfElements(numbers, beginIndex, endIndex);
			break;
		case 2:
			result = minOfElements(numbers, beginIndex, endIndex);
			break;
		case 3:
			result = maxOfElements(numbers, beginIndex, endIndex);
			break;
		default:
			break;
		}
		stringstream vv;
		vv << tokens << "(" << beginIndex << "," << endIndex << ")=" << result;
		r = vv.str();
		results.insert(results.end(), r);
		vv.clear();
		tokens.clear();
		cin >> tokens;
		
	}
	stringstream cc;
	string print;
	for (size_t i = 0; i < results.size(); ++i)
	{
		if (i != 0)
			cc << ",";
		cc << results[i];
	}
	print = cc.str();
	cout << "[" << results.size() << "]{" << print << "}"<< endl;
}