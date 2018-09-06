//
// APlayer.cpp for APlayer in /home/myallaen/Work/epitech/CPP/cpp_indie_studio
//
// Made by myallaen
// Login   <myallaen@epitech.eu>
//
// Started on  Sat Jun 17 19:21:23 2017 myallaen
// Last update Sun Jun 18 16:46:54 2017 myallaen
//

#include "Players/APlayer.hpp"

IS::APlayer::APlayer(const unsigned int& id, const IS::IPlayer::Type& type):_id(id),_type(type),_invulnerability()
{
  _life = 3;
  _bomb_power = 1;
  _blocs = 1;
  _max_bombs = 1;
  switch (_id)
    {
    case 1:
      _dir = DIR_DOWN;
      _x = 1;
      _y = 1;
      _overlay_x = 0;
      _overlay_y = 0;
      break;
    case 2:
      _dir = DIR_UP;
      _x = 1;
      _y = 15;
      _overlay_x = 0;
      _overlay_y = 540;
      break;
    case 3:
      _dir = DIR_DOWN;
      _x = 15;
      _y = 1;
      _overlay_x = 1504;
      _overlay_y = 0;
      break;
    case 4:
      _dir = DIR_UP;
      _x = 15;
      _y = 15;
      _overlay_x = 1504;
      _overlay_y = 540;
      break;
    default:
      throw new std::invalid_argument("Wrong player id (4 max)");
    }
}

IS::APlayer::~APlayer()
{}

/*
**	GETTERS
*/

const std::vector<IS::Bomb>& IS::APlayer::getBombs() const
{
  return _bombs;
}

const IS::IPlayer::Type& IS::APlayer::getType() const
{
  return _type;
}

const unsigned int& IS::APlayer::getX() const
{
  return _x;
}

const unsigned int& IS::APlayer::getY() const
{
  return _y;
}

const unsigned int& IS::APlayer::getDir() const
{
  return _dir;
}

const unsigned int& IS::APlayer::getLife() const
{
  return _life;
}

const unsigned int& IS::APlayer::getBombPower() const
{
  return _bomb_power;
}

const unsigned int& IS::APlayer::getBlocs() const
{
  return _blocs;
}

const unsigned int& IS::APlayer::getMaxBombs() const
{
  return _max_bombs;
}

const unsigned int& IS::APlayer::getId() const
{
  return _id;
}


/*
**	BOOL CHECKERS
*/

bool IS::APlayer::hasBomb() const
{
  //std::cout << "APlayer::hasBombs()" <<  std::endl;
  if (_max_bombs > _bombs.size())
    return true;
  return false;
}

bool IS::APlayer::hasBloc() const
{
  //std::cout << "APlayer::hasBloc()" << std::endl;
  if (_blocs)
    return true;
  return false;
}

bool IS::APlayer::isLiving() const
{
  if (_life)
    return true;
  return false;
}

/*
**	ACTION METHODS
*/

void IS::APlayer::move(const int& dir)
{
  //std::cout << "APlayer::moveUp(int " << dir << ")" << std::endl;
  _char_state = 0;
  switch (dir)
    {
    case DIR_UP:
      if (_dir != DIR_UP)
	_dir = DIR_UP;
      _y -= 1;
      break;
    case DIR_DOWN:
      if (_dir != DIR_DOWN)
	_dir = DIR_DOWN;
      _y += 1;
      break;
    case DIR_LEFT:
      if (_dir != DIR_LEFT)
	_dir = DIR_LEFT;
      _x -= 1;
      break;
    case DIR_RIGHT:
      if (_dir != DIR_RIGHT)
	_dir = DIR_RIGHT;
      _x += 1;
      break;
    default:
      break;
    }
}

void IS::APlayer::addBomb(const unsigned int& x, const unsigned int& y)
{
  //std::cout << "APlayer::addBomb(Uint " << x << ", Uint " << y << ")" << std::endl;
  _bombs.push_back(IS::Bomb(x, y, _bomb_power));
}

void IS::APlayer::addBloc()
{
  //std::cout << "APlayer::addBloc()" << std::endl;
  if (_blocs)
    --_blocs;
}

void IS::APlayer::takeDamage()
{
  //std::cout << "APlayer::takeDamage()" << std::endl;
  if (_invulnerability.getElapsedTime() > sf::seconds(3))
    {
      _invulnerability.restart();
      _life -= 1;
      //std::cout << "APlayer[" << _id << "]::takeDamage() = " << _life << std::endl;
    }
}

void IS::APlayer::incrementMaxBombs()
{
  if (_max_bombs < 9)
    ++_max_bombs;
}

void IS::APlayer::incrementPower()
{
  if (_bomb_power < 10)
    ++_bomb_power;
}

void IS::APlayer::incrementBlocs()
{
  if (!(_blocs))
    _blocs = 1;
}

void IS::APlayer::incrementLife()
{
  ++_life;
}


/*
**	GRAPHIC METHODS
*/

void IS::APlayer::loadChar(const int& player, const int& skin, sf::Font& font)
{
  //std::cout << "APlayer::loadChar(int " << player << ", int " << skin << ", sf::Font font)" << std::endl;

  std::string char_file = "assets/sprites/char_" + std::to_string(player) + "_" + std::to_string(skin) + ".png";
  _char_tex.loadFromFile(char_file);
  _char_sprite.setTexture(_char_tex);
  _char_sprite.setTextureRect(sf::IntRect(0, 0, 64, 128));
  _char_state = 0;

  _name = "Player " + std::to_string(player);
  _texts["_player_name"] = new sf::Text(_name, font, 30);
  _texts["_player_life"] = new sf::Text("", font, 30);
  _texts["_player_blocs"] = new sf::Text("", font, 30);
  _texts["_player_bombs"] = new sf::Text("", font, 30);
  _texts["_player_name"]->setPosition((_overlay_x + 100), (_overlay_y + 100));
  _texts["_player_life"]->setPosition((_overlay_x + 100), (_overlay_y + 130));
  _texts["_player_blocs"]->setPosition((_overlay_x + 100), (_overlay_y + 160));
  _texts["_player_bombs"]->setPosition((_overlay_x + 100), (_overlay_y + 190));
}

void IS::APlayer::draw(sf::RenderWindow& win)
{
  //std::cout << "APlayer::draw(_win)" << std::endl;

  _char_sprite.setTextureRect(sf::IntRect(((_char_state / 3)) * 64, (_dir) * 128, 64, 128));
  _char_sprite.setPosition((64 * _x) + 416, (64 * _y) - 64);
  win.draw(_char_sprite);
  _char_state = (_char_state + 1) % 24;
}

void IS::APlayer::drawOverlay(sf::RenderWindow& win)
{
  //std::cout << "APlayer::drawOverlay(_win)" << std::endl;
  std::string _player_life = "LIFE  :     " + std::to_string(_life);
  std::string _player_blocs = "BLOCS : " + std::to_string(_blocs) + " / 1";
  std::string _player_bombs = "BOMBS : " + std::to_string(_bombs.size()) + " / " + std::to_string(_max_bombs);

  _texts["_player_life"]->setString(_player_life);
  _texts["_player_blocs"]->setString(_player_blocs);
  _texts["_player_bombs"]->setString(_player_bombs);

  win.draw(*(_texts["_player_name"]));
  win.draw(*(_texts["_player_life"]));
  win.draw(*(_texts["_player_blocs"]));
  win.draw(*(_texts["_player_bombs"]));
}
