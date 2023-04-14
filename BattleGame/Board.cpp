#include "Board.h"
#include <string>

using namespace std;

Board::Board (int size)
    :m_size (size), m_fullCells (0) 
{
    m_board = vector <vector<BoardCell>> ();
    for (int i = 0; i < size; i++) {
        m_board.push_back (vector<BoardCell> ());
        for (int j = 0; j < size; j++) {      
            m_board[i].push_back (BoardCell (i, j));
        }
    }
}

Board::~Board () 
{
}


int Board::GetSize () const 
{ 
    return m_size; 
}

BoardCell& Board::GetCell (const int row, const int col) 
{
    BoardCell& cell = m_board[row][col];
    return cell;
}

bool Board::IsFull () const 
{ 
    return m_fullCells == m_size * m_size; 
}

bool Board::IsEmpty () const 
{
    return m_fullCells == 0; 
}

bool Board::PlayAt (const int row, const int col, Player* p) 
{
    BoardCell& cell = GetCell (row, col);

    if (cell.IsCellFull ()) {
        return false;
    }
    else {
        cell.FillCell (p);
        return true;
    }
}

void Board::PlacePlayersRandomally (Player* p1, Player* p2)
{
    bool flag = true;

    while (!IsFull()) {
        srand ((unsigned)time (0));
        int i = (rand () % m_size);
        int j = (rand () % m_size);
        BoardCell& cell = GetCell (i, j);

        if (!cell.IsCellFull ()) {
            if (flag) {
                cell.FillCell (p1);
                flag = false;
                m_fullCells++;
            }
            else {
                cell.FillCell (p2);
                flag = true;
                m_fullCells++;
            }
        }
    }
}

