#include "world.h"
#include "ant.h"

int main(int argc, char** argv) {
  int rows, cols, steps, i;
  std::cout << "Introduzca las dimensiones del mundo\nfilas:";
  std::cin >> rows;
  std::cout << "columnas:";
  std::cin >> cols;
  std::cout << "Numero de pasos:";
  std::cin >> steps;

  World world(rows, cols);
  Ant ant(rows, cols);

  i=0;
  while (i <= steps) {
    if (i == 0) {
      std::cout << "Estado inicial" << std::endl;
    } else {
      std::cout << "Iteración numero " << i << std::endl;
    }
    world.print_world(ant);
    ant.change_orientation(world.get_cell_colour(ant.get_position().x, ant.get_position().y));
    world.change_cell_colour(ant.get_position().x, ant.get_position().y);
    ant.move_fordward();
    //comprobamos si la hromiga se ha salido del mundo
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
    std::cout << std::endl;
    i++;
  }  

  return 0;
}