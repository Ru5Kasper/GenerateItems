#pragma once
#include "LootTable.h"
#include "Stats.h"

class Game {
private:
    LootTable lootTable;
    Stats stats;
    bool running;

public:
    Game();
    void run();
};
