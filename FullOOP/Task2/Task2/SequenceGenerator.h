#pragma once

#include <string>

class SequenceGenerator {
protected:
	double * sequence;
	std::string * names;
	int start;
	int end;

	SequenceGenerator(int start, int end):
		start(start),
		end(end){
		this->sequence = new double[this->end - this->start];
		this->names = new std::string[this->end - this->start];
		
	}

	~SequenceGenerator() {
		delete[] sequence;
		delete[] names;
	}

	SequenceGenerator(const SequenceGenerator& other) {
		this->sequence = new double[other.end - other.start];
		this->names = new std::string[other.end - other.start];
		this->start = other.start;
		this->end = other.end;
		copySequence(other.sequence, other.names, other.end - other.start);
	}

	SequenceGenerator& operator=(const SequenceGenerator& other) {
		if (this != &other) {
			delete[] sequence;
			delete[] names;
			this->sequence = new double[other.end - other.start];
			this->names = new std::string[other.end - other.start];
			this->start = other.start;
			this->end = other.end;
			copySequence(other.sequence, other.names, other.end - other.start);
		}
		return *this;
	}
	
public:
	virtual void generateSquence() = 0; 
	double getValue(int index) const {
		return this->sequence[index];
	}

	std::string getName(int index) const {
		return this->names[index];
	}
private:
	void copySequence(const double * sequence, const std::string * names, int len) {
		for (int i = 0; i < len; i++) {
			this->sequence[i] = sequence[i];
			this->names[i] = names[i];
		}
	}
};