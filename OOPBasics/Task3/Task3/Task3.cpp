#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
static int index = 0;
class Person {
	string name;
	int age;
	int id;
public:
	Person(string name, int age) :
		age(age),
		name(name) {
		this->id = index;
		index++;
	};
	string getName() const {
		return this->name;
	};
	int getAge() const {
		return this->age;
	};
	int getId() const {
		return this->id;
	};
	void setName(string name) {
		this->name = name;
	};
	void setAge(int age) {
		this->age = age;
	};
};
class Car {
	string manifacturerName;
	string model;
	Person& owner;
	int hoursepower;
	string registrationNumber;
public:
	Car(string manifacturerName, string model, Person& owner, int hoursepower, string registrationNumber) :
		manifacturerName(manifacturerName),
		model(model),
		owner(owner),
		hoursepower(hoursepower),
		registrationNumber(registrationNumber) {
	};
	string getRegistrationNumber() const {
		return this->registrationNumber;
	}
	void changeOwner(Person& person, string registrationNumber) {
		this->owner = person;
		this->registrationNumber = registrationNumber;
	};
	string carInfo() {
		stringstream ss;
		ss << this->manifacturerName << " " << this->model << endl;
		ss << "Hoursepower: " << this->hoursepower << endl;
		ss << "Registration number: " << this->registrationNumber << endl;
		ss << "Owner: " << this->owner.getName() << " " << this->owner.getAge() << " " << this->owner.getId() << endl;
		string s = ss.str();
		ss.str("");
		return s;
	};
};
int main()
{
	vector<Person> people;
	vector<Car> cars;
	string s;
	cin >> s;
	while (s != "end") {
		int command = stoi(s);
		switch (command) {
		case 0:
		{
			string n;
			int age;
			cout << "Enter name: ";
			cin >> n;
			cout << "Enter age: ";
			cin >> age;
			Person p(n, age);
			people.push_back(p);
			break;
		}
		case 1:
		{
			string manifacturer;
			string m;
			int id;
			int hourses;
			string registration;
			cout << "Enter manifacturer: ";
			cin >> manifacturer;
			cout << "Enter model: ";
			cin >> m;
			cout << "Enter id: ";
			cin >> id;
			Person& own = people.at(id);
			cout << "Enter hoursepower: ";
			cin >> hourses;
			cout << "Enter registration number: ";
			cin >> registration;
			Car car(manifacturer, m, own, hourses, registration);
			cars.push_back(car);
			break;
		}
		case 2:
		{
			int id;
			cout << "Enter person id: ";
			cin >> id;
			string name;
			int age;
			cout << "Enter name: ";
			cin >> name;
			cout << "Enter age: ";
			cin >> age;
			people.at(id).setName(name);
			people.at(id).setAge(age);
			break;
		}
		case 3:
		{
			int id;
			string reg;
			cout << "Enter car registration number: ";
			cin >> reg;
			cout << "Enter person id: ";
			cin >> id;
			Person& p = people.at(id);
			string newReg;
			cout << "Enter new registration number: ";
			cin >> newReg;
			for (int i = 0; i < cars.size(); i++) {
				if (reg.compare(cars.at(i).getRegistrationNumber()) == 0) {
					cars.at(i).changeOwner(p, newReg);
					break;
				}
			}
			break;
		}
		case 4:
		{
			for (int i = 0; i < cars.size(); i++) {
				cout << cars.at(i).carInfo();
			}
			break;
		}
		}
		cin >> s;
	}
}
