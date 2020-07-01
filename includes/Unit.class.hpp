#ifndef UNIT_CLASS_HPP
# define UNIT_CLASS_HPP

#include "retro.game.hpp"

class Unit : public Object {

  public:
    Unit(void);
    Unit(int x, int y);
    Unit(int x, int y, int shape);
    Unit(int x, int y, int shape, int hp);
    Unit(Unit &other);
    virtual ~Unit(void);
    Unit& operator=(Unit const &other);

    void  set_hp(int hp);
    int   get_hp(void) const;
    void  lose_hp(int damage);
    virtual void  shoot(void);

  private:
    int   _hp;
};

#endif
