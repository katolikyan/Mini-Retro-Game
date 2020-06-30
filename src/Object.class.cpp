#include "retro.game.hpp"

Object::Object() : _alive(true) {};

Object::Object(int x, int y) : _x(x), _y(y), _alive(true) {};

Object::Object(int x, int y, int shape) : _x(x), _y(y), _shape(shape), _alive(true) {};

Object::Object(Object &other) {
  this->_x = other.get_x();
  this->_y = other.get_y();
  this->_shape = other.get_shape();
  this->_alive = other.is_alive() ? 1 : 0;
};

Object::~Object() {};

Object& Object::operator=(Object const &other) {
  this->_x = other.get_x();
  this->_y = other.get_y();
  this->_shape = other.get_shape();
  this->_alive = other.is_alive() ? 1 : 0;
  return *this;
};


void	Object::set_xy(int x, int y) {
  this->_x = x;
  this->_y = y;
};

void  Object::set_shape(int shape) {
  this->_shape = shape;
}

int	Object::get_x() const {
  return this->_x;
};

int	Object::get_y() const{
  return this->_y;
};

int Object::get_shape() const{
  return this->_shape;
};

void	Object::move_left(int maxcord) {
  if (this->_x > maxcord)
    this->_x -= 1;
};

void	Object::move_right(int maxcord) {
  if (this->_x < maxcord)
    this->_x += 1;
};

void	Object::move_up(int maxcord) {
  if (this->_y > maxcord)
    this->_y -= 1;
};

void	Object::move_down(int maxcord) {
  if (this->_y < maxcord)
    this->_y += 1;
};

int		Object::have_collision(int x, int y) const {
  if (this->_x == x && this->_y == y) {
    return 1;
  }
  return 0;
};

int   Object::out_of_borders(int maxX, int maxY) const {
  if (this->_x < 1 || this->_x > maxX - 2 || \
      this->_y < 1 || this->_y > maxY - 1)
    return 1;
  return 0;
};

int		Object::is_alive() const {
  return (this->_alive ? 1 : 0);
};

void Object::display() {
  mvaddch(this->_y, this->_x, this->_shape);
};

void Object::clear_shape() {
  mvaddch(this->_y, this->_x, ' ');
};

void Object::make_dead() {
  this->_alive = false;
};

void Object::make_alive() {
  this->_alive = true;
};
