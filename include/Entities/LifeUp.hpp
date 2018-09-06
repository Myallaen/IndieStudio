//
// LifeUp.hpp for LifeUp in /home/myallaen/Work/epitech/CPP/cpp_indie_studio
//
// Made by myallaen
// Login   <myallaen@epitech.eu>
//
// Started on  Sun Jun 18 15:02:12 2017 myallaen
// Last update Sun Jun 18 15:28:25 2017 myallaen
//

#ifndef _LIFE_UP_HPP_
# define _LIFE_UP_HPP_

# include <iostream>
# include <string>

# include "Entities/AEntity.hpp"

namespace	IS
{
  class			LifeUp : public AEntity
  {
  public:			// tor
				LifeUp(const unsigned int&, const unsigned int&);
    virtual			~LifeUp();

  public:			// methods
    void			pickedUp(IS::IPlayer*);
  };		// LifeUp
};

#endif /* !_LIFE_UP_HPP_ */
