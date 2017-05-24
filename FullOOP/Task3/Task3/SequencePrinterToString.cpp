#include "SequencePrinter.h"
#include <string>
#include <sstream>

class SequencePrinterToString : public SequencePrinter {
private:
	std::string s;
public:
	void setSequence(const SequenceGenerator * sequence) {
		this->sequence = sequence;
	}
	void print() {
		std::stringstream ss;
		int length = (*sequence).getEnd() - (*sequence).getStart();
		for (int i = 0; i < length; i++) {
			ss << (*sequence).getName(i) << " " << (*sequence).getValue(i) << std::endl;
		}
		s = ss.str();
		ss.str("");
	}
	std::string getString() const{
		return this->s;
	}
};