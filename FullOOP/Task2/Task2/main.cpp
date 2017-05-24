#include <iostream>
#include <climits>

#include "SqrtGenerator.cpp"
#include "FibonacciGenerator.cpp"

int main() {
//	FibonacciGenerator first(3, 6);
//	SqrtGenerator second(4, 10);

//	std::cout << first.getName(1) << std::endl;
//	std::cout << first.getValue(1) << std::endl;
//	std::cout << second.getName(1) << std::endl;
//	std::cout << second.getValue(1) << std::endl;
	
		for (int ind2 = 0; ind2 < INT_MAX; ind2++) {
			std::cout << " " << std::endl;
			FibonacciGenerator g(1, 20);
			FibonacciGenerator copyConstructed(g);
			FibonacciGenerator copyAssigned(1, 5);
			copyAssigned = g;
			std::cout << copyAssigned.getValue(15) << std::endl;
			// print copyAssigned and copyConstructed to see they are correct
			// or just have a function which checks each of their values
		}
	

}