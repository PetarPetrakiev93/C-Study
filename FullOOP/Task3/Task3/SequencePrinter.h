#pragma once
#include "SequenceGenerator.h"

class SequencePrinter {
	protected:
	const SequenceGenerator * sequence;
public:
	virtual void print() = 0;
	virtual void setSequence(const SequenceGenerator * sequence) = 0;
};