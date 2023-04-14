#include "BoardCell.h"

BoardCell::BoardCell (int row, int col)
    :m_colPos (col), m_rowPos (row),m_cellFull (false), m_player (NULL)
{
}

int BoardCell::GetRow () const
{
    return this->m_rowPos;
}

int BoardCell::GetColumn () const
{
    return this->m_colPos;
}

Player* BoardCell::GetPlayer () const
{
    return m_player;
}

bool BoardCell::FillCell (Player* player)
{
    if (this->m_cellFull)
        return false;
    this->m_cellFull = true;
    this->m_player = player;

    return true;
}

void BoardCell::FreeCell ()
{
    this->m_cellFull = false;
    this->m_player = NULL;
}

Player* BoardCell::TakeTurns (Player* newPlayer)
{
    Player* oldPlayer = this->m_player;
    this->FillCell (newPlayer);

    return oldPlayer;
}

bool BoardCell::IsCellFull () const
{
    return this->m_cellFull;
}