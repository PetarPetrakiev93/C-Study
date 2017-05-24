#include "Figure.h"

class Bishop : public Figure {
public:
	Bishop(std::string color, int x, int y) :
		Figure('b', color, x, y) {}
	std::vector<Position> getAvailableMoves(const std::vector<Figure*> figures) {
		std::vector<Position> moves;
		int tempX = 1;
		int tempY = 1;
		bool isTrue = true;
		while (isTrue == true && (this->getPosX() + tempX) < 8 && (this->getPosX() + tempY) < 8) {
			for (int i = 0; i < figures.size(); i++) {
				if ((*figures.at(i)).getPosX() == (this->getPosX() + tempX) &&
					(*figures.at(i)).getPosY() == (this->getPosY() + tempY)) {
					if (this->color.compare((*figures.at(i)).getColor()) == 0 || (*figures.at(i)).getSymbol == 'k') {
						isTrue = false;
						break;
					}
					
				}
			}
			if (isTrue != false) {
				moves.push_back(Position((this->getPosX() + tempX), (this->getPosY() + tempY)));
			}
			tempX++;
			tempY++;
		}
		tempX = 1;
		tempY = 1;
		isTrue = true;
		while (isTrue == true && (this->getPosX() - tempX) > -1 && (this->getPosX() + tempY) < 8) {
			for (int i = 0; i < figures.size(); i++) {
				if ((*figures.at(i)).getPosX() == (this->getPosX() - tempX) &&
					(*figures.at(i)).getPosY() == (this->getPosY() + tempY)) {
					if (this->color.compare((*figures.at(i)).getColor()) == 0 || (*figures.at(i)).getSymbol == 'k') {
						isTrue = false;
						break;
					}
				}
			}
			if (isTrue != false) {
				moves.push_back(Position((this->getPosX() - tempX), (this->getPosY() + tempY)));
			}
			tempX++;
			tempY++;
		}
		tempX = 1;
		tempY = 1;
		isTrue = true;
		while (isTrue == true && (this->getPosX() + tempX) < 8 && (this->getPosX() - tempY) > -1) {
			for (int i = 0; i < figures.size(); i++) {
				if ((*figures.at(i)).getPosX() == (this->getPosX() + tempX) &&
					(*figures.at(i)).getPosY() == (this->getPosY() - tempY)) {
					if (this->color.compare((*figures.at(i)).getColor()) == 0 || (*figures.at(i)).getSymbol == 'k') {
						isTrue = false;
						break;
					}
				}
			}
			if (isTrue != false) {
				moves.push_back(Position((this->getPosX() + tempX), (this->getPosY() - tempY)));
			}
			tempX++;
			tempY++;
		}
		tempX = 1;
		tempY = 1;
		isTrue = true;
		while (isTrue == true && (this->getPosX() - tempX) > -1 && (this->getPosX() - tempY) > -1) {
			for (int i = 0; i < figures.size(); i++) {
				if ((*figures.at(i)).getPosX() == (this->getPosX() - tempX) &&
					(*figures.at(i)).getPosY() == (this->getPosY() - tempY)) {
					if (this->color.compare((*figures.at(i)).getColor()) == 0 || (*figures.at(i)).getSymbol == 'k') {
						isTrue = false;
						break;
					}
				}
			}
			if (isTrue != false) {
				moves.push_back(Position((this->getPosX() - tempX), (this->getPosY() - tempY)));
			}
			tempX++;
			tempY++;
		}
		return moves;
	}

	bool move(Position newPosition, std::vector<Figure*> &figures) {
		std::vector<Position> availablePositions = getAvailableMoves(figures);
		for (int i = 0; i < availablePositions.size(); i++) {
			if (availablePositions.at(i).getX() == newPosition.getX() &&
				availablePositions.at(i).getY() == newPosition.getY()) {
				for (int j = 0; j < figures.size(); j++) {
					if (availablePositions.at(i).getX() == (*figures.at(j)).getPosX() &&
						availablePositions.at(i).getY() == (*figures.at(j)).getPosY()) {
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