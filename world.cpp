#include "world.h"

World::World(const int& rows, const int& cols) {
  assert (rows > 0 && cols > 0);

  world_.resize(rows);
  for (int i = 0; i < rows; i++) {
    world_[i].resize(cols);
  }
  // Inicializamos el tablero paraque este todo blanco
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++)
      world_[i][j] = 0;
  }
}

int World::get_cell_colour(const int& i, const int& j) {
  return world_[i][j];
}

void World::change_cell_colour(const int& i, const int& j) {
  if (world_[i][j] == 0) {
    world_[i][j] = 1;
  } else {
    world_[i][j] = 0;
  }
}
