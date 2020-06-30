#ifndef BULLET_CLASS_HPP
# define BULLET_CLASS_HPP

#include "retro.game.hpp"

class Bullet : public Object {

  public:
    Bullet(void);
    Bullet(int x, int y);
    Bullet(int x, int y, int shape);
    Bullet(Bullet &other);
    virtual ~Bullet(void);
    Bullet& operator=(Bullet const &other);

    clock_t get_time() const;
    void    set_time(clock_t time);

  private:
    clock_t _time;
};

#endif
