#include "VisualRenderer.cpp"
#include "FiguresInitializer.cpp"
#include <iostream>
#include <string>
#include <vector>


static std::vector<Figure*> objects;
static std::string currentColour = "white";
class ChessEngine {
public:
	void run() {
		FiguresInitializer f;
		f.initObjects(objects);
		while (true) {
			system("cls");
			std::vector<Figure*> & o = objects;
			Figure * blackKing;
			Figure * whiteKing;
			for (int i = 0; i < objects.size(); i++) {
				if ((*o.at(i)).getSymbol() == 'k' &&
					(*o.at(i)).getColor().compare("white") == 0) {
					whiteKing = o.at(i);
				}
				if ((*o.at(i)).getSymbol() == 'k' &&
					(*o.at(i)).getColor().compare("black") == 0) {
					blackKing = o.at(i);
				}
			}
			if((*blackKing).getPosX() != 0 && (*blackKing).getPosY() != 4){
				if ((*blackKing).getAvailableMoves(o).size() == 0) {
					std::cout << "White Win !" << std::endl;
					system("pause");
					return;
				}
			}
			if ((*whiteKing).getPosX() != 0 && (*whiteKing).getPosY() != 4) {
				if ((*whiteKing).getAvailableMoves(o).size() == 0) {
					std::cout << "Black Win !" << std::endl;
					system("pause");
					return;
				}
			}
			VisualRenderer renderer;
			std::cout << renderer.render(objects);
			std::string figure;
			std::string move;
			int figureCurrX;
			int figureCurrY;
			int newPosX;
			int newPosY;
			std::cout << currentColour << " turn" << std::endl;
			std::cout << "Enter figure coordinates: " << std::endl;
			std::getline(std::cin, figure);
			std::vector<Position> moves;
			while (true) {
				getCoordinates(figure, figureCurrX, figureCurrY);
				bool exists = false;
				for (int i = 0; i < objects.size(); i++) {

					if ((*o.at(i)).getPosX() == figureCurrY &&
						(*o.at(i)).getPosY() == figureCurrX &&
						(*o.at(i)).getColor() == currentColour) {
						exists = true;
						moves = (*o.at(i)).getAvailableMoves(o);
						break;
					}
				}
				if (exists == true) {
					break;
				}
				std::cout << "Try again!!" << std::endl;
				std::getline(std::cin, figure);
			}
			if (moves.size() != 0) {
				std::cout << "Enter yout move:" << std::endl;
				std::getline(std::cin, move);
				while (true) {
					getCoordinates(move, newPosX, newPosY);
					bool isDone = false;
					for (int i = 0; i < moves.size(); i++) {
						if (moves.at(i).getX() == newPosY &&
							moves.at(i).getY() == newPosX) {
							for (int i = 0; i < objects.size(); i++) {
								if ((*o.at(i)).getPosX() == figureCurrY &&
									(*o.at(i)).getPosY() == figureCurrX &&
									(*o.at(i)).getColor() == currentColour) {
									isDone = (*o.at(i)).move(Position(newPosY, newPosX), o);
								}
							}
						}
					}
					if (isDone == true) {
						break;
					}
					std::cout << "Wrond move! Try again!" << std::endl;
					std::getline(std::cin, move);
				}

				if (currentColour.compare("white") == 0) {
					currentColour = "black";
				}
				else {
					currentColour = "white";
				}
			}
			
		}
	}
	private:
		void getCoordinates(std::string figureCordinates, int & x, int & y) {
			switch (figureCordinates.at(0)) {
			case 'A':
				y = 0;
				break;
			case 'B':
				y = 1;
				break;
			case 'C':
				y = 2;
				break;
			case 'D':
				y = 3;
				break;
			case 'E':
				y = 4;
				break;
			case 'F':
				y = 5;
				break;
			case 'G':
				y = 6;
				break;
			case 'H':
				y = 7;
				break;
			}
			switch (figureCordinates.at(1)) {
			case '1':
				x = 0;
				break;
			case '2':
				x = 1;
				break;
			case '3':
				x = 2;
				break;
			case '4':
				x = 3;
				break;
			case '5':
				x = 4;
				break;
			case '6':
				x = 5;
				break;
			case '7':
				x = 6;
				break;
			case '8':
				x = 7;
				break;
			}
		}
};