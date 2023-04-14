#include <iostream>
#include <random>
#include "Player.h"
#include "Print.h"

using namespace std;

const int boardSize = 5;

int main (int argc, char* argv[])
{
	Board* board = new Board (boardSize);
	Player* p1 = new Player ();
	Player* p2 = new Player ();
	board->PlacePlayersRandomally (p1, p2);
	board->PlayAt (0, 1, p1);
	board->PlayAt (0, 2, p2);
	Print* printer = new Print ();

	printer->PrintBoard (board, p2);

	delete board;
	delete p1, p2;
	delete printer;

	return 0;
}