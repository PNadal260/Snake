#include "snake.h"

int gHeadX;
int gHeadY;
std::vector<Position> gTail;
Direction gDir = DIR_NONE;

// Inicializa la serpiente en el centro del tablero
void InitSnake(int width, int height) {
    gHeadX = width / 2;
    gHeadY = height / 2;
    gDir = DIR_NONE;
    gTail.clear();
}
// Cambia la dirección de la serpiente
void ChangeDirection(Direction newDir) {
    if (gDir == DIR_NONE) {
        gDir = newDir;
        return;
    }
    if ((gDir == DIR_UP && newDir == DIR_DOWN) ||
        (gDir == DIR_DOWN && newDir == DIR_UP) ||
        (gDir == DIR_LEFT && newDir == DIR_RIGHT) ||
        (gDir == DIR_RIGHT && newDir == DIR_LEFT)) {
        return;
    }
    gDir = newDir;
}
// Actualiza la posición de la cabeza y la cola
void UpdateSnake() {
    if (gDir == DIR_NONE)
        return;

    if (!gTail.empty()) {
        for (int i = (int)gTail.size() - 1; i > 0; --i)
            gTail[i] = gTail[i - 1];
        gTail[0] = { gHeadX, gHeadY };
    }

    switch (gDir) {
    case DIR_UP:    --gHeadY; break;
    case DIR_DOWN:  ++gHeadY; break;
    case DIR_LEFT:  --gHeadX; break;
    case DIR_RIGHT: ++gHeadX; break;
    default: break;
    }
}
// Añade un nuevo segmento al cuerpo
void GrowSnake() {
    Position newSeg = gTail.empty() ? Position{ gHeadX, gHeadY } : gTail.back();
    gTail.push_back(newSeg);
}
// Verifica si la cabeza colisiona con la cola
bool CheckSelfCollision() {
    for (const auto& seg : gTail)
        if (seg.x == gHeadX && seg.y == gHeadY)
            return true;
    return false;
}
// Verifica si la cabeza colisiona
bool CheckWallCollision(int width, int height) {
    return (gHeadX <= 0 || gHeadX >= width - 1 ||
        gHeadY <= 0 || gHeadY >= height - 1);
}
