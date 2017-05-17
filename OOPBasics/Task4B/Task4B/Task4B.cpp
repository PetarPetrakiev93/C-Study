#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>


using namespace std;

static int index = 0;
class Person {
	string name;
	int age;
	int id;
public:
	Person() {};
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
	friend ostream& operator<<(ostream& os, const Person& s)
	{
		os << s.name << '\n';
		os << s.age << '\n';
		os << s.id << '\n';
		return os;
	};
	friend istream& operator >> (istream& is, Person& s)
	{
		is >> s.name >> s.age >> s.id;
		return is;
	};
};
class Car {
	string manifacturerName;
	string model;
	int id;
	int hoursepower;
	string registrationNumber;
public:
	Car() {};
	Car(string manifacturerName, string model, int id, int hoursepower, string registrationNumber) :
		manifacturerName(manifacturerName),
		model(model),
		id(id),
		hoursepower(hoursepower),
		registrationNumber(registrationNumber) {
	};
	string getRegistrationNumber() const {
		return this->registrationNumber;
	}
	void changeOwner(int id, string registrationNumber) {
		this->id = id;
		this->registrationNumber = registrationNumber;
	};
	string carInfo(vector<Person> people) {
		stringstream ss;
		ss << this->manifacturerName << " " << this->model << endl;
		ss << "Hoursepower: " << this->hoursepower << endl;
		ss << "Registration number: " << this->registrationNumber << endl;
		ss << "Owner: " << people.at(this->id).getName() << " " << people.at(this->id).getAge() << " " << people.at(this->id).getId() << endl;
		string s = ss.str();
		ss.str("");
		return s;
	};
	friend ostream& operator<<(ostream& os, const Car& s)
	{
		os << s.manifacturerName << '\n';
		os << s.model << '\n';
		os << s.id << '\n';
		os << s.hoursepower << '\n';
		os << s.registrationNumber << '\n';
		return os;
	};
	friend istream& operator >> (istream& is, Car& s)
	{
		is >> s.manifacturerName >> s.model >> s.id >> s.hoursepower >> s.registrationNumber;
		return is;
	};
};
int main()
{
	vector<Person> people;
	vector<Car> cars;
	ifstream ifs("saved.txt");
	int size;
	ifs >> size;
	for (int i = 0; i < size; i++) {
		Person person;
		ifs >> person;
		people.push_back(person);
	}
	ifs >> size;
	for (int i = 0; i < size; i++) {
		Car car;
		ifs >> car;
		cars.push_back(car);
	}
	ifs.close();
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

			cout << "Enter hoursepower: ";
			cin >> hourses;
			cout << "Enter registration number: ";
			cin >> registration;
			Car car(manifacturer, m, id, hourses, registration);
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

			string newReg;
			cout << "Enter new registration number: ";
			cin >> newReg;
			for (int i = 0; i < cars.size(); i++) {
				if (reg.compare(cars.at(i).getRegistrationNumber()) == 0) {
					cars.at(i).changeOwner(id, newReg);
					break;
				}
			}
			break;
		}
		case 4:
		{
			for (int i = 0; i < cars.size(); i++) {
				cout << cars.at(i).carInfo(people);
			}
			break;
		}
		}
		cin >> s;
	}

	ofstream ofs("saved.txt");
	ofs << people.size() << endl;
	for (int i = 0; i < people.size(); i++) {
		ofs << people.at(i);
	}
	ofs << cars.size() << endl;
	for (int i = 0; i < cars.size(); i++) {
		ofs << cars.at(i);
	}
	ofs.close();
}
