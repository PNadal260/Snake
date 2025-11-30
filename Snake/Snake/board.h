#pragma once
#include <vector>
#include "position.h"

extern const int WIDTH;
extern const int HEIGHT;
// Dibuja el tablero de juego con límites, la serpiente, la fruta y la puntuación.
void DrawBoard(int headX, int headY,
    const std::vector<Position>& tail,
    const Position& fruit,
    int score);
