#include "retro.game.hpp"

using namespace std;

Game::Game() {
  int xMax, yMax;
  this->_setup_curses();
  getmaxyx(stdscr, yMax, xMax);
  this->_mapX = xMax;
  this->_mapY = yMax;
  this->_gameOver = 0;
  this->_build_enemies();
	this->_player = Player(this->_mapX / 2, this->_mapY - 2, 'A', 5, 5);
  this->_message = Window();
  this->_playerBullets = new vector<Bullet*>;
  this->_enemyBullets = new vector<Bullet*>;
};

Game::Game(int x, int y) : _mapX(x), _mapY(y) {
  this->_build_enemies();
  this->_gameOver = 0;
	this->_player = Player(this->_mapX / 2, this->_mapY - 2, 'A', 5, 5);
  this->_message = Window();
  this->_playerBullets = new vector<Bullet*>;
  this->_enemyBullets = new vector<Bullet*>;
};

Game::Game(Game &other) {
  this->_mapX = other._mapX;
  this->_mapY = other._mapY;
  this->_gameOver = other._gameOver;
  this->_enemyCount = other._enemyCount;
  this->_enemyCurrent = other._enemyCurrent;
  this->_level = other._level;
  this->_player = other._player;
  this->_message = other._message;
  this->_enemies = new Enemy[other._enemyCount];
  for (int i = 0; i < other._enemyCount; i++)
    this->_enemies[i] = other._enemies[i];
  this->_playerBullets = new vector<Bullet *>;
  this->_enemyBullets = new vector<Bullet *>;
};

Game::~Game() {
  this->_destroy_enemies();
};

Game& Game::operator=(Game const &other) {
  this->_mapX = other._mapX;
  this->_mapY = other._mapY;
  this->_gameOver = other._gameOver;
  this->_enemyCount = other._enemyCount;
  this->_enemyCurrent = other._enemyCurrent;
  this->_level = other._level;
  this->_player = other._player;
  this->_message = other._message;
  if (this->_enemies) 
    this->_destroy_enemies();
  this->_enemies = new Enemy[other._enemyCount];
  for (int i = 0; i < other._enemyCount; i++)
    this->_enemies[i] = other._enemies[i];
  this->_playerBullets = new vector<Bullet *>;
  this->_enemyBullets = new vector<Bullet *>;
  return *this;
};

void  Game::_build_enemies() {
  this->_enemyCount = this->_level.get_enemyCount(); // level count
  this->_enemyCurrent = this->_level.get_enemyCount(); // level count
  this->_enemies = new Enemy[this->_level.get_enemyCount()]; // level count
  for (int i = 0; i < this->_enemyCount; i++) {
    this->_enemies[i].set_xy(rand() % this->_mapX + 1, rand() % (this->_mapY - 15) + 1);
    this->_enemies[i].set_shape(this->_level.get_enemyShape()); // level shape
  }
};

void  Game::_destroy_enemies() {
  delete [] this->_enemies;

  // delete bullets;
  for (unsigned long i = 0; i < this->_playerBullets->size(); i++) {
      delete (*this->_playerBullets)[i];
      this->_playerBullets->erase(this->_playerBullets->begin() + i);
    }
  for (unsigned long i = 0; i < this->_enemyBullets->size(); i++) {
      delete (*this->_enemyBullets)[i];
      this->_enemyBullets->erase(this->_enemyBullets->begin() + i);
    }
};

void  Game::spawn_player() {
  this->_player.set_xy(this->_mapX / 2, this->_mapY - 2);
};

void  Game::draw_enemies() {
  for (int i = 0; i < this->_enemyCount; i++)
    if (this->_enemies[i].is_alive())
      this->_enemies[i].display();
};

void  Game::move_enemies() {
  int move_to;
  
  for (int i = 0; i < this->_enemyCount; i++) {
    //chance to move;
    if ((rand() % 100000) < this->_level.get_enemySpeed()) // Enemy move Frequency;
      continue;

    move_to = rand() % 5;
    if (this->_enemies[i].is_alive()) {
      this->_enemies[i].clear_shape();
      switch (move_to) {
        case 1:
          this->_enemies[i].move_up(1);
          break;
        case 2:
          this->_enemies[i].move_down(this->_mapY - 10);
          break;
        case 3:
          this->_enemies[i].move_left(1);
          break;
        case 4:
          this->_enemies[i].move_right(this->_mapX - 2);
          break;
        default:
          break;
      }
    }
  }
};

void  Game::shoot_enemies() {
  for (int i = 0; i < this->_enemyCount; i++) {
    if (this->_enemies[i].is_alive()) {
      if ((rand() % 1000000) > this->_level.get_enemyBulletFreq()) // enemy shoot Frequency.
        this->init_enemy_bullet(this->_enemies[i].get_x(), this->_enemies[i].get_y());
    }
  }
};

void  Game::init_enemy_bullet(int x, int y) {
  this->_enemyBullets->push_back(new Bullet(x, y, 'o'));
};
    
int Game::run() {
  this->_player.display();
  this->move_enemies();
  this->draw_enemies();
  this->shoot_enemies();
  this->update_bullets();
  this->check_collisions();
  this->draw_info();
  this->input();
  if (this->check_end_game())
    return 0;
  refresh();
	return 1;
};

void  Game::draw_info() {
	box(stdscr, 0, 0);
	mvprintw(0, this->_mapX / 2 - 6, "kek lol game");
  mvprintw(this->_mapY - 1, 10, "| Ammo: %d / %d |", this->_player.get_ammo(), this->_player.get_ammoMax());
  mvprintw(this->_mapY - 1, 30, "| HP: %d |", this->_player.get_hp());
  mvprintw(this->_mapY - 1, 50, "| LVL: %d |-| ENEMY COUNT: %d |", \
      this->_level.get_level(), this->_level.get_enemyCount());
};

void Game::init_player_bullet() {
  if (this->_player.get_ammo())
    this->_playerBullets->push_back(new Bullet(this->_player.get_x(), this->_player.get_y(), '!'));
}

void Game::update_bullets() {
  // player bullets;
  for (unsigned long i = 0; i < this->_playerBullets->size(); i++)
    if ((clock() - (*this->_playerBullets)[i]->get_time()) > 30000) {
      (*this->_playerBullets)[i]->clear_shape();
      (*this->_playerBullets)[i]->move_up(0);
      (*this->_playerBullets)[i]->display();
      (*this->_playerBullets)[i]->set_time(clock());
    }
  // enemies bullets;
  for (unsigned long i = 0; i < this->_enemyBullets->size(); i++)
    if ((clock() - (*this->_enemyBullets)[i]->get_time()) > 30000) {
      (*this->_enemyBullets)[i]->clear_shape();
      (*this->_enemyBullets)[i]->move_down(this->_mapY);
      (*this->_enemyBullets)[i]->display();
      (*this->_enemyBullets)[i]->set_time(clock());
    }
};

void  Game::check_collisions() {
  // players bullet collisions;
  for (unsigned long i = 0; i < this->_playerBullets->size(); i++) {
    // out of border;
    if ((*this->_playerBullets)[i]->out_of_borders(this->_mapX, this->_mapY)) {
      (*this->_playerBullets)[i]->clear_shape();
      delete (*this->_playerBullets)[i];
      this->_playerBullets->erase(this->_playerBullets->begin() + i);
      continue;
    }
    // have hit the enemy;
    for (int k = 0; k < this->_enemyCount; k++) {
      if (this->_enemies[k].is_alive() && \
          (*this->_playerBullets)[i]->have_collision( \
            this->_enemies[k].get_x(), this->_enemies[k].get_y())) {
        // erase bullet;
        (*this->_playerBullets)[i]->clear_shape();
        delete (*this->_playerBullets)[i];
        this->_playerBullets->erase(this->_playerBullets->begin() + i);
        // make dead;
        this->_enemies[k].clear_shape();
        this->_enemies[k].make_dead();
        this->_enemyCurrent -= 1;
        break;
      }
    }  
  }

  // enemy bullet collisions:
  for (unsigned long i = 0; i < this->_enemyBullets->size(); i++) {
    // out of border;
    if ((*this->_enemyBullets)[i]->out_of_borders(this->_mapX, this->_mapY - 1)) {
      (*this->_enemyBullets)[i]->clear_shape();
      delete (*this->_enemyBullets)[i];
      this->_enemyBullets->erase(this->_enemyBullets->begin() + i);
      continue;
    }
    // hit the hero;
    if ((*this->_enemyBullets)[i]->have_collision(this->_player.get_x(), this->_player.get_y())) {
      // erase bullet;
      (*this->_enemyBullets)[i]->clear_shape();
      delete (*this->_enemyBullets)[i];
      this->_enemyBullets->erase(this->_enemyBullets->begin() + i);
      // lose hp
      this->_player.lose_hp(1);
      this->spawn_player();
    }
  }
  
  // collision player with enemy:
  for (int i = 0; i < this->_enemyCount; i++) {
    if (this->_enemies[i].is_alive() && \
        this->_enemies[i].have_collision( \
          this->_player.get_x(), this->_player.get_y())) {
      this->_player.lose_hp(1);
      this->spawn_player();
    }
  }  
};

void Game::input() {
  int key = getch();

  switch(key) {
    case ((int)'w'):
    case KEY_UP:
      this->_player.clear_shape();
      this->_player.move_up(1);
      break;
    case ((int)'a'):
    case KEY_LEFT:
      this->_player.clear_shape();
      this->_player.move_left(1);
      break;
    case ((int)'s'):
    case KEY_DOWN:
      this->_player.clear_shape();
      this->_player.move_down(this->_mapY - 2);
      break;
    case ((int)'d'):
    case KEY_RIGHT:
      this->_player.clear_shape();
      this->_player.move_right(this->_mapX - 2);
      break;
    case ((int)'r'):
      this->_player.reload();
      break;
    case ((int)' '):
      this->init_player_bullet();
      this->_player.shoot();
      break;
    default:
      break;
  }
};

int  Game::check_end_game() {
  if (this->_player.get_hp() <= 0) {
    this->_gameOver = 1;
    this->_message.pop_up(MESSAGE_GAME_OVER);
    return 1;
  }
  else if (!this->_enemyCurrent) {
    // check_end_of the game:
      //if (this->_level.get_level() == 5) || level == custom one;
        //endgame call menue;
        //endgame
    // sleep for a sec or two and pop up a next menu story;
    this->_level.next_level();
    this->_message.pop_up(this->_level.get_message());
    clear();
    this->_destroy_enemies();
    this->_build_enemies();
    this->spawn_player();
    return 0;
  }
  return 0;
};

void  Game::_setup_curses() {
  srand(time(NULL)); // random seed from clock
	initscr();
  cbreak();
  noecho();
  nodelay(stdscr, TRUE);
  keypad(stdscr, TRUE); // allows to use arrows. 
  curs_set(0); // invisible cursor
};
