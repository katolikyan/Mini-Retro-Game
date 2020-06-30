#ifndef OBJECT_CLASS_HPP
# define OBJECT_CLASS_HPP

#include "retro.game.hpp"

class Object {

  public:
    Object(void);
    Object(int x, int y);
    Object(int x, int y, int shape);
    Object(Object &other);
    virtual ~Object(void);
    Object& operator=(Object const &other);

    void set_xy(int x, int y);
    void set_shape(int shape);

    int get_x(void) const;
    int get_y(void) const;
    int get_shape(void) const;

    void move_left(int maxcord);
    void move_right(int maxcord);
    void move_up(int maxcord);
    void move_down(int maxcord);
    void display(void);
    void clear_shape(void);

    int out_of_borders(int maxX, int maxY) const;
    int have_collision(int x, int y) const;
    int is_alive(void) const;
    void make_dead(void);
    void make_alive(void);

  private:
    int _x;
    int _y;
    int _shape;
    bool _alive;
};

#endif
