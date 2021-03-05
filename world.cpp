#include "world.h"

World::World(const int& rows, const int& cols) {
  assert (rows > 0 && cols > 0);
  rows_ = rows;
  cols_ = cols;

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

int World::get_cols(void) {
  return cols_;
}

int World::get_rows(void) {
  return rows_;
}

void World::print_cell(const int& i, const int& j) {
  int cell_colour;
  cell_colour = get_cell_colour(i,j);
  switch (cell_colour) {
    case WHITE:
      std::cout << ' ';
      break;
    case BLACK:
      std::cout << 'X';
      break;
  }
}

void World::print_world(Ant& ant) {
  for (int i = 0; i < rows_; i++) {
    std::cout << "\n";
    for (int j = 0; j < cols_; j++) {
      if ((i == ant.get_position().x) && (j == ant.get_position().y )) {
        ant.print_ant();
        } else {
          print_cell(i,j);
        }
      }
    }
}
