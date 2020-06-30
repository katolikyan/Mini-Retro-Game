#include "retro.game.hpp"

Enemy::Enemy(void) : Unit() {
  this->set_xy(0, 0);
};

Enemy::Enemy(int x, int y) : Unit(x, y) {};

Enemy::Enemy(int x, int y, int shape) : \
    Unit(x, y, shape) {};

Enemy::Enemy(int x, int y, int shape, int hp) : \
    Unit(x, y, shape, hp) {};

Enemy::Enemy(Enemy &other) {
  this->set_xy(other.get_x(), other.get_y());
  this->set_shape(other.get_shape());
  other.is_alive() ? this->make_alive() : this->make_dead();
  this->set_hp(other.get_hp());
};

Enemy::~Enemy(void) {};

Enemy& Enemy::operator=(Enemy const &other) {
  this->set_xy(other.get_x(), other.get_y());
  this->set_shape(other.get_shape());
  other.is_alive() ? this->make_alive() : this->make_dead();
  this->set_hp(other.get_hp());
  return *this;
};
