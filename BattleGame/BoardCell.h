#pragma once
#include "Player.h"

class BoardCell
{
public:

    BoardCell (int row, int col);
    ~BoardCell () {}
    int     GetRow ()   const;
    int     GetColumn ()   const;
    Player* GetPlayer ()   const;

    bool    FillCell (Player* p);
    void    FreeCell ();
    Player* TakeTurns (Player* newPlayer);

    bool    IsCellFull () const;
private:
    Player*                 m_player;
    bool                    m_cellFull;
    int                     m_rowPos;
    int                     m_colPos;
};