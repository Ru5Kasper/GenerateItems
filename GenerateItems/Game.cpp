#include "Game.h"
#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>

static std::map<Rarity, int> rarityColors = {
    {Rarity::COMMON,    7},   // �����
    {Rarity::RARE,      9},   // �������
    {Rarity::EPIC,      13},  // ����������
    {Rarity::LEGENDARY, 14},  // �����
    {Rarity::MYTHIC,    12},  // �������
    {Rarity::ULTRA,     11}   // ��������� (�� ���������)
};

Game::Game() : running(true) {
    srand(time(0));
}

void printRainbowText(const std::string& text, HANDLE hConsole) {
    // �������� ����� �� �������
    int rainbowColors[] = { 12, 14, 10, 11, 9, 13 };
    int count = sizeof(rainbowColors) / sizeof(rainbowColors[0]);

    for (int i = 0; i < 12; i++) { // 12 ���� ������
        int color = rainbowColors[i % count];
        SetConsoleTextAttribute(hConsole, color);
        std::cout << "\r����� �������: " << text << "   ";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(120));
    }

    SetConsoleTextAttribute(hConsole, 7); // ����� � �����
    std::cout << "\n";
}

void Game::run() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int turn = -1;
    while (running) {
        ++turn;
        std::cout << "\n1. ������� �������\n";
        std::cout << "2. ���������� ����������\n";
        std::cout << "3. �����\n";
        std::cout << "��� �����: ";

        /*int choice = 1;*/
        /*if (turn > 100)
            std::cin >> choice;*/
        int choice; std::cin >> choice;

        if (choice == 1) {
            Rarity r = lootTable.getRandomRarity();
            Item it = lootTable.getRandomItem(r);

            if (r == Rarity::ULTRA) {
                printRainbowText(it.name, hConsole);
            }
            else {
                SetConsoleTextAttribute(hConsole, rarityColors[r]);
                std::cout << "����� �������: " << it.name << "\n";
                SetConsoleTextAttribute(hConsole, 7); // �����
            }

            stats.addDrop(it);
        }
        else if (choice == 2) {
            stats.printStats();
        }
        else if (choice == 3) {
            running = false;
        }
    }
}
