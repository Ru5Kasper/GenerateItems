#pragma once
#include <string>

enum class Rarity {
    COMMON,
    RARE,
    EPIC,
    LEGENDARY,
    MYTHIC,   // ���������� �������
    ULTRA     // ������ ������ ��������
};

struct Item {
    std::string name;
    Rarity rarity;
};
