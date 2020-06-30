#include "retro.game.hpp"

Player::Player() : Unit(), _ammoMax(5), _ammo(5) {};

Player::Player(int x, int y) : \
    Unit(x, y), _ammoMax(5), _ammo(5) {};

Player::Player(int x, int y, int shape) : \
    Unit(x, y, shape), _ammoMax(5), _ammo(5) {};

Player::Player(int x, int y, int shape, int hp) : \
    Unit(x, y, shape, hp), _ammoMax(5), _ammo(5) {};

Player::Player(int x, int y, int shape, int hp, int ammo) : \
    Unit(x, y, shape, hp), _ammoMax(ammo), _ammo(ammo) {};

Player::Player(Player &other) {
  this->_ammo = other.get_ammo();
  this->_ammoMax = other.get_ammoMax();
  this->set_xy(other.get_x(), other.get_y());
  this->set_shape(other.get_shape());
  other.is_alive() ? this->make_alive() : this->make_dead();
  this->set_hp(other.get_hp());
};

Player::~Player() {};

Player& Player::operator=(Player const &other) {
  this->_ammo = other.get_ammo();
  this->_ammoMax = other.get_ammoMax();
  this->set_xy(other.get_x(), other.get_y());
  this->set_shape(other.get_shape());
  other.is_alive() ? this->make_alive() : this->make_dead();
  this->set_hp(other.get_hp());
  return *this;
};

int   Player::have_ammo() {
  if (this->_ammo > 0)
    return 1;
  return 0;
};

void  Player::shoot() {
  if (this->have_ammo())
    this->_ammo -= 1;
};

void  Player::reload() {
  this->_ammo = this->_ammoMax;
};

int   Player::get_ammo() const {
  return this->_ammo;
};

int   Player::get_ammoMax() const {
  return this->_ammoMax;
};

void  Player::set_ammoMax(int newMax) {
  this->_ammoMax = newMax;
};
