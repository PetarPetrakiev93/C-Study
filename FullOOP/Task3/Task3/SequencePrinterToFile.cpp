#include "SequencePrinter.h"
#include <string>
#include <fstream>

class SequencePrinterToFile : public SequencePrinter {
	 const std::string filename = "save.txt";
public:
	void setSequence(const SequenceGenerator * sequence) {
		this->sequence = sequence;
	}
	void print() {
		std::ofstream myfile;
		myfile.open(filename);
		int length = (*sequence).getEnd() - (*sequence).getStart();
		for (int i = 0; i < length; i++) {
			myfile << (*sequence).getName(i) << " " << (*sequence).getValue(i) << std::endl;
		}
		myfile.close();
	}
};