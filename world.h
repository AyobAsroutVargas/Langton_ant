#ifndef World_H_
#define World_H_

#include <iostream>
#include <vector>
#include <assert.h>
#include "ant.h"

enum Colour { WHITE, BLACK};


class World {
 public:
  World(const int& rows, const int& cols);
  int get_cell_colour(const int& i, const int& j);
  void change_cell_colour(const int& i, const int& j);
  void print_cell(const int& i, const int& j);
  void print_world(Ant& ant);
  int get_rows(void);
  int get_cols(void);
 private:
  std::vector<std::vector<int>> world_;
  int rows_;
  int cols_;
};




#endif //World_H_