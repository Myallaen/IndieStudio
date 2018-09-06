//
// RandomEntity.cpp for indieStudio in /home/myallaen/Work/epitech/CPP/cpp_indie_studio/src
//
// Made by myallaen
// Login   <myallaen@epitech.net>
//
// Started on  Sun Jun 18 14:58:52 2017 myallaen
// Last update Sun Jun 18 17:06:35 2017 myallaen
//

#include "Entities/BombUp.hpp"
#include "Entities/PowerUp.hpp"
#include "Entities/BlocUp.hpp"
#include "Entities/LifeUp.hpp"

IS::IEntity* IS::newRandomEntity(const unsigned int& x, const unsigned int& y)
{
  IS::IEntity* entity = NULL;
  int i = (rand() % 10);

  switch (i)
    {
    case 0:
      entity = new IS::LifeUp(x, y);
      break;
    case 1:
    case 2:
      entity = new IS::BlocUp(x, y);
      break;
    case 3:
    case 4:
    case 5:
      entity = new IS::BombUp(x, y);
      break;
    default:
      entity = new IS::PowerUp(x, y);
      break;
    }
  return entity;
}
