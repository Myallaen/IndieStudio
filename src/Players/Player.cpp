//
// Player.cpp for Player in /home/myallaen/Work/epitech/CPP/cpp_indie_studio
//
// Made by myallaen
// Login   <myallaen@epitech.eu>
//
// Started on  Wed Jun 14 22:50:27 2017 myallaen
// Last update Sun Jun 18 13:17:36 2017 myallaen
//

#include "Players/Player.hpp"

IS::Player::Player(const unsigned int& id):APlayer(id, IS::IPlayer::PLAYER),_controller(id)
{}

IS::Player::~Player()
{
  //std::cout << "destruct Player(" << _id << ")" << std::endl;
}

/*
**	GETTERS
*/

const IS::Controller& IS::Player::getController() const
{
  return _controller;
}
