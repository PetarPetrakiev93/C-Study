#pragma once

#include<vector>
#include "Figure.h"

class ObjectsInitializer {
public:
	
	virtual void initObjects(std::vector<Figure*> & objects) = 0;
	
};