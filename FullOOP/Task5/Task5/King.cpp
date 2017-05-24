#pragma once
#include "Figure.h"

class King : public Figure {
public:
	King(std::string color, int x, int y) :
		Figure('k', color, x, y) {}
	std::vector<Position> getAvailableMoves(const std::vector<Figure*> figures) {
		std::vector<Position> moves;
		std::vector<Position> possiblePos;
		int offSetPlusX = this->getPosX() + 1;
		int offSetMinusX = this->getPosX() - 1;
		int offSetPlusY = this->getPosY() + 1;
		int offSetMinusY = this->getPosY() - 1;
		if (offSetPlusX < 8) {
			possiblePos.push_back(Position((this->getPosX() + 1), this->getPosY()));
		}
		if (offSetPlusX < 8 && offSetMinusY > -1) {
			possiblePos.push_back(Position(this->getPosX() + 1, this->getPosY() - 1));
		}
		if (offSetPlusX < 8 && offSetPlusY < 8) {
			possiblePos.push_back(Position(this->getPosX() + 1, this->getPosY() + 1));
		}
		if (offSetMinusX > -1) {
			possiblePos.push_back(Position(this->getPosX() - 1, this->getPosY()));
		}
		if (offSetMinusX > -1 && offSetPlusX < 8) {
			possiblePos.push_back(Position(this->getPosX() - 1, this->getPosY() + 1));
		}
		if (offSetMinusX > -1 && offSetMinusY > -1) {
			possiblePos.push_back(Position(this->getPosX() - 1, this->getPosY() - 1));
		}
		if (offSetMinusY > -1) {
			possiblePos.push_back(Position(this->getPosX(), this->getPosY() - 1));
		}
		if (offSetPlusY > 8) {
			possiblePos.push_back(Position(this->getPosX(), this->getPosY() + 1));
		}
		for (int i = 0; i < possiblePos.size(); i++){
			Position p(possiblePos.at(i).getX(), possiblePos.at(i).getY());
			bool isPossible = true;
			for (int j = 0; j < figures.size(); j++) {
				if ((*figures.at(j)).getSymbol() != 'k'){
				if ((((*figures.at(j)).getPosX() == p.getX() &&
					(*figures.at(j)).getPosY() == p.getY() &&
					(*figures.at(j)).getColor().compare(this->getColor()) == 0))) {
					isPossible = false;
					break;
				}
				else {
					if ((*figures.at(j)).getColor().compare(this->getColor()) != 0) {
						std::vector<Position> othersPos = (*figures.at(j)).getAvailableMoves(figures);
						for (int k = 0; k < othersPos.size(); k++) {
							if (othersPos.at(k).getX() == p.getX() &&
								othersPos.at(k).getY() == p.getY()) {
								isPossible = false;
								break;
							}
						}
					}
				}
			}
			}
			if (isPossible == true) {
				moves.push_back(p);
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