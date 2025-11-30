#pragma once
#include <vector>
#include "board.h"

enum Direction {
    DIR_NONE,
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT
};

class Snake {
public:
    Snake(int width, int height);

    void Update();
    void ChangeDirection(Direction newDir);

    int  GetHeadX() const { return m_headX; }
    int  GetHeadY() const { return m_headY; }
    const std::vector<Position>& GetTail() const { return m_tail; }

private:
    int m_headX;
    int m_headY;
    std::vector<Position> m_tail;
    Direction m_dir;
};
