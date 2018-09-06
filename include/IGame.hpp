//
// IGame.hpp for IGame in /home/myallaen/Work/epitech/CPP/cpp_indie_studio
//
// Made by myallaen
// Login   <myallaen@epitech.eu>
//
// Started on  Tue Jun 13 12:39:42 2017 myallaen
// Last update Tue Jun 13 13:31:15 2017 myallaen
//

#ifndef _IGAME_HPP_
# define _IGAME_HPP_

# include <iostream>
# include <string>

namespace IS
{
  class		IGame
  {
  public:			// tor
    virtual		~IGame() {}

  public:
    virtual void	start()=0;
  };		// IGame
};

#endif /* !_IGAME_HPP_ */
