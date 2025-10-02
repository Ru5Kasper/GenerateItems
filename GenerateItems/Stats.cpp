#include "Stats.h"
#include <iostream>
#include <vector>
#include <windows.h>

static std::map<Rarity, int> rarityColors = {
    {Rarity::COMMON,    7},   // белый
    {Rarity::RARE,      9},   // голубой
    {Rarity::EPIC,      13},  // фиолетовый
    {Rarity::LEGENDARY, 14},  // жёлтый
    {Rarity::MYTHIC,    12},  // красный
    {Rarity::ULTRA,     11}   // бирюзовый
};

static std::map<Rarity, std::string> rarityNames = {
    {Rarity::COMMON,    "Обычный"},
    {Rarity::RARE,      "Редкий"},
    {Rarity::EPIC,      "Эпический"},
    {Rarity::LEGENDARY, "Легендарный"},
    {Rarity::MYTHIC,    "Мифический (красный)"},
    {Rarity::ULTRA,     "Ультра-редкий (радужный)"}
};

void Stats::addDrop(const Item& item) {
    rarityStats[item.rarity]++;
    itemStats[item.name].first = item.rarity;  // сохраняем редкость
    itemStats[item.name].second++;             // увеличиваем количество
}

void Stats::printStats() const {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    std::cout << "\n=== Статистика выпадений ===\n";

    std::vector<Rarity> order = {
        Rarity::COMMON, Rarity::RARE, Rarity::EPIC,
        Rarity::LEGENDARY, Rarity::MYTHIC, Rarity::ULTRA
    };

    for (auto r : order) {
        if (rarityStats.count(r) == 0) continue;

        SetConsoleTextAttribute(hConsole, rarityColors[r]);
        std::cout << "\n" << rarityNames[r] << " — " << rarityStats.at(r) << " шт.\n";
        SetConsoleTextAttribute(hConsole, 7);

        // Выводим предметы этой редкости
        for (auto& p : itemStats) {
            if (p.second.first == r) {  // сравниваем редкость
                SetConsoleTextAttribute(hConsole, rarityColors[r]);
                std::cout << "  " << p.first << " — " << p.second.second << " шт.\n";
                SetConsoleTextAttribute(hConsole, 7);
            }
        }
    }

    std::cout << "=============================\n";
}
