#include "retro.game.hpp"

using namespace std;

Window::Window() {
  int xMax, yMax;

  getmaxyx(stdscr, yMax, xMax);
  this->_xMax = xMax;
  this->_yMax = yMax;
  this->_startX = xMax / 4;
  this->_startY = yMax / 4;
  this->_width = xMax / 2;
  this->_height = yMax / 2;
};

Window::Window(int height, int width, int startY, int startX) {
  int xMax, yMax;

  getmaxyx(stdscr, yMax, xMax);
  this->_xMax = xMax;
  this->_yMax = yMax;
  this->_startX = startX;
  this->_startY = startY;
  this->_width = width;
  this->_height = height;
};

Window::Window(int height, int width, int startY, int startX, int yMax, int xMax) : \
    _height(height), _width(width), _startY(startY), _startX(startX), \
    _yMax(yMax), _xMax(xMax) {};

Window::~Window() {
  if (this->_win)
    delwin(this->_win);
};

Window::Window(Window &other) {
  this->_xMax = other._xMax;
  this->_yMax = other._yMax;
  this->_startX = other._startX;
  this->_startY = other._startY;
  this->_width = other._width;
  this->_height = other._height;
  if (this->_win)
    this->_win = dupwin(other._win);
};

Window& Window::operator=(Window const &other) {
  this->_xMax = other._xMax;
  this->_yMax = other._yMax;
  this->_startX = other._startX;
  this->_startY = other._startY;
  this->_width = other._width;
  this->_height = other._height;
  if (this->_win)
    this->_win = dupwin(other._win);
  return *this;
};

void  Window::pop_up(string text) {
  int key;

  this->_win = newwin(this->_height, this->_width, this->_startY, this->_startX);
  refresh();

  mvwprintw(this->_win, 1, 0, text.c_str());
  box(this->_win, 0, 0);
//   mvwprintw(this->_win, 2, 1, "DEBUG xMAX %d yMAX %d, H %d, W %d, StX %d, StY %d",\
//        _xMax, _yMax, _height, _width, _startX, _startY) ;
  wrefresh(this->_win);

  while(1) {
    key = wgetch(this->_win);
    if (key == 10 || key == 13) {
      delwin(this->_win);
      break;
    }
  }  
};

void  Window::resize_win(int height, int width, int startY, int startX) {
  this->_height = height;
  this->_width = width;
  this->_startY = startY;
  this->_startX = startX;
};
