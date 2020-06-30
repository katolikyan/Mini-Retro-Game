#include "retro.game.hpp"

Unit::Unit() : Object(), _hp(1) {};

Unit::Unit(int x, int y) : Object(x, y), _hp(1) {};

Unit::Unit(int x, int y, int shape) : Object(x, y, shape), _hp(1) {};

Unit::Unit(int x, int y, int shape, int hp) : Object(x, y, shape), _hp(hp) {};

Unit::Unit(Unit &other) {
  this->_hp = other.get_hp();
  this->set_xy(other.get_x(), other.get_y());
  this->set_shape(other.get_shape());
  other.is_alive() ? this->make_alive() : this->make_dead();
};

Unit::~Unit() {};

Unit& Unit::operator=(Unit const &other) {
  this->_hp = other.get_hp();
  this->set_xy(other.get_x(), other.get_y());
  this->set_shape(other.get_shape());
  other.is_alive() ? this->make_alive() : this->make_dead();
  return *this;
};

void	Unit::set_hp(int hp) {
  this->_hp = hp;
};


int	Unit::get_hp() const {
  return this->_hp;
};

void Unit::lose_hp(int damage) {
  this->_hp -= damage;
};

void Unit::shoot() {};
