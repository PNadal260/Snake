#define FRAME_RATE 150

#include <iostream>
#include <thread>
#include <chrono>
#include "board.h"
#include "keyboard.h"
#include "snake.h"

int main() {

    bool bGameOver = false;

    Snake snake(WIDTH, HEIGHT);

    // Bucle principal del juego
    while (!bGameOver) {

        // 1. Input
        if (IsWPressed()) snake.ChangeDirection(DIR_UP);
        if (IsSPressed()) snake.ChangeDirection(DIR_DOWN);
        if (IsAPressed()) snake.ChangeDirection(DIR_LEFT);
        if (IsDPressed()) snake.ChangeDirection(DIR_RIGHT);

        // 2. Actualizar lógica
        snake.Update();

        // 3. Dibujar
        DrawBoard(snake.GetHeadX(), snake.GetHeadY(), snake.GetTail());

        // Controlar velocidad del juego
        std::this_thread::sleep_for(std::chrono::milliseconds(FRAME_RATE));
    }

    return 0;
}
