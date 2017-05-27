#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

int main() {
	std::stack<int> s;
	std::string input;
	std::cin >> input;
	while (true) {
		if (input.compare("sum") == 0) {
			int number_one = s.top();
			s.pop();
			int number_two = s.top();
			s.pop();
			s.push(number_one + number_two);
			
		}
		else if (input.compare("subtract") == 0) {
			int number_one = s.top();
			s.pop();
			int number_two = s.top();
			s.pop();
			s.push(number_one - number_two);
		}
		else if (input.compare("concat") == 0) {
			std::stringstream ss;
			std::string first = std::to_string(s.top());
			s.pop();
			std::string second = std::to_string(s.top());
			s.pop();
			ss << second << first;
			int number;
			ss >> number;
			s.push(number);
		}
		else if (input.compare("discard") == 0) {
			s.pop();
		}
		else if (input.compare("end") == 0){
			break;
		}
		else {
			std::stringstream ss(input);
			int number;
			ss >> number;
			s.push(number);
		}
		std::cin >> input;
	}
	std::vector<int> numbers;
	while (!s.empty()) {
		numbers.push_back(s.top());
		s.pop();
	}
	for (auto i = numbers.rbegin(); i != numbers.rend(); ++i) {
		std::cout << *i << std::endl;
	}
}