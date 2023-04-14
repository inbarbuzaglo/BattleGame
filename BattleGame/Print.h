#pragma once
#include "Board.h"

const char emptyCell = '#';
const char player1 = '1';
const char player2 = '2';

class Print 
{
public:
	Print           ();
	~Print			() {}
	void PrintBoard (Board* board, const Player* player);

private:
	char			m_emptyCell;
	char			m_player1;
	char			m_player2;
};