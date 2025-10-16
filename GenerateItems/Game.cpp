#include "Game.h"
#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>

static std::map<Rarity, int> rarityColors = {
    {Rarity::COMMON,    7},   // белый
    {Rarity::RARE,      9},   // голубой
    {Rarity::EPIC,      13},  // фиолетовый
    {Rarity::LEGENDARY, 14},  // жёлтый
    {Rarity::MYTHIC,    12},  // красный
    {Rarity::ULTRA,     11}   // бирюзовый (по умолчанию)
};

Game::Game() : running(true) {
    srand(time(0));
}

void printRainbowText(const std::string& text, HANDLE hConsole) {
    // Радужные цвета по порядку
    int rainbowColors[] = { 12, 14, 10, 11, 9, 13 };
    int count = sizeof(rainbowColors) / sizeof(rainbowColors[0]);

    for (int i = 0; i < 12; i++) { // 12 смен цветов
        int color = rainbowColors[i % count];
        SetConsoleTextAttribute(hConsole, color);
        std::cout << "\rВыпал предмет: " << text << "   ";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(120));
    }

    SetConsoleTextAttribute(hConsole, 7); // сброс в белый
    std::cout << "\n";
}

void Game::run() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int turn = -1;
    while (running) {
        ++turn;
        std::cout << "\n1. Крутить рулетку\n";
        std::cout << "2. Посмотреть статистику\n";
        std::cout << "3. Выйти\n";
        std::cout << "Ваш выбор: ";

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
                std::cout << "Выпал предмет: " << it.name << "\n";
                SetConsoleTextAttribute(hConsole, 7); // сброс
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
