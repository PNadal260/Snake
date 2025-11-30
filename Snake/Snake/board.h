#pragma once
#include <vector>

struct Position {
    int x;
    int y;
};

extern const int WIDTH;
extern const int HEIGHT;

void DrawBoard(int headX, int headY, const std::vector<Position>& tail);
