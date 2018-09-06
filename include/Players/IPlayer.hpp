//
// IPlayer.hpp for IPlayer in /home/myallaen/Work/epitech/CPP/cpp_indie_studio
//
// Made by myallaen
// Login   <myallaen@epitech.eu>
//
// Started on  Sat Jun 17 19:21:23 2017 myallaen
// Last update Sun Jun 18 15:10:37 2017 myallaen
//

#ifndef _I_PLAYER_HPP_
# define _I_PLAYER_HPP_

# include <iostream>
# include <string>

# include "SFML/Graphics.hpp"
# include "SFML/Window.hpp"

# include "Players/Bomb.hpp"

namespace	IS
{
  class			IPlayer
  {
  public:
    enum			Type
      {
	UNDEFINED = -1,
	PLAYER,
	AI,
      };

  public:			// dtor
    virtual			~IPlayer() {}

  public:			// getters
    virtual const std::vector<IS::Bomb>&	getBombs()const=0;
    virtual const IS::IPlayer::Type&	getType()const=0;
    virtual const unsigned int&		getX()const=0;
    virtual const unsigned int&		getY()const=0;
    virtual const unsigned int&		getDir()const=0;
    virtual const unsigned int&		getLife()const=0;
    virtual const unsigned int&		getBombPower()const=0;
    virtual const unsigned int&		getBlocs()const=0;
    virtual const unsigned int&		getMaxBombs()const=0;
    virtual const unsigned int&		getId()const=0;

  public:			// bool checkers
    virtual bool			hasBomb()const=0;
    virtual bool			hasBloc()const=0;
    virtual bool			isLiving()const=0;

  public:			// actions methods
    virtual void			move(const int&)=0;
    virtual void			addBomb(const unsigned int&, const unsigned int&)=0;
    virtual void			addBloc()=0;
    virtual void			takeDamage()=0;

    virtual void			incrementMaxBombs()=0;
    virtual void			incrementPower()=0;
    virtual void			incrementBlocs()=0;
    virtual void			incrementLife()=0;

  public:			// graphic methods
    virtual void			loadChar(const int&, const int&, sf::Font&)=0;
    virtual void			draw(sf::RenderWindow&)=0;
    virtual void			drawOverlay(sf::RenderWindow&)=0;
  };			// IPlayer
};	     // IS

#endif /* !_I_PLAYER_HPP_ */
