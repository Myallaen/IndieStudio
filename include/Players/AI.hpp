//
// AI.hpp for indieStudio in /home/myallaen/Work/epitech/CPP/cpp_indie_studio
//
// Made by myallaen
// Login   <myallaen@epitech.eu>
//
// Started on  Wed Jun 14 22:50:27 2017 myallaen
// Last update Sun Jun 18 13:37:36 2017 myallaen
//

#ifndef _AI_HPP_
# define _AI_HPP_

# include <iostream>
# include <string>

# include "Players/APlayer.hpp"

namespace	IS
{
  class		        AI: public IS::APlayer
  {
  public:
    enum			Action
      {
	UNDEFINED = -1,
	MOVE_UP,
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_RIGHT,
	ACT1,
	ACT2,
	SLEEP,
      };

  public:			// tor
				AI(const unsigned int&);
    virtual			~AI();

  public:			// getters
    IS::AI::Action		getAction();
  };			// Player
};

#endif /* !_PLAYER_HPP_ */
