#pragma once
#include "BoardCell.h"
#include "Player.h"
#include <vector>
#include <random>
#include <iostream>
class Board
{
public:

                Board                   (int size);
               ~Board                   ();

    int        GetSize                  () const;
    BoardCell& GetCell                  (const int row, const int col);

    bool IsFull                         () const;
    bool IsEmpty                        () const;

    bool  PlayAt                        (const int row, const int col, Player* p);
    void  PlacePlayersRandomally        (Player* p1, Player* p2);


private:
    int                                  m_size;
    std::vector <std::vector<BoardCell>> m_board;
    int                                  m_fullCells;

    friend class Print;
};
