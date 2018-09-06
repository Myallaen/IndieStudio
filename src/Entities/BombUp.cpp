//
// BombUp.cpp for BombUp in /home/myallaen/Work/epitech/CPP/cpp_indie_studio
//
// Made by myallaen
// Login   <myallaen@epitech.eu>
//
// Started on  Sun Jun 18 15:02:12 2017 myallaen
// Last update Sun Jun 18 16:47:49 2017 myallaen
//

#include "Entities/BombUp.hpp"

IS::BombUp::BombUp(const unsigned int& x, const unsigned int& y):AEntity(IS::IEntity::BOMB_UP, x, y)
{
  _tex.loadFromFile("assets/sprites/entities.png");
  _sprite.setTexture(_tex);
  _sprite.setTextureRect(sf::IntRect(0, 64, 64, 64));
}

IS::BombUp::~BombUp()
{}

void IS::BombUp::pickedUp(IS::IPlayer* player)
{
  if (_type != USED)
    player->incrementMaxBombs();
  _type = USED;
}
