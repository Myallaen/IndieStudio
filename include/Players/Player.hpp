//
// Player.hpp for Player in /home/myallaen/Work/epitech/CPP/cpp_indie_studio
//
// Made by myallaen
// Login   <myallaen@epitech.eu>
//
// Started on  Wed Jun 14 22:50:27 2017 myallaen
// Last update Sun Jun 18 13:10:38 2017 myallaen
//

#ifndef _PLAYER_HPP_
# define _PLAYER_HPP_

# include <iostream>
# include <string>

# include "Players/APlayer.hpp"
# include "Players/Controller.hpp"

namespace	IS
{
  class			Player: public IS::APlayer
  {
  public:
    IS::Controller	_controller;

  public:			// tor
				Player(const unsigned int&);
    virtual			~Player();

  public:			// getters
    const IS::Controller&	getController() const;
  };			// Player
};

#endif /* !_PLAYER_HPP_ */
