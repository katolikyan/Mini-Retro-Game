#ifndef MENU_CLASS_HPP
# define MENU_CLASS_HPP

class Menu : Window {

  public:
    Menu();
    Menu(int height, int width, int startY, int startX);
    Menu(Menu &other);
    ~Menu();
    Menu& operator=(Menu const &other);

    int pop_menu(void);

  private:

};

#endif
