#include "Stats.h"
#include <iostream>
#include <vector>
#include <windows.h>

static std::map<Rarity, int> rarityColors = {
    {Rarity::COMMON,    7},   // �����
    {Rarity::RARE,      9},   // �������
    {Rarity::EPIC,      13},  // ����������
    {Rarity::LEGENDARY, 14},  // �����
    {Rarity::MYTHIC,    12},  // �������
    {Rarity::ULTRA,     11}   // ���������
};

static std::map<Rarity, std::string> rarityNames = {
    {Rarity::COMMON,    "�������"},
    {Rarity::RARE,      "������"},
    {Rarity::EPIC,      "���������"},
    {Rarity::LEGENDARY, "�����������"},
    {Rarity::MYTHIC,    "���������� (�������)"},
    {Rarity::ULTRA,     "������-������ (��������)"}
};

void Stats::addDrop(const Item& item) {
    rarityStats[item.rarity]++;
    itemStats[item.name].first = item.rarity;  // ��������� ��������
    itemStats[item.name].second++;             // ����������� ����������
}

void Stats::printStats() const {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    std::cout << "\n=== ���������� ��������� ===\n";

    std::vector<Rarity> order = {
        Rarity::COMMON, Rarity::RARE, Rarity::EPIC,
        Rarity::LEGENDARY, Rarity::MYTHIC, Rarity::ULTRA
    };

    for (auto r : order) {
        if (rarityStats.count(r) == 0) continue;

        SetConsoleTextAttribute(hConsole, rarityColors[r]);
        std::cout << "\n" << rarityNames[r] << " � " << rarityStats.at(r) << " ��.\n";
        SetConsoleTextAttribute(hConsole, 7);

        // ������� �������� ���� ��������
        for (auto& p : itemStats) {
            if (p.second.first == r) {  // ���������� ��������
                SetConsoleTextAttribute(hConsole, rarityColors[r]);
                std::cout << "  " << p.first << " � " << p.second.second << " ��.\n";
                SetConsoleTextAttribute(hConsole, 7);
            }
        }
    }

    std::cout << "=============================\n";
}
