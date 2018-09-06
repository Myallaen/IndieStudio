//
// LifeUp.cpp for LifeUp in /home/myallaen/Work/epitech/CPP/cpp_indie_studio
//
// Made by myallaen
// Login   <myallaen@epitech.eu>
//
// Started on  Sun Jun 18 15:02:12 2017 myallaen
// Last update Sun Jun 18 16:48:11 2017 myallaen
//

#include "Entities/LifeUp.hpp"

IS::LifeUp::LifeUp(const unsigned int& x, const unsigned int& y):AEntity(IS::IEntity::LIFE_UP, x, y)
{
  _tex.loadFromFile("assets/sprites/entities.png");
  _sprite.setTexture(_tex);
  _sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
}

IS::LifeUp::~LifeUp()
{}

void IS::LifeUp::pickedUp(IS::IPlayer* player)
{
  if (_type != USED)
    player->incrementLife();
  _type = USED;
}
