#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

class AstronomicalObject {
	string solarSystem;
	int position;
	int mass;
	int radius;
	string type;
	string nickname;

public:
	AstronomicalObject() {};
	AstronomicalObject(string solarSystem, int position, int mass, int radius, string type) :
		solarSystem(solarSystem),
		position(position),
		mass(mass),
		radius(radius) {
		this->setType(type);
		if (this->type.compare("star") == 0) {
			this->position = 0;
		}
	};
	AstronomicalObject(string solarSystem, int position, int mass, int radius, string type, string nickname) :
		solarSystem(solarSystem),
		position(position),
		mass(mass),
		radius(radius),
		nickname(nickname){
		this->setType(type);
		if (this->type.compare("star") == 0) {
			this->position = 0;
		}
	};

private:
	void setType(string type) {
		if (type.compare("star") == 0 ||
			type.compare("rocky planet") == 0 ||
			type.compare("gas gient") == 0) {
			this->type = type;
		}
		else {
			this->type = "unknown";
		}
	}
public:
	void changeSolarSystem(string solarSystem) {
		this->solarSystem = solarSystem;
	}
	void changeType(string type) {
		if (this->type.compare("unknown") == 0) {
			setType(type);
		}
	}
	string getSolarSystem() const{
		return this->solarSystem;
	}
	string getDesignation() const {
		stringstream ss;
		ss << this->solarSystem << "-" << this->position;
		if (this->nickname.compare("") == 1) {
			ss << " (" << this->nickname << ")";
		}
		string temp = ss.str();
		ss.str("");
		return temp;
	}
	string getInfo() const {
		stringstream ss;
		ss << getDesignation() << " {mass: " << this->mass << ", radius: " << this->radius << "}";
		string temp = ss.str();
		ss.str("");
		return temp;
	}
	int getPosition() const {
		return this->position;
	}
	friend ostream& operator<<(ostream& os, const AstronomicalObject& s)
	{
		os << s.solarSystem << '\n';
		os << s.position << '\n';
		os << s.mass << '\n';
		os << s.radius << '\n';
		os << s.type << '\n';
		os << s.nickname << '\n';
		return os;
	};
	friend istream& operator >> (istream& is, AstronomicalObject& s)
	{
		is >> s.solarSystem >> s.position >> s.mass >> s.radius >> s.type >> s.nickname;
		
		return is;
	};
};

int main() {
	vector<AstronomicalObject> objects;
	ifstream ifs("saved.txt");
	ifstream ifsl("savedLen.txt");
	int len;
	ifsl >> len;
	for (int i = 0; i < len; i++) {
		AstronomicalObject ao;
		ifs >> ao;
		objects.push_back(ao);
	}
	ifsl.close();
	ifs.close();
	string s;
	cin >> s;
	ofstream ofs("saved.txt");
	while (s != "end") {
		int command = stoi(s);
		switch (command)
		{
		case 0:
		{
			string solarS;
			int position;
			int mass;
			int radius;
			string type;
			string nickname;
			cout << "Enter solar system: ";
			cin >> solarS;
			cout << "Enter position: ";
			cin >> position;
			cout << "Enter mass: ";
			cin >> mass;
			cout << "Enter radius: ";
			cin >> radius;
			cout << "Enter type: ";
			cin >> type;
			cout << "Enter nickname: ";
			cin >> nickname;
			if (nickname.compare("no") == 0) {
				nickname = "";
			}
			if (nickname.compare("") == 0) {
				AstronomicalObject o(solarS, position, mass, radius, type);
				objects.push_back(o);
				ofs << o;
			}
			else {
				AstronomicalObject o(solarS, position, mass, radius, type, nickname);
				objects.push_back(o);
				ofs << o;
			}
			break;
		}
		case 1:
		{
			string solarS;
			cout << "Enter solar sytem: ";
			cin >> solarS;
			for (int i = 0; i < objects.size(); i++) {
				if (solarS.compare(objects.at(i).getSolarSystem()) == 0) {
					cout << objects.at(i).getInfo() << endl;
				}
			}
			break;
		}
		case 2:
		{
			string solarS;
			int pos;
			cout << "Enter solar sytem: ";
			cin >> solarS;
			cout << "Enter position: ";
			cin >> pos;
			for (int i = 0; i < objects.size(); i++) {
				if (solarS.compare(objects.at(i).getSolarSystem()) == 0 && pos == objects.at(i).getPosition()) {
					cout << objects.at(i).getInfo() << endl;
				}
			}
			break;
		}
		default:
			break;
		}
		cin >> s;
	}
	ofs.close();
	ofstream ofsl("savedLen.txt");
	ofsl << objects.size();
}