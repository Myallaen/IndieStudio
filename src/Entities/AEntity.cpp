//
// AEntity.cpp for AEntity in /home/myallaen/Work/epitech/CPP/cpp_indie_studio
//
// Made by myallaen
// Login   <myallaen@epitech.eu>
//
// Started on  Sun Jun 18 12:14:17 2017 myallaen
// Last update Sun Jun 18 16:55:02 2017 myallaen
//

#include "Entities/AEntity.hpp"

IS::AEntity::AEntity(const IS::IEntity::Type& type, const unsigned int& x, const unsigned int& y):_type(type),_x(x),_y(y),_invulnerability()
{
}

IS::AEntity::~AEntity()
{}

const IS::IEntity::Type& IS::AEntity::getType() const
{
  return _type;
}

const unsigned int& IS::AEntity::getX() const
{
  return _x;
}

const unsigned int& IS::AEntity::getY() const
{
  return _y;
}

bool IS::AEntity::isUsed() const
{
  if (_type == IS::IEntity::USED)
    return true;
  return false;
}

void IS::AEntity::takeDamage()
{
  sf::Time _time = sf::seconds(3);
  if (_invulnerability.getElapsedTime() > _time)
    _type = IS::IEntity::USED;
}

void IS::AEntity::draw(sf::RenderWindow& win)
{
  _sprite.setPosition((64 * _x) + 416,(64 * _y));
  win.draw(_sprite);
}
