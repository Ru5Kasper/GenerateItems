#pragma once
#include <string>

enum class Rarity {
    COMMON,
    RARE,
    EPIC,
    LEGENDARY,
    MYTHIC,   // мифическая красная
    ULTRA     // ультра редкая радужная
};

struct Item {
    std::string name;
    Rarity rarity;
};
