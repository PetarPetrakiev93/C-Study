#include "BigInt.h"
#include<iostream>
#include <string>

int main() {
	std::string first;
	std::string second;
	std::getline(std::cin, first);
	std::getline(std::cin, second);
	BigInt firstNumber(first);
	BigInt secondNumber(second);
	for (firstNumber; firstNumber.getDigits().compare(secondNumber.getDigits()) != 0; firstNumber += BigInt(1)) {
		if (firstNumber.getDigits()[firstNumber.getDigits().size() - 1] == '0' ||
			firstNumber.getDigits()[firstNumber.getDigits().size() - 1] == '5') {
			int currentNumber = 0;
			for (int i = 0; i < firstNumber.getDigits().size(); i++) {
				char c = firstNumber.getDigits()[i];
				currentNumber += (c - 48);
			}
			while (currentNumber > 10)
			{
				std::string temp = std::to_string(currentNumber);
				currentNumber = 0;
				for (int j = 0; j < temp.size(); j++) {
					char c = temp[j];
					currentNumber += (c - 48);
				}
			}
			if (currentNumber % 9 == 0) {
				std::cout << firstNumber << std::endl;
			}
		}
	}
	return 0;
}