//
// BlocUp.hpp for BlocUp in /home/myallaen/Work/epitech/CPP/cpp_indie_studio
//
// Made by myallaen
// Login   <myallaen@epitech.eu>
//
// Started on  Sun Jun 18 15:02:12 2017 myallaen
// Last update Sun Jun 18 15:27:52 2017 myallaen
//

#ifndef _BLOC_UP_HPP_
# define _BLOC_UP_HPP_

# include <iostream>
# include <string>

# include "Entities/AEntity.hpp"

namespace	IS
{
  class			BlocUp : public AEntity
  {
  public:			// tor
				BlocUp(const unsigned int&, const unsigned int&);
    virtual			~BlocUp();

  public:			// methods
    void			pickedUp(IS::IPlayer*);
  };		// BlocUp
};

#endif /* !_BLOC_UP_HPP_ */
