#include "SequenceGenerator.h"
#include <math.h>

class SqrtGenerator : public SequenceGenerator {
public:
	SqrtGenerator(int startInteger, int endInteger) : 
		SequenceGenerator(startInteger, endInteger){
		generateSquence();
	}


	void generateSquence() {
		int position = 0;
		for (int i = start; i < end; i++) {
			std::string temp = "Sqrt(";
			temp.append(std::to_string(i));
			temp.append(")");
			names[position] = temp;
			sequence[position] = sqrt((double)i);
			position++;
		}
	}
};

