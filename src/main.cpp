#include "retro.game.hpp"

/*
** Example of run with outside curses setup;
**
** void  setup()
** {
**   srand(time(NULL)); // random seed from clock
** 	initscr();
**   cbreak();
**   noecho();
**   nodelay(stdscr, TRUE);
**   keypad(stdscr, TRUE); // allows to use arrows. 
**   curs_set(0); // invisible cursor
** }
** 
** int	main(void) {
**   int xMax, yMax;
** 
**   setup();
**   getmaxyx(stdscr, yMax, xMax);
**   Game *game = new Game(xMax, yMax);
** 
**   while(1)
**     if (!game->run())
**     {
**       clear();
**       endwin();
**       delete game;
**       return (0);
**     }
**   return (1);
** }
*/

int	main(void) {
  Game *game = new Game();

  if (!game->run()) {
    delete game;
    return (0);
  }
  delete game;
  return (1);
}

//
//int	main(void) {
//  Game *game = new Game();
//
//  if (game->run()) {
//    delete game;
//    return 1;
//  }
//
//  delete game;
//  return 0;
//};
