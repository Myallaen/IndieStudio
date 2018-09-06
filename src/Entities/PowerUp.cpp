//
// PowerUp.cpp for PowerUp in /home/myallaen/Work/epitech/CPP/cpp_indie_studio
//
// Made by myallaen
// Login   <myallaen@epitech.eu>
//
// Started on  Sun Jun 18 15:02:12 2017 myallaen
// Last update Sun Jun 18 16:48:44 2017 myallaen
//

#include "Entities/PowerUp.hpp"

IS::PowerUp::PowerUp(const unsigned int& x, const unsigned int& y):AEntity(IS::IEntity::POWER_UP, x, y)
{
  _tex.loadFromFile("assets/sprites/entities.png");
  _sprite.setTexture(_tex);
  _sprite.setTextureRect(sf::IntRect(64, 0, 64, 64));
}

IS::PowerUp::~PowerUp()
{}

void IS::PowerUp::pickedUp(IS::IPlayer* player)
{
  if (_type != USED)
    player->incrementPower();
  _type = USED;
}
