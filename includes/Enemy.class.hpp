#ifndef ENEMY_CLASS_HPP
# define ENEMY_CLASS_HPP

#include "retro.game.hpp"

class Enemy : public Unit {

  public:
    Enemy(void);
    Enemy(int x, int y);
    Enemy(int x, int y, int shape);
    Enemy(int x, int y, int shape, int hp);
    Enemy(int x, int y, int shape, int hp, int ammo);
    Enemy(Enemy &other);
    ~Enemy(void) override;
    Enemy& operator=(Enemy const &other);

  private:
};

#endif
