//
// IEntity.hpp for IEntity in /home/myallaen/Work/epitech/CPP/cpp_indie_studio
//
// Made by myallaen
// Login   <myallaen@epitech.eu>
//
// Started on  Sun Jun 18 12:06:20 2017 myallaen
// Last update Sun Jun 18 14:54:07 2017 myallaen
//

#ifndef _IENTITY_HPP_
# define _IENTITY_HPP_

# include <iostream>
# include <string>

# include "SFML/Window.hpp"
# include "SFML/Graphics.hpp"

# include "Players/IPlayer.hpp"

namespace	IS
{
  class			IEntity
  {
  public:
    enum			Type
      {
	UNDEFINED = -1,
	USED,
	BOMB_UP,
	POWER_UP,
	BLOC_UP,
	LIFE_UP,
      };			// Type

  public:			// tor
    virtual		        ~IEntity() {}

  public:			// pure getters
    virtual const IS::IEntity::Type& getType()const=0;
    virtual const unsigned int&	getX()const=0;
    virtual const unsigned int& getY()const=0;

  public:			// bool checkers
    virtual bool		isUsed()const=0;

  public:			// actions methods
    virtual void		pickedUp(IS::IPlayer*)=0;
    virtual void		takeDamage()=0;

  public:			// graphic methods
    virtual void		draw(sf::RenderWindow&)=0;

  };			// IEntity

  IS::IEntity*			newRandomEntity(const unsigned int&, const unsigned int&);

};		// IS

#endif /* !_IENTITY_HPP_ */
