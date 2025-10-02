#include "Game.h"
#include <windows.h>
#include <locale>

int main() {
    setlocale(LC_ALL, "ru");
    Game game;
    game.run();
    return 0;
}
