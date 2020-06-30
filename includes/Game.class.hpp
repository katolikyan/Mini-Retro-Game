#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP

#include "retro.game.hpp"

using namespace std;

class Game {
  public:
    Game(void);
    Game(int x, int y);
    Game(Game &other);
    virtual ~Game(void);
    Game& operator=(Game const &other);

    void	spawn_player(void);
    void	draw_enemies(void);
    void	move_enemies(void);
    void  shoot_enemies(void);
    int   run(void);
    void  draw_info(void);
    void  input(void);
    void  init_player_bullet(void);
    void  init_enemy_bullet(int x, int y);
    int   check_end_game();
    void  update_bullets(void);
    void  check_collisions(void);

  private:
    // functions;
    void  _setup_curses(void);
    void  _destroy_enemies(void);
    void  _build_enemies(void);

    // properties;
    int _mapX;
    int _mapY;
    int _gameOver;
    int _enemyCount;
    int _enemyCurrent;

    Level   _level;
    Player  _player;
    Enemy   *_enemies;
    vector<Bullet*> *_playerBullets;
    vector<Bullet*> *_enemyBullets;
};
  
#endif
