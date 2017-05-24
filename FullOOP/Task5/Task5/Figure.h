#pragma once
#include <string>
#include <vector>
class Position {
	int posX;
	int posY;
public:
	
	Position(int x, int y) :
		posX(x),
		posY(y){}
	Position() {}
	int getX() const {
		return this->posX;
	}
	int getY() const {
		return this->posY;
	}
	void setX(int x) {
		this->posX = x;
	}
	void setY(int y) {
		this->posY = y;
	}
};

class Figure {
protected:
	char symbol;
	std::string * color;
	Position pos;
	Figure() {}
	Figure(char symbol, std::string color, int x, int y) :
		symbol(symbol),
		pos(Position(x, y)){
		this->color = new std::string(color);
	}
	Figure(const Figure& other) {
		this->pos = Position(other.getPosX(), other.getPosY());
		color = new std::string((other).getColor());
		this->symbol = other.getSymbol();
	}
	~Figure(){
		delete color;
	}
	Figure &operator=(const Figure &c)
	{
		if (this != &c) //be aware of self-copy
		{
			delete color;
			color = new std::string(c.getColor());
		}
		return *this;
	}
public:
	virtual std::vector<Position> getAvailableMoves(const std::vector<Figure*> figures) = 0;
	virtual bool move(Position newPosition, std::vector<Figure*> &figures) = 0;
	char getSymbol() const {
		return this->symbol;
	}
	std::string getColor() const{
		return *color;
	}
	int getPosX() const {
		return this->pos.getX();
	}
	int getPosY() const {
		return this->pos.getY();
	}
	void setPosX(int x) {
		this->pos.setX(x);
	}
	void setPosY(int y) {
		this->pos.setY(y);
	}
};