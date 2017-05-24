#pragma once
#include "Figure.h"

class Pawn : public Figure {
public:
	Pawn(std::string color, int x, int y):
	Figure('p', color, x, y){}
	std::vector<Position> getAvailableMoves(const std::vector<Figure*> figures) {
		std::vector<Position> moves;
		if ((*color).compare("black") == 0) {
			bool isTrue1 = true;
			bool isTrue2 = true;
			bool isTrue3 = true;
			bool isEmpty1 = true;
			bool isEmpty2 = true;
			for (int i = 0; i < figures.size(); i++) {
				Figure * temp = figures.at(i);
				if ((*temp).getPosX() == (this->getPosX() + 1) &&
					(*temp).getPosY() == this->getPosY()) {
					isTrue1 = false;
				}
				
				if (((*temp).getPosX() == (this->getPosX() + 1) &&
					(*temp).getPosY() == (this->getPosY() + 1))) {
					isEmpty1 = false;
				}
				if (((*temp).getPosX() == (this->getPosX() + 1) &&
					(*temp).getPosY() == (this->getPosY() - 1))) {
					isEmpty2 = false;
				}

				if (((*temp).getPosX() == (this->getPosX() + 1) &&
					(*temp).getPosY() == (this->getPosY() + 1))) {

					if ((*temp).getColor().compare("white") == 0 || (*temp).getSymbol() == 'k') {
						isTrue2 = false;
					}
				}
				if (((*temp).getPosX() == (this->getPosX() + 1) &&
					(*temp).getPosY() == (this->getPosY() - 1))) {
					if ((*temp).getColor().compare("white") == 0 || (*temp).getSymbol() == 'k') {
						isTrue3 = false;
					}
				}
			}
			if ((this->getPosX() + 1) < 8) {
				if (isTrue1 == true) {
					moves.push_back(Position(this->getPosX() + 1, this->getPosY()));
				}
				if ((this->getPosY() + 1) < 8  && isTrue2 == true && isEmpty1 == false) {
					moves.push_back(Position(this->getPosX() + 1, this->getPosY() + 1));
				}
				if ((this->getPosY() - 1) > -1 && isTrue3 == true && isEmpty2 == false) {
					moves.push_back(Position(this->getPosX() + 1, this->getPosY() - 1));
				}
			}
		}
		else {
			bool isTrue1 = true;
			bool isTrue2 = true;
			bool isTrue3 = true;
			bool isEmpty1 = true;
			bool isEmpty2 = true;
			for (int i = 0; i < figures.size(); i++) {
				Figure * temp = figures.at(i);
				if ((*temp).getPosX() == (this->getPosX() - 1) &&
					(*temp).getPosY() == this->getPosY()) {
					isTrue1 = false;
				}
				if (((*temp).getPosX() == (this->getPosX() - 1) &&
					(*temp).getPosY() == (this->getPosY() + 1))) {
					isEmpty1 = false;
				}
				if (((*temp).getPosX() == (this->getPosX() - 1) &&
					(*temp).getPosY() == (this->getPosY() - 1))) {
					isEmpty2 = false;
				}
				if (((*temp).getPosX() == (this->getPosX() - 1) &&
					(*temp).getPosY() == (this->getPosY() + 1))) {
					if ((*temp).getColor().compare("black") == 0 || (*temp).getSymbol() == 'k') {
						isTrue2 = false;
					}
				}
				if (((*temp).getPosX() == (this->getPosX() - 1) &&
					(*temp).getPosY() == (this->getPosY() - 1))) {
					if ((*temp).getColor().compare("black") == 0 || (*temp).getSymbol() == 'k') {
						isTrue3 = false;
					}
				}
			}
			if ((this->getPosX() - 1) > -1) {
				if (isTrue1 == true) {
					moves.push_back(Position(this->getPosX() - 1, this->getPosY()));
				}
				if ((this->getPosY() + 1) < 8 && isTrue2 == true && isEmpty1 == false) {
					moves.push_back(Position(this->getPosX() - 1, this->getPosY() + 1));
				}
				if ((this->getPosY() - 1) > -1 && isTrue3 == true && isEmpty2 == false) {
					moves.push_back(Position(this->getPosX() - 1, this->getPosY() - 1));
				}
			}
		}
		return moves;
	}

	bool move(Position newPosition, std::vector<Figure*> &figures) {
		std::vector<Position> availablePositions = getAvailableMoves(figures);
		for (int i = 0; i < availablePositions.size(); i++) {
			if (availablePositions.at(i).getX() == newPosition.getX() &&
				availablePositions.at(i).getY() == newPosition.getY()) {
				for (int j = 0; j < figures.size(); j++) {
					if ((*figures.at(j)).getPosX() == newPosition.getX() &&
						(*figures.at(j)).getPosY() == newPosition.getY()) {
						figures.erase(figures.begin() + j);
					}
				}
				this->pos = newPosition;
				return true;
			}
		}
		return false;
	}
};