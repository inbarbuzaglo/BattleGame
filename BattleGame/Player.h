#pragma once
#include <string>

class Player
{

public:
    Player  () {}
    ~Player () {}

    void Shoot ();

    bool operator==(const Player& other) { return (this == &other); }
    bool operator!=(const Player& other) { return !(*this == other); }

};