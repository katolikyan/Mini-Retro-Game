#include "retro.game.hpp"

Bullet::Bullet(void) : _time(std::clock()) {};

Bullet::Bullet(int x, int y) : \
    Object(x, y), _time(std::clock()) {};

Bullet::Bullet(int x, int y, int shape) : \
    Object(x, y, shape), _time(std::clock()) {};

Bullet::Bullet(Bullet &other) {
  this->_time = other.get_time();
  this->set_xy(other.get_x(), other.get_y());
  this->set_shape(other.get_shape());
  other.is_alive() ? this->make_alive() : this->make_dead();
};

Bullet::~Bullet(void) {};

Bullet& Bullet::operator=(Bullet const &other) {
  this->_time = other.get_time();
  this->set_xy(other.get_x(), other.get_y());
  this->set_shape(other.get_shape());
  other.is_alive() ? this->make_alive() : this->make_dead();
  return *this;
};

clock_t Bullet::get_time() const {
  return this->_time;
};

void    Bullet::set_time(clock_t time) {
  this->_time = time;
};
