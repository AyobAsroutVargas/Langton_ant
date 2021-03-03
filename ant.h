#ifndef Ant_H_
#define Ant_H_

struct Position {
  int x;
  int y;
};

enum Orientation { NORTH, EAST, SOUTH, WEST };

class Ant {
 public:
  Ant(void);
  Ant(const int& rows, const int& cols);
  Position get_position(void);
  int get_orientation(void);
  void change_orientation(const int& current_cell_colour);
  void move_fordward(void);
  void set_position_x(const int& x);
  void set_position_y(const int& y);
 private:
  Position position_;
  int orientation_;
};

#endif // Ant_H_