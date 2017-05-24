#include "Renderer.h"
#include "Knight.cpp"
#include "Pawn.cpp"
#include "King.cpp"
#include "Queen.cpp"
#include "Bishop.cpp"
#include "Rook.cpp"
#include <string>
#include <vector>
#include <sstream>
#include <string>

class VisualRenderer : public Renderer {
public:
	std::string render(const std::vector<Figure*> &figures) {
		
		char figureMatrix[8][8];
		std::string s;
		int a = 0;
		int b = 1;
		int temp;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (i % 2 == a && j % 2 == b) {
					figureMatrix[i][j] = '*';
				}
				else {
					figureMatrix[i][j] = ' ';
				}
			}
			temp = a;
			a = b;
			b = temp;
		}
		for (int i = 0; i < figures.size(); i++) {
			int posX = (*figures.at(i)).getPosX();
			int posY = (*figures.at(i)).getPosY();
			char c = (*figures.at(i)).getSymbol();
			if ((*figures.at(i)).getColor().compare("black") == 0) {
				c -= 32;
			}
			figureMatrix[posX][posY] = c;
		}
		std::stringstream ss;
		char gridChar = 'A';
		int gridInt = 1;
		for (int i = 0; i < 8; i++) {
			for (int k = 0; k < 17; k++) {
				ss << "-";
			}
			ss << std::endl;
			for (int j = 0; j < 8; j++) {
				ss << "|" << figureMatrix[i][j];
			}
			ss << "|" << " " << gridChar << std::endl;
			gridChar++;
		}
		for (int i = 0; i < 17; i++) {
			ss << "-";
		}
		ss << std::endl;
		for (int i = 1; i < 18; i++) {
			if (i % 2 == 0) {
				ss << " " << gridInt;
				gridInt++;
			}
		}
		ss << std::endl;
		s = ss.str();
		ss.str("");
		return s;
	}
};