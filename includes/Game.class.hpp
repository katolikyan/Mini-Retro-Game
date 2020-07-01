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

    int   run(void);

  private:
    void  _setup_curses(void);
    int   _run_game(void);
    void  _build_enemies(void);
    void  _destroy_enemies(void);
    void	_spawn_player(void);
    void	_draw_enemies(void);
    void  _draw_info(void);
    void  _init_player_bullet(void);
    void  _init_enemy_bullet(int x, int y);
    void  _shoot_enemies(void);
    void	_move_enemies(void);
    void  _update_bullets(void);
    void  _check_collisions(void);
    int   _check_end_game();
    int   _input(void);

    int   _mapX;
    int   _mapY;
    int   _gameOver;
    int   _enemyCount;
    int   _enemyCurrent;
    Menu    _menu;
    Window  _message;
    Level   _level;
    Player  _player;
    Enemy   *_enemies;
    vector<Bullet*> *_playerBullets;
    vector<Bullet*> *_enemyBullets;
};
  
#endif
