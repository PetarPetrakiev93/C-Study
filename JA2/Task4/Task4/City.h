#pragma once
#include <string>

#include "Vector2D.h"

class City {
	std::string name;
	Vector2D vector;
public:
	City(std::string name, double x, double y):
	name(name){
		this->vector = Vector2D(x, y);
	}

	std::string getName() const {
		return this->name;
	}

	Vector2D getVector() const {
		return this->vector;
	}
};