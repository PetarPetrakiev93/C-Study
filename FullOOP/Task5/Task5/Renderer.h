#pragma once
#include <string>
#include <vector>
#include "Figure.h"

class Renderer {
public:
	virtual std::string render(const std::vector<Figure*> &figures) = 0;
};