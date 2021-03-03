#include "world.h"
#include "ant.h"

int main(int argc, char** argv) {
  int rows, cols, steps, orientation, i, cell_colour;
  std::cout << "Introduzca las dimensiones del mundo\nfilas:";
  std::cin >> rows;
  std::cout << "columnas:";
  std::cin >> cols;
  std::cout << "Numero de pasos:";
  std::cin >> steps;

  World world(rows, cols);
  Ant ant(rows, cols);

  i = 0;
  while (i <= steps) {
    if (i == 0) {
      std::cout << "Estado inicial" << std::endl;
    } else {
      std::cout << "Iteración numero " << i << std::endl;
    }
    //Imprimimos el mundo
    for (int i = 0; i < rows; i++) {
      std::cout << "\n";
      for (int j = 0; j < cols; j++) {
        if ((i == ant.get_position().x) && (j == ant.get_position().y )) {
          orientation = ant.get_orientation();
          switch (orientation) {
          case NORTH:
            std::cout << '^';
            break;
          case EAST:
            std::cout << '>';
            break;
          case SOUTH:
            std::cout << 'v';
            break;
          case WEST:
            std::cout << '<';
            break;  
          }
        } else {
          cell_colour = world.get_cell_colour(i,j);
          switch (cell_colour) {
          case 0:
            std::cout << ' ';
            break;
          case 1:
            std::cout << 'X';
            break;
          }
        }
      }
    }
    std::cout << std::endl;
    ant.change_orientation(world.get_cell_colour(ant.get_position().x, ant.get_position().y));
    world.change_cell_colour(ant.get_position().x, ant.get_position().y);
    ant.move_fordward();
    //Comprobamos que la hormiga no se haya salido de los limites del mundo
    if((ant.get_position().x < 0) || (ant.get_position().x >= rows)) {
      if(ant.get_position().x < 0) {
        ant.set_position_x(rows-1);
      } else {
        ant.set_position_x(0);
      }
    } else if((ant.get_position().y < 0) || (ant.get_position().y >= cols)) {
      if(ant.get_position().y < 0) {
        ant.set_position_y(cols-1);
      } else {
        ant.set_position_y(0);
      }
    }
    i++;
  }
  std::cout << std::endl;

  return 0;
}