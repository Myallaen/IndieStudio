//
// AI.cpp for AI in /home/myallaen/Work/epitech/CPP/cpp_indie_studio
//
// Made by myallaen
// Login   <myallaen@epitech.eu>
//
// Started on  Sat Jun 17 23:51:59 2017 myallaen
// Last update Sun Jun 18 13:17:04 2017 myallaen
//

#include "Players/AI.hpp"

IS::AI::AI(const unsigned int& id):APlayer(id, IS::IPlayer::AI)
{}

IS::AI::~AI()
{}

IS::AI::Action IS::AI::getAction()
{
  return IS::AI::SLEEP;
}
