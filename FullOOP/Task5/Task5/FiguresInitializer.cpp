#include "ObjectsInitializer.h"
#include<vector>
#include "Knight.cpp"
#include "Pawn.cpp"
#include "King.cpp"
#include "Queen.cpp"
#include "Bishop.cpp"
#include "Rook.cpp"

static Rook r1("black", 0, 0);
static Knight n1("black", 0, 1);
static Bishop b1("black", 0, 2);
static Queen q1("black", 0, 3);
static King k1("black", 0, 4);
static Bishop b2("black", 0, 5);
static Knight n2("black", 0, 6);
static Rook r2("black", 0, 7);
static Pawn p1("black", 1, 0);
static Pawn p2("black", 1, 1);
static Pawn p3("black", 1, 2);
static Pawn p4("black", 1, 3);
static Pawn p5("black", 1, 4);
static Pawn p6("black", 1, 5);
static Pawn p7("black", 1, 6);
static Pawn p8("black", 1, 7);
static Rook R1("white", 7, 0);
static Knight N1("white", 7, 1);
static Bishop B1("white", 7, 2);
static Queen Q1("white", 7, 3);
static King K1("white", 7, 4);
static Bishop B2("white", 7, 5);
static Knight N2("white", 7, 6);
static Rook R2("white", 7, 7);
static Pawn P1("white", 6, 0);
static Pawn P2("white", 6, 1);
static Pawn P3("white", 6, 2);
static Pawn P4("white", 6, 3);
static Pawn P5("white", 6, 4);
static Pawn P6("white", 6, 5);
static Pawn P7("white", 6, 6);
static Pawn P8("white", 6, 7);

class FiguresInitializer : public ObjectsInitializer {
public:
	void initObjects(std::vector<Figure*> & objects) {
		objects.push_back(&r1);
		objects.push_back(&n1);
		objects.push_back(&b1);
		objects.push_back(&q1);
		objects.push_back(&k1);
		objects.push_back(&b2);
		objects.push_back(&n2);
		objects.push_back(&r2);
		objects.push_back(&p1);
		objects.push_back(&p2);
		objects.push_back(&p3);
		objects.push_back(&p4);
		objects.push_back(&p5);
		objects.push_back(&p6);
		objects.push_back(&p7);
		objects.push_back(&p8);
		objects.push_back(&R1);
		objects.push_back(&N1);
		objects.push_back(&B1);
		objects.push_back(&Q1);
		objects.push_back(&K1);
		objects.push_back(&B2);
		objects.push_back(&N2);
		objects.push_back(&R2);
		objects.push_back(&P1);
		objects.push_back(&P2);
		objects.push_back(&P3);
		objects.push_back(&P4);
		objects.push_back(&P5);
		objects.push_back(&P6);
		objects.push_back(&P7);
		objects.push_back(&P8);

	}
};