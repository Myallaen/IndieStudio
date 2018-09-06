//
// Bomb.cpp for Bomb in /home/myallaen/Work/epitech/CPP/cpp_indie_studio
//
// Made by myallaen
// Login   <myallaen@epitech.eu>
//
// Started on  Fri Jun 16 14:42:05 2017 myallaen
// Last update Sun Jun 18 17:13:14 2017 myallaen
//

#include "Players/Bomb.hpp"

IS::Bomb::Bomb(const unsigned int& x, const unsigned int& y, const unsigned int& power):_x(x),_y(y),_power(power),_val(0),_time()
{}

IS::Bomb::~Bomb()
{}

const unsigned int& IS::Bomb::getX() const
{
  return _x;
}

const unsigned int& IS::Bomb::getY() const
{
  return _y;
}

const unsigned int& IS::Bomb::getPower() const
{
  return _power;
}

int IS::Bomb::getBombVal()
{
  //std::cout << "Bomb::getBombVal()" << std::endl;

  sf::Time lapse = sf::seconds(0.225f);

  while (_time.getElapsedTime() > ((_val + 1) * lapse))
    _val += 1.f;
  return ((int)(_val));
}
