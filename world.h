#ifndef World_H_
#define World_H_

#include <iostream>
#include <vector>
#include <assert.h>
#include "ant.h"

class World {
 public:
  World(const int& rows, const int& cols);
  int get_cell_colour(const int& i, const int& j);
  void change_cell_colour(const int& i, const int& j);
 private:
  std::vector<std::vector<int>> world_;
};




#endif //World_H_