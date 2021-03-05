#include "ant.h"
#include <iostream>

Ant::Ant(void) {
  position_.x = 0;
  position_.y = 0;
  orientation_ = EAST;
}

Ant::Ant(const int& rows, const int& cols) {
  position_.x = rows/2;
  position_.y = cols/2;
  orientation_ = EAST;
}

Position Ant::get_position() {
  return position_;
}

int Ant::get_orientation(void) {
  return orientation_;
}

void Ant::change_orientation(const int& current_cell_colour) {
  switch (orientation_) {
    case NORTH:
      if(current_cell_colour == 0) {
        orientation_ = WEST;
      } else {
        orientation_ = EAST;
      }
      break;
    case EAST:
      if(current_cell_colour == 0) {
        orientation_ = NORTH;
      } else {
        orientation_ = SOUTH;
      } 
      break;
    case SOUTH:
      if(current_cell_colour == 0) {
        orientation_ = EAST;
      } else {
        orientation_ = WEST;
      }   
      break;
    case WEST:
      if(current_cell_colour == 0) {
        orientation_ = SOUTH;
      } else {
        orientation_ = NORTH;
      } 
      break;  
  }
}

void Ant::move_fordward(){//World& world) {
  switch (orientation_) {
    case NORTH:
      position_.x += -1;
      break;
    case EAST:
      position_.y += 1;
      break;
    case SOUTH:
      position_.x += 1;
      break;
    case WEST:
      position_.y += -1;
      break;  
  }

  // if((position_.x < 0) || (position_.x >= world.get_rows())) {
  //     if(position_.x < 0) {
  //       position_.x = world.get_rows()-1;
  //     } else {
  //       position_.x = 0;
  //     }
  //   } else if((position_.y < 0) || (position_.y >= world.get_cols())) {
  //     if(position_.y < 0) {
  //       position_.y = world.get_cols()-1;
  //     } else {
  //       position_.y = 0;
  //     }
  //   }
}

void Ant::set_position_x(const int& x) {
  position_.x = x;
}

void Ant::set_position_y(const int& y){
  position_.y = y;
}

void Ant::set_orientation(const int& orientation) {
  orientation_ = orientation;
}

void Ant::print_ant(void) {
  switch (orientation_) {
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
}