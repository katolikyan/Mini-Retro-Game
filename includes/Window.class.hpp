#ifndef WINDOW_CLASS_HPP
# define WINDOW_CLASS_HPP

#include "retro.game.hpp"

using namespace std;

class Window {
  
  public:
    Window();
    Window(int height, int width, int startY, int startX);
    Window(int height, int width, int startY, \
        int startX, int yMax, int xMax);
    Window(Window &other);
    ~Window();
    Window& operator=(Window const &other);

    virtual void  pop_up(string text);
    void  resize_win(int height, int width, int startY, int startX);

  protected:
    int _height;
    int _width;
    int _startY;
    int _startX;
    int _yMax;
    int _xMax;
    WINDOW  *_win;
};

#endif
