#include <iostream>
#include <string>
#include <set>

class Visitor {
	std::string id;
	std::string name;
	int age;
public:
	Visitor(std::string id, std::string name, int age):
		id(id), name(name), age(age){}

	std::string getId() const {
		return this->id;
	}
	std::string getName() const {
		return this->name;
	}
	int getAge() const {
		return this->age;
	}
	bool operator<(const Visitor& other) {
		return this->id.compare(other.id) == 0;
	}
};

class VisitorIDComparator {
public:
	bool operator()(const Visitor& v1, const Visitor& v2) {
		return v1.getId() < v2.getId();
	}
};


int main() {
	std::set<Visitor, VisitorIDComparator> visitors;
	std::string command;
	std::cin >> command;
	while (true)
	{
		if (command.compare("entry") == 0) {
			std::string id, name;
			int age;
			std::cin >> id >> name >> age;
			visitors.insert(Visitor(id, name, age));
		}
		else if (command.compare("name") == 0) {
			std::string compName;
			std::cin >> compName;
			int counter = 0;
			for (auto v : visitors) {
				if (v.getName().compare(compName) == 0) {
					counter++;
				}
			}
			std::cout << counter << std::endl;
		}
		else if (command.compare("age") == 0) {
			int ageL, ageH;
			std::cin >> ageL >> ageH;
			int counter = 0;
			
			for (auto v : visitors) {
				if (v.getAge() >= ageL && v.getAge() < ageH) {
					counter++;
				}
			}
			std::cout << counter << std::endl;
		}
		else {
			break;
		}
		std::cin >> command;
	}
	
}