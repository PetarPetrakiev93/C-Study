
#include <climits>

#include "SqrtGenerator.cpp"
#include "FibonacciGenerator.cpp"
#include "SequencePrinterToConsole.cpp"
#include "SequencePrinterToString.cpp"
#include "SequencePrinterToFile.cpp"

int main() {
	FibonacciGenerator first(3, 6);
	SqrtGenerator second(4, 10);
	SequencePrinter *pointer;
	SequencePrinterToConsole consoleWriter;
	pointer = &consoleWriter;
	(*pointer).setSequence(&first);
	(*pointer).print();
	SequencePrinterToFile fileWriter;
	pointer = &fileWriter;
	(*pointer).setSequence(&first);
	(*pointer).print();
	int temp;
}