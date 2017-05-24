#include "SequenceGenerator.h"

class FibonacciGenerator : public SequenceGenerator {
public:
	FibonacciGenerator(int startFibonacciNumber, int endFibonacciNumber) :
		SequenceGenerator(startFibonacciNumber, endFibonacciNumber) {
		generateSquence();
	}
	void generateSquence() {
		int position = 0;
		for (int i = start; i < end; i++) {
			std::string temp = "Fibonacci ";
			temp.append(std::to_string(i));
			names[position] = temp;
			sequence[position] = Fibonacci_R(i);
			position++;
		}
	}
private:
	int Fibonacci_R(int n)
	{
		if (n <= 0) return 0;
		else if (n == 1) return 1;
		else return Fibonacci_R(n - 1) + Fibonacci_R(n - 2);
	}
};

