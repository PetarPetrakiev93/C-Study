#pragma once
#include "Figure.h"

class Knight : public Figure {
public:
	Knight(std::string color, int x, int y) :
		Figure('n', color, x, y) {}
	std::vector<Position> getAvailableMoves(const std::vector<Figure*> figures) {
		std::vector<Position> moves;
		int newX = this->getPosX() + 2;
		int newY = this->getPosY() + 1;
		bool isTrue = true;
		if (newX > -1 && newX < 8 && newY > -1 && newY < 8) {
			for (int i = 0; i < figures.size(); i++) {
				if (newX == (*figures.at(i)).getPosX() &&
					newY == (*figures.at(i)).getPosY()) {
					if (this->getColor().compare((*figures.at(i)).getColor()) == 0 ||
						(*figures.at(i)).getSymbol() == 'k') {
						isTrue = false;
					}
				}
			}
			if (isTrue == true) {
				moves.push_back(Position(newX, newY));
			}
		}
		newX = this->getPosX() + 1;
		newY = this->getPosY() + 2;
		isTrue = true;
		if (newX > -1 && newX < 8 && newY > -1 && newY < 8) {
			for (int i = 0; i < figures.size(); i++) {
				if (newX == (*figures.at(i)).getPosX() &&
					newY == (*figures.at(i)).getPosY()) {
					if (this->getColor().compare((*figures.at(i)).getColor()) == 0 ||
						(*figures.at(i)).getSymbol() == 'k') {
						isTrue = false;
					}
				}
			}
			if (isTrue == true) {
				moves.push_back(Position(newX, newY));
			}
		}
		newX = this->getPosX() - 1;
		newY = this->getPosY() - 2;
		isTrue = true;
		if (newX > -1 && newX < 8 && newY > -1 && newY < 8) {
			for (int i = 0; i < figures.size(); i++) {
				if (newX == (*figures.at(i)).getPosX() &&
					newY == (*figures.at(i)).getPosY()) {
					if (this->getColor().compare((*figures.at(i)).getColor()) == 0 ||
						(*figures.at(i)).getSymbol() == 'k') {
						isTrue = false;
					}
				}
			}
			if (isTrue == true) {
				moves.push_back(Position(newX, newY));
			}
		}
		newX = this->getPosX() - 2;
		newY = this->getPosY() - 1;
		isTrue = true;
		if (newX > -1 && newX < 8 && newY > -1 && newY < 8) {
			for (int i = 0; i < figures.size(); i++) {
				if (newX == (*figures.at(i)).getPosX() &&
					newY == (*figures.at(i)).getPosY()) {
					if (this->getColor().compare((*figures.at(i)).getColor()) == 0 ||
						(*figures.at(i)).getSymbol() == 'k') {
						isTrue = false;
					}
				}
			}
			if (isTrue == true) {
				moves.push_back(Position(newX, newY));
			}
		}
		newX = this->getPosX() - 1;
		newY = this->getPosY() + 2;
		isTrue = true;
		if (newX > -1 && newX < 8 && newY > -1 && newY < 8) {
			for (int i = 0; i < figures.size(); i++) {
				if (newX == (*figures.at(i)).getPosX() &&
					newY == (*figures.at(i)).getPosY()) {
					if (this->getColor().compare((*figures.at(i)).getColor()) == 0 ||
						(*figures.at(i)).getSymbol() == 'k') {
						isTrue = false;
					}
				}
			}
			if (isTrue == true) {
				moves.push_back(Position(newX, newY));
			}
		}
		newX = this->getPosX() + 1;
		newY = this->getPosY() - 2;
		isTrue = true;
		if (newX > -1 && newX < 8 && newY > -1 && newY < 8) {
			for (int i = 0; i < figures.size(); i++) {
				if (newX == (*figures.at(i)).getPosX() &&
					newY == (*figures.at(i)).getPosY()) {
					if (this->getColor().compare((*figures.at(i)).getColor()) == 0 ||
						(*figures.at(i)).getSymbol() == 'k') {
						isTrue = false;
					}
				}
			}
			if (isTrue == true) {
				moves.push_back(Position(newX, newY));
			}
		}
		newX = this->getPosX() - 2;
		newY = this->getPosY() + 1;
		isTrue = true;
		if (newX > -1 && newX < 8 && newY > -1 && newY < 8) {
			for (int i = 0; i < figures.size(); i++) {
				if (newX == (*figures.at(i)).getPosX() &&
					newY == (*figures.at(i)).getPosY()) {
					if (this->getColor().compare((*figures.at(i)).getColor()) == 0 ||
						(*figures.at(i)).getSymbol() == 'k') {
						isTrue = false;
					}
				}
			}
			if (isTrue == true) {
				moves.push_back(Position(newX, newY));
			}
		}
		newX = this->getPosX() + 2;
		newY = this->getPosY() - 1;
		isTrue = true;
		if (newX > -1 && newX < 8 && newY > -1 && newY < 8) {
			for (int i = 0; i < figures.size(); i++) {
				if (newX == (*figures.at(i)).getPosX() &&
					newY == (*figures.at(i)).getPosY()) {
					if (this->getColor().compare((*figures.at(i)).getColor()) == 0 ||
						(*figures.at(i)).getSymbol() == 'k') {
						isTrue = false;
					}
				}
			}
			if (isTrue == true) {
				moves.push_back(Position(newX, newY));
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