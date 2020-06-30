#include "retro.game.hpp"

Level::Level() {
  this->_crntLevel = 1;
  this->_level_setup(this->_crntLevel);
};

Level::Level(Level &other) {
  this->_crntLevel = other.get_level();
  this->_enemyCount = other.get_enemyCount();
  this->_enemySpeed = other.get_enemySpeed();
  this->_enemyShape = other.get_enemyShape();
  this->_enemyBulletFreq = other.get_enemyBulletFreq();
};

Level::~Level() {};

Level& Level::operator=(Level const &other) {
  this->_crntLevel = other.get_level();
  this->_enemyCount = other.get_enemyCount();
  this->_enemySpeed = other.get_enemySpeed();
  this->_enemyShape = other.get_enemyShape();
  this->_enemyBulletFreq = other.get_enemyBulletFreq();
  return *this;
};

int   Level::get_level() const {
  return this->_crntLevel;
};

int   Level::get_enemyCount() const {
  return this->_enemyCount;
};

int   Level::get_enemySpeed() const {
  return this->_enemySpeed;
};

int   Level::get_enemyShape() const {
  return this->_enemyShape;
};

int   Level::get_enemyBulletFreq() const {
  return this->_enemyBulletFreq;
};

void  Level::next_level() {
  this->_crntLevel += 1;
  this->_level_setup(this->_crntLevel);
};

void  Level::level_checkout(int level) {
  this->_level_setup(level);
};

void  Level::_level_setup(int level) {
  switch (level) {
    case 1: // First level;
      this->_enemyCount = 10;
      this->_enemySpeed = 99995;
      this->_enemyShape = 'U';
      this->_enemyBulletFreq = 999990;
      break;
    case 2: // 42 evemies
      this->_enemyCount = 42;
      this->_enemySpeed = 99980;
      this->_enemyShape = 'V';
      this->_enemyBulletFreq = 999990;
      break;
    case 3: // fast bombardiring
      this->_enemyCount = 15;
      this->_enemySpeed = 99990;
      this->_enemyShape = 'M';
      this->_enemyBulletFreq = 999900;
      break;
    case 4: // 42 swarm
      this->_enemyCount = 42;
      this->_enemySpeed = 95000;
      this->_enemyShape = 'W';
      this->_enemyBulletFreq = 999995;
      break;
    case 5: // invisible
      this->_enemyCount = 15;
      this->_enemySpeed = 99900;
      this->_enemyShape = ' ';
      this->_enemyBulletFreq = 999980;
      break;
    default:
      break;
  }
};
