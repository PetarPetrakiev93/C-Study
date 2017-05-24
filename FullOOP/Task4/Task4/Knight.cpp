#include "Figure.h"

class Knight : public Figure {
public:
	Knight(std::string color, int x, int y) :
		Figure('k', color, x, y) {}
	std::vector<Position> getAvailableMoves(const std::vector<Figure*> figures) {
		
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