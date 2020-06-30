#ifndef PLAYER_CLASS_HPP
# define PLAYER_CLASS_HPP

#include "retro.game.hpp"

class Player : public Unit {

  public:
    Player(void);
    Player(int x, int y);
    Player(int x, int y, int shape);
    Player(int x, int y, int shape, int hp);
    Player(int x, int y, int shape, int hp, int ammo);
    Player(Player &other);
    ~Player(void) override;
    Player& operator=(Player const &other);

    int   get_ammo(void) const;
    int   get_ammoMax(void) const;
    void  set_ammoMax(int newMax);

    void  shoot(void) override;
    void  reload(void);
    int   have_ammo(void);


  private:
    int _ammoMax;
    int _ammo;
};

#endif
