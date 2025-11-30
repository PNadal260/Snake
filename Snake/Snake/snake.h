#pragma once
#include <vector>
#include "position.h"

// Enum que representa la dirección actual de desplazamiento de la serpiente.
enum Direction {
    DIR_NONE,
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT
};
// Variables globales compartidas entre módulos para representar la serpiente.
extern int gHeadX;                      // Coordenada X de la cabeza
extern int gHeadY;                      // Coordenada Y de la cabeza
extern std::vector<Position> gTail;     // Segmentos del cuerpo de la serpiente
extern Direction gDir;                  // Dirección actual

// Funciones de control de la serpiente
void InitSnake(int width, int height);   // Inicializa la serpiente en el centro del tablero
void ChangeDirection(Direction newDir);  // Cambia la dirección de la serpiente
void UpdateSnake();                      // Actualiza la posición de la cabeza y la cola
void GrowSnake();                        // Añade un nuevo segmento al cuerpo
bool CheckSelfCollision();               // Verifica si la cabeza colisiona con la cola
bool CheckWallCollision(int width, int height); // Verifica si la cabeza colisiona
