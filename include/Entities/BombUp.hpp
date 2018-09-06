//
// BombUp.hpp for BombUp in /home/myallaen/Work/epitech/CPP/cpp_indie_studio
//
// Made by myallaen
// Login   <myallaen@epitech.eu>
//
// Started on  Sun Jun 18 15:02:12 2017 myallaen
// Last update Sun Jun 18 15:05:23 2017 myallaen
//

#ifndef _BOMB_UP_HPP_
# define _BOMB_UP_HPP_

# include <iostream>
# include <string>

# include "Entities/AEntity.hpp"

namespace	IS
{
  class			BombUp : public AEntity
  {
  public:			// tor
				BombUp(const unsigned int&, const unsigned int&);
    virtual			~BombUp();

  public:			// methods
    void			pickedUp(IS::IPlayer*);
  };		// BombUp
};

#endif /* !_BOMB_UP_HPP_ */
