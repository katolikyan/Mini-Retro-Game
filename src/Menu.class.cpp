#include "retro.game.hpp"

Menu::Menu() : Window() {
};

Menu::Menu(int height, int width, int startY, int startX) : \
    Window(height, width, startY, startX) {
};

Menu::Menu(Menu &other) {
  this->_xMax = other._xMax;
  this->_yMax = other._yMax;
  this->_startX = other._startX;
  this->_startY = other._startY;
  this->_width = other._width;
  this->_height = other._height;
  if (this->_win)
    this->_win = dupwin(other._win);
};

Menu::~Menu() {
  if (this->_win)
    delwin(this->_win);
};

Menu& Menu::operator=(Menu const &other) {
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

int  Menu::pop_menu() {
  Window _optionMessage;
  int key;
  int highlight = 0;
  std::string choises[4] = {MENU_OPTION_1, MENU_OPTION_2, MENU_OPTION_3, MENU_OPTION_4};
  std::string messages[4] = {MENU_MESSAGE_1, MENU_MESSAGE_2, MENU_MESSAGE_3, MENU_MESSAGE_4};

  this->_win = newwin(this->_height, this->_width, this->_startY, this->_startX);
  keypad(this->_win, TRUE);
  refresh();

  while(1) {
    for (int i = 0; i < 4; i++) {
      if (i == highlight)
        wattron(this->_win, A_REVERSE);
      mvwprintw(this->_win, i + 1, 1, choises[i].c_str());
      wattroff(this->_win, A_REVERSE);
    }
    box(this->_win, 0, 0);
    wrefresh(this->_win);

    key = wgetch(this->_win);
    switch (key) {
      case 10:
      case 13:
        // Sound = Sound of choosing an option
        // system("afplay ./assets/Choose.wav &");
        if (highlight == 0) {
          delwin(this->_win);
          return 1;
        }
        else if (highlight == 3) {
          _optionMessage.pop_up(messages[highlight]);
          return 0;
        }
        else 
          _optionMessage.pop_up(messages[highlight]);
        break;
      case KEY_DOWN:
      case 's':
        // Sound = Sound of moving cursor
        // system("afplay ./assets/Select.wav &");
        if (highlight < 3)
          highlight += 1;
        break;
      case KEY_UP:
      case 'w':
        // Sound = Sound of moving cursor
        // system("afplay ./assets/Select.wav &");
        if (highlight > 0)
          highlight -= 1;
        break;
      default:
        break;
    }
  }  
};
