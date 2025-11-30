#include "board.h"
#include <iostream>

const int WIDTH = 20;   // Ancho del tablero
const int HEIGHT = 10;  // Alto del tablero

// Dibuja en consola el tablero, la serpiente, la fruta y la puntuación.
void DrawBoard(int headX, int headY,
    const std::vector<Position>& tail,
    const Position& fruit,
    int score)
{
    system("cls");
    std::cout << "Score: " << score << std::endl;

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            if (y == 0 || y == HEIGHT - 1)
                std::cout << "-";
            else if (x == 0 || x == WIDTH - 1)
                std::cout << "|";
            else if (x == headX && y == headY)
                std::cout << "X";
            else if (x == fruit.x && y == fruit.y)
                std::cout << "O";
            else {
                bool isTail = false;
                for (const auto& t : tail) {
                    if (t.x == x && t.y == y) {
                        std::cout << "x";
                        isTail = true;
                        break;
                    }
                }
                if (!isTail) std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}
