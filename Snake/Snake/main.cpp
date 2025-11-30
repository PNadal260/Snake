#define FRAME_RATE 150

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <ctime>
#include "position.h"
#include "board.h"
#include "keyboard.h"
#include "snake.h"

// Variables globales para la fruta, puntuación y estado de juego.
Position gFruit;
int gScore = 0;
bool gGameOver = false;

// Genera una nueva fruta en una posición libre del tablero.
void SpawnFruit() {
    bool ok = false;
    while (!ok) {
        
        gFruit.x = 1 + std::rand() % (WIDTH - 2);
        gFruit.y = 1 + std::rand() % (HEIGHT - 2);

        ok = true;
        if (gFruit.x == gHeadX && gFruit.y == gHeadY)
            ok = false;
        for (const auto& seg : gTail)
            if (seg.x == gFruit.x && seg.y == gFruit.y)
                ok = false;
    }
}

int main() {
    srand(std::time(NULL));

    InitSnake(WIDTH, HEIGHT);   // Inicializa la serpiente
    SpawnFruit();               // Genera la primera fruta
    gScore = 0;
    gGameOver = false;
    // Bucle principal del juego
    while (!gGameOver) {
        // Procesa el input del teclado.
        if (IsWPressed()) ChangeDirection(DIR_UP);
        if (IsSPressed()) ChangeDirection(DIR_DOWN);
        if (IsAPressed()) ChangeDirection(DIR_LEFT);
        if (IsDPressed()) ChangeDirection(DIR_RIGHT);
        // Actualiza la posición de la serpiente.
        UpdateSnake();
        // Comprueba colisión con el borde o consigo misma.
        if (CheckWallCollision(WIDTH, HEIGHT) || CheckSelfCollision())
            gGameOver = true;
        // Comer fruta y puntuación.
        if (gHeadX == gFruit.x && gHeadY == gFruit.y) {
            gScore += 15;
            GrowSnake();
            SpawnFruit();
        }
        // Suma puntos cada frame por la longitud de la cola.
        gScore += (int)gTail.size();
        // Dibuja el estado actual.
        DrawBoard(gHeadX, gHeadY, gTail, gFruit, gScore);

        std::this_thread::sleep_for(std::chrono::milliseconds(FRAME_RATE));
    }

    std::cout << "Game Over! Final score: " << gScore << std::endl;
    return 0;
}
