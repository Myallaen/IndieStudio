//
// PowerUp.hpp for PowerUp in /home/myallaen/Work/epitech/CPP/cpp_indie_studio
//
// Made by myallaen
// Login   <myallaen@epitech.eu>
//
// Started on  Sun Jun 18 15:02:12 2017 myallaen
// Last update Sun Jun 18 15:29:23 2017 myallaen
//

#ifndef _POWER_UP_HPP_
# define _POWER_UP_HPP_

# include <iostream>
# include <string>

# include "Entities/AEntity.hpp"

namespace	IS
{
  class			PowerUp : public AEntity
  {
  public:			// tor
    PowerUp(const unsigned int&, const unsigned int&);
    virtual			~PowerUp();

  public:			// methods
    void			pickedUp(IS::IPlayer*);
  };		// PowerUp
};

#endif /* !_POWER_UP_HPP_ */
