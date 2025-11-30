#include "board.h"
#include <iostream>

const int WIDTH = 20;
const int HEIGHT = 10;

void DrawBoard(int headX, int headY, const std::vector<Position>& tail) {
    system("cls"); // limpiar pantalla en Windows

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {

            if (y == 0 || y == HEIGHT - 1) {
                std::cout << "-";
            }
            else if (x == 0 || x == WIDTH - 1) {
                std::cout << "|";
            }
            else if (x == headX && y == headY) {
                std::cout << "X"; // cabeza
            }
            else {
                bool isTail = false;
                for (const auto& t : tail) {
                    if (t.x == x && t.y == y) {
                        std::cout << "x"; // cuerpo
                        isTail = true;
                        break;
                    }
                }
                if (!isTail)
                    std::cout << " ";
            }

        }
        std::cout << std::endl;
    }
}
