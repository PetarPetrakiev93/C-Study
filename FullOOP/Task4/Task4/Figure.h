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
	std::string color;
	Position pos;
	Figure(char symbol, std::string color, int x, int y) :
		symbol(symbol),
		color(color),
		pos(Position(x, y)){
	}
public:
	virtual std::vector<Position> getAvailableMoves(const std::vector<Figure*> figures) = 0;
	virtual bool move(Position newPosition, std::vector<Figure*> &figures) = 0;
	char getSymbol() const {
		return this->symbol;
	}
	std::string getColor() const{
		return this->color;
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
