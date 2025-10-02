#pragma once
#include "Item.h"
#include <vector>
#include <map>

class LootTable {
private:
    std::map<Rarity, double> chances;
    std::vector<Item> items;

public:
    LootTable();

    Rarity getRandomRarity() const;
    Item getRandomItem(Rarity rarity) const;
};
