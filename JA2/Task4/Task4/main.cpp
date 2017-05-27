#include "City.h"
#include <iostream>
#include <vector>

int main() {
	int n;
	std::cin >> n;
	std::vector<City> cities;
	for (int i = 0; i < n; i++) {
		std::string name;
		double x, y;
		std::cin >> name >> x >> y;
		cities.push_back(City(name, x, y));
	}
	std::string firstName = cities[0].getName();
	std::string secondName = cities[1].getName();
	std::string firstNameT;
	std::string secondNameT;
	double length = 222222222.0;
	for (int i = 0; i < cities.size() - 1; i++) {
		firstNameT = cities[i].getName();
		for (int j = i + 1; j < cities.size(); j++) {
			secondNameT = cities[j].getName();
			Vector2D temp = cities[i].getVector() - cities[j].getVector();
			if (temp.getLength() < length) {
				firstName = cities[i].getName();
				secondName = cities[j].getName();
				length = temp.getLength();
			}
		}
	}

std::cout << firstName << "-" << secondName << std::endl;
}