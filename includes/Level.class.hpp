#ifndef LEVEL_CLASS_HPP
# define LEVEL_CLASS_HPP

#include "retro.game.hpp"

class Level {

  public:
    Level(void);
    Level(Level &other);
    ~Level(void);
    Level& operator=(Level const &other);

    int   get_level() const;
    int   get_enemyCount() const; 
    int   get_enemySpeed() const;
    int   get_enemyShape() const;
    int   get_enemyBulletFreq() const;

    void  next_level();
    void  level_checkout(int level);

  private:
    void  _level_setup(int level);

    int   _crntLevel;
    int   _enemyCount;
    int   _enemySpeed;
    int   _enemyShape;
    int   _enemyBulletFreq;
};

#endif
