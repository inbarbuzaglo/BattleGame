#include "Print.h"
#include <string>
#include <iostream>

using namespace std;

Print::Print ()
    :m_emptyCell (emptyCell), m_player1 (player1), m_player2 (player2) 
{
}

void Print::PrintBoard (Board* board, const Player* player1) 
{

    int n = board->m_size;

    for (int i = 0; i < n / 10 + 1; i++) cout << " ";
    cout << "+";
    for (int i = 0; i < n; i++) cout << "--";
    cout << "+";
    cout.put (cout.widen ('\n'));
    cout.flush ();

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n / 10 - i / 10; j++) cout << " ";
        cout << i << "|";

        for (int j = 0; j < n; j++) {

            BoardCell c = board->GetCell (i, j);
            if (!c.IsCellFull ()) cout << this->m_emptyCell;
            else if (c.GetPlayer () == player1) cout << this->m_player1;
            else cout << this->m_player2;

            cout << " ";
        }
        cout << "|" << i;
        cout.put (cout.widen ('\n'));
        cout.flush ();
    }
    for (int i = 0; i < n / 10 + 1; i++) cout << " ";
    cout << "+";
    for (int i = 0; i < n; i++) cout << "--";
    cout << "+";
    cout.put (cout.widen ('\n'));
    cout.flush ();
    for (int i = 0; i < n / 10 + 2; i++) cout << " ";
    cout.put (cout.widen ('\n'));
    cout.flush ();

}