//
// AEntity.hpp for AEntity in /home/myallaen/Work/epitech/CPP/cpp_indie_studio
//
// Made by myallaen
// Login   <myallaen@epitech.eu>
//
// Started on  Sun Jun 18 12:14:17 2017 myallaen
// Last update Sun Jun 18 13:38:30 2017 myallaen
//

#ifndef _AENTITY_HPP_
# define _AENTITY_HPP_

# include <iostream>
# include <string>

# include "Entities/IEntity.hpp"

namespace	IS
{
  class			AEntity : public IEntity
  {
  protected:			// IEntity vals
    IS::IEntity::Type		_type;

  protected:			// data vals
    unsigned int		_x;
    unsigned int 		_y;
    sf::Clock			_invulnerability;

  protected:			// display vals
    sf::Texture			_tex;
    sf::Sprite			_sprite;
                                                                    /*
    /   \             ~~~~                        \//
    |-O-|  ~~~~                               <===(()
    \   /                       ~~~~              /\\                */

  protected:			// protected ctor
    AEntity(const IS::IEntity::Type&, const unsigned int&, const unsigned int&);
  public:			// dtor
    virtual			~AEntity();

  public:			// getters
    const IS::IEntity::Type&	getType()const;
    const unsigned int&		getX()const;
    const unsigned int&		getY()const;

  public:			// bool checkers
    bool			isUsed()const;

  public:			// actions methods
    virtual void		pickedUp(IS::IPlayer*)=0;
    void			takeDamage();

  public:			// graphic methods
    void			draw(sf::RenderWindow&);
  };			// AEntity
};	     // IS

#endif /* !_AENTITY_HPP_ */
