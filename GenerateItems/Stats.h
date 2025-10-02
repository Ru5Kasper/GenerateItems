#pragma once
#include "LootTable.h"
#include <map>

class Stats {
public:
    void addDrop(const Item& item);
    void printStats() const;

private:
    std::map<Rarity, int> rarityStats; // количество выпадений по редкости
    std::map<std::string, std::pair<Rarity, int>> itemStats;
    // ключ = имя предмета, значение = <редкость, количество>
};
