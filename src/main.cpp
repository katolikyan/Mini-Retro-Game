#include "retro.game.hpp"

int	main(void) {
  Game *game = new Game();

  if (!game->run()) {
    delete game;
    return (0);
  }
  delete game;
  return (1);
}
