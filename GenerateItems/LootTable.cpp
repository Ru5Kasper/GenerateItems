#include "LootTable.h"
#include <cstdlib>
#include <ctime>

LootTable::LootTable() {
    chances = {
        {Rarity::COMMON,    60.0},
        {Rarity::RARE,      20.0},
        {Rarity::EPIC,      5.0},
        {Rarity::LEGENDARY, 2.0},
        {Rarity::MYTHIC,    0.1},
        {Rarity::ULTRA,     0.01}
    };

    items = {
        {"Обычный меч", Rarity::COMMON},
        {"Обычное кольцо", Rarity::COMMON},
        {"Обычный лук", Rarity::COMMON},
        {"Обычный щит", Rarity::COMMON},
        {"Обычный посох", Rarity::COMMON},
        {"Редкий посох", Rarity::RARE},
        {"Редкий меч", Rarity::RARE},
        {"Редкий лук", Rarity::RARE},
        {"Редкое кольцо", Rarity::RARE},
        {"Щит силы", Rarity::EPIC},
        {"Клинок правды", Rarity::EPIC},
        {"Посох огня", Rarity::EPIC},
        {"Посох воды", Rarity::EPIC},
        {"Эпический шлем", Rarity::EPIC},
        {"Меч Пламени Дракона", Rarity::LEGENDARY},
        {"Ледяной Клинок Севера", Rarity::LEGENDARY},
        {"Посох Звёздного Света", Rarity::LEGENDARY},
        {"Амулет Лунного Сияния", Rarity::LEGENDARY},
        {"Перстень Теней", Rarity::LEGENDARY},
        {"Жезл Времени и Судьбы", Rarity::MYTHIC},
        {"Светозарный Рассекатель", Rarity::MYTHIC},
        {"Сердце Замёрзшего Солнца", Rarity::MYTHIC},
        {"Флакон Эссенции Феникса", Rarity::MYTHIC},
        {"Клинок Бездны", Rarity::ULTRA},
        {"Сфера Начала и Конца", Rarity::ULTRA},
        {"Посох Хаоса", Rarity::ULTRA}
    };
}

Rarity LootTable::getRandomRarity() const {
    // Считаем общую сумму весов
    double totalWeight = 0.0;
    for (auto& p : chances) {
        totalWeight += p.second;
    }

    // Случайное число от 0 до totalWeight
    double roll = (rand() / (double)RAND_MAX) * totalWeight;

    double sum = 0.0;
    for (auto& p : chances) {
        sum += p.second;
        if (roll < sum) return p.first;
    }

    return Rarity::COMMON; // fallback
}

Item LootTable::getRandomItem(Rarity rarity) const {
    std::vector<Item> pool;
    for (auto& i : items) {
        if (i.rarity == rarity) pool.push_back(i);
    }
    return pool[rand() % pool.size()];
}
