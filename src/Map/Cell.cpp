//
// Cell.cpp for Cell in /home/myallaen/Work/epitech/CPP/cpp_indie_studio
//
// Made by myallaen
// Login   <myallaen@epitech.eu>
//
// Started on  Fri Jun 16 21:02:47 2017 myallaen
// Last update Sun Jun 18 21:02:39 2017 myallaen
//

#include "Map/Cell.hpp"

IS::Cell::Cell():_type(UNDEFINED)
{}

IS::Cell::Cell(const int& val, const unsigned int& x, const unsigned int& y):_x(x),_y(y)
{
  setVal(val);
}

IS::Cell::~Cell()
{}

const IS::Cell::Type& IS::Cell::getType() const
{
  //std::cout << "Cell::getType()" << std::endl;

  return _type;
}

const int& IS::Cell::getVal() const
{
  //std::cout << "Cell::getVal()" << std::endl;
  return _val;
}

const unsigned int& IS::Cell::getX() const
{
  //std::cout << "Cell::getX()" << std::endl;
  return _x;
}

const unsigned int& IS::Cell::getY() const
{
  //std::cout << "Cell::getY()" << std::endl;
  return _y;
}

bool IS::Cell::isDrawable()
{
  //std::cout << "Cell::isDrawable()" << std::endl;

  switch (_type)
    {
    case IS::Cell::BREAKABLE_OBSTACLE:
    case IS::Cell::OBSTACLE:
    case IS::Cell::BOMB:
    case IS::Cell::EXPLODING_BOMB:
    case IS::Cell::EXPLOSION:
      return true;
    default :
      return false;
    }
}

bool IS::Cell::isWalkable()
{
  //std::cout << "Cell::isWalkable()" << std::endl;
  switch (_type)
    {
    case IS::Cell::PATH:
    case IS::Cell::EXPLOSION:
      return true;
    default :
      return false;
    }
}

bool IS::Cell::isWall()
{
  //std::cout << "Cell::isWall()" << std::endl;
  switch (_type)
    {
    case IS::Cell::UNDEFINED:
    case IS::Cell::BREAKABLE_OBSTACLE:
    case IS::Cell::OBSTACLE:
    case IS::Cell::INVISIBLE_OBSTACLE:
      return true;
    default :
      return false;
    }
}

bool IS::Cell::isBreakableWall()
{
  //std::cout << "Cell::isBreakableWall()" << std::endl;

  switch (_type)
    {
    case IS::Cell::BREAKABLE_OBSTACLE:
      return true;
    default :
      return false;
    }
}

bool IS::Cell::isBomb()
{
  //std::cout << "Cell::isBomb()" << std::endl;

  switch (_type)
    {
    case IS::Cell::BOMB:
    case IS::Cell::EXPLODING_BOMB:
      return true;
    default :
      return false;
    }
}

bool IS::Cell::isBombExploding()
{
  //std::cout << "Cell::isBombExploding()" << std::endl;

  switch (_type)
    {
    case IS::Cell::EXPLODING_BOMB:
      return true;
    default :
      return false;
    }
}

bool IS::Cell::isExplosion()
{
  //std::cout << "Cell::isExplosion()" << std::endl;

  switch (_type)
    {
    case IS::Cell::EXPLOSION:
      return true;
    default :
      return false;
    }
}

void IS::Cell::setVal(const int& val)
{
  //std::cout << "Cell::setVal(" << val << ")" << std::endl;

  _megumin_counter = 0;
  _val = val;
  _type = IS::Cell::UNDEFINED;
  if (_val >= -1 && _val <= 1)
    _type = IS::Cell::PATH;
  if (_val == 2 || _val == 3)
    _type = IS::Cell::BREAKABLE_OBSTACLE;
  if (_val == 4 || _val == 5)
    _type = IS::Cell::OBSTACLE;
  if (_val == 6 || _val == 7)
    _type = IS::Cell::INVISIBLE_OBSTACLE;
  if (_val >= 8 && _val <= 15)
    _type = IS::Cell::BOMB;
  if (_val >= 16 && _val <= 55 && (_val % 8) != 7)
    _type = IS::Cell::EXPLOSION;
  return;
}

void IS::Cell::incrementBomb(std::map<int,IS::IPlayer*> players)
{
  //std::cout << "Cell::incrementBomb(std::map<int,IS::IPlayer*> players)" << std::endl;

  for (unsigned int i = 0; i < 5; ++i)
    if ((players[i]) && (static_cast<IS::APlayer*>(players[i])->_bombs.size()))
      for (unsigned int j = 0; j < static_cast<IS::APlayer*>(players[i])->_bombs.size(); ++j)
	if ((static_cast<IS::APlayer*>(players[i])->_bombs[j].getX() == _x) &&
	    (static_cast<IS::APlayer*>(players[i])->_bombs[j].getY() == _y))
	  {
	    int  bomb_val = static_cast<IS::APlayer*>(players[i])->_bombs[j].getBombVal();
	    if (bomb_val > 7)
	      explodeBomb();
	    else
	      setVal(bomb_val + 8);
	  }
}

void IS::Cell::explodeBomb()
{
  //std::cout << "Cell::explodeBomb(IS::IPlayer _player, Uint " << b << ")" << std::endl;

  setVal(15);
  _type = IS::Cell::EXPLODING_BOMB;
}

void IS::Cell::incrementExplosion()
{
  //std::cout << "Cell::incrementExplosion()" << std::endl;

  if (_type != IS::Cell::EXPLOSION)
    return;
  ++_megumin_counter;
  if (_megumin_counter == 3)
    {
      setVal(_val + 8);
      if (_type == IS::Cell::UNDEFINED)
	setVal(-1);
    }
}
