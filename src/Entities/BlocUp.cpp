//
// BlocUp.cpp for BlocUp in /home/myallaen/Work/epitech/CPP/cpp_indie_studio
//
// Made by myallaen
// Login   <myallaen@epitech.eu>
//
// Started on  Sun Jun 18 15:02:12 2017 myallaen
// Last update Sun Jun 18 16:48:28 2017 myallaen
//

#include "Entities/BlocUp.hpp"

IS::BlocUp::BlocUp(const unsigned int& x, const unsigned int& y):AEntity(IS::IEntity::BLOC_UP, x, y)
{
  _tex.loadFromFile("assets/sprites/entities.png");
  _sprite.setTexture(_tex);
  _sprite.setTextureRect(sf::IntRect(64, 64, 64, 64));
}

IS::BlocUp::~BlocUp()
{}

void IS::BlocUp::pickedUp(IS::IPlayer* player)
{
  if (_type != USED)
    player->incrementBlocs();
  _type = USED;
}
