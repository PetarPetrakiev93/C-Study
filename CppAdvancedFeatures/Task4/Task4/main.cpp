#include <iostream>
#include <string>
#include <sstream>

#include "List.h"

List<int> f(List<int> & a) {
	return{ 3, 4 };
}

int main() {
	List<int> a{ 1,2 };
	a = f(a);
	for (int value : a) {
		std::cout << value << std::endl;
	}
	return 0;

}
