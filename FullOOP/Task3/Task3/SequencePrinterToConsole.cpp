#include "SequencePrinter.h"
#include <iostream>

class SequencePrinterToConsole : public SequencePrinter {
public:
	void setSequence(const SequenceGenerator * sequence) {
		this->sequence = sequence;
	}
	void print() {
		
		int length = (*sequence).getEnd() - (*sequence).getStart();
		for (int i = 0; i < length; i++) {
			std::cout << (*sequence).getName(i) << " " << (*sequence).getValue(i) << std::endl;
		}
	}
};