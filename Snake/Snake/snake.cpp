#include "snake.h"

Snake::Snake(int width, int height) {
    m_headX = width / 2;
    m_headY = height / 2;
    m_dir = DIR_NONE;

    // si quieres, puedes empezar con cola vacía
    // o añadir segmentos:
    // m_tail.push_back({ m_headX - 1, m_headY });
}

void Snake::ChangeDirection(Direction newDir) {
    if (m_dir == DIR_NONE) {
        m_dir = newDir;
        return;
    }

    // Evitar girar 180°
    if ((m_dir == DIR_UP && newDir == DIR_DOWN) ||
        (m_dir == DIR_DOWN && newDir == DIR_UP) ||
        (m_dir == DIR_LEFT && newDir == DIR_RIGHT) ||
        (m_dir == DIR_RIGHT && newDir == DIR_LEFT)) {
        return;
    }

    m_dir = newDir;
}

void Snake::Update() {
    if (m_dir == DIR_NONE)
        return; // aún no se ha empezado a mover

    // mover cola
    if (!m_tail.empty()) {
        for (int i = (int)m_tail.size() - 1; i > 0; --i) {
            m_tail[i] = m_tail[i - 1];
        }
        m_tail[0] = { m_headX, m_headY };
    }

    // mover cabeza
    switch (m_dir) {
    case DIR_UP:    --m_headY; break;
    case DIR_DOWN:  ++m_headY; break;
    case DIR_LEFT:  --m_headX; break;
    case DIR_RIGHT: ++m_headX; break;
    default: break;
    }
}
