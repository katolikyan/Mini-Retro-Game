#ifndef LEVEL_CLASS_HPP
# define LEVEL_CLASS_HPP

#include "retro.game.hpp"

class Level {

  public:
    Level(void);
    Level(Level &other);
    ~Level(void);
    Level& operator=(Level const &other);

    int   get_level(void) const;
    int   get_enemyCount(void) const; 
    int   get_enemySpeed(void) const;
    int   get_enemyShape(void) const;
    int   get_enemyBulletFreq(void) const;
    std::string get_message(void) const;
    void  set_level(int level);

    void  next_level(void);
    void  level_checkout(int level);

  private:
    void  _level_setup(int level);

    int   _crntLevel;
    int   _enemyCount;
    int   _enemySpeed;
    int   _enemyShape;
    int   _enemyBulletFreq;
    std::string _message;
};

#endif
