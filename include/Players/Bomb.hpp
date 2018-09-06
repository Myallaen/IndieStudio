//
// Bomb.hpp for indieStudio in /home/myallaen/Work/epitech/CPP/cpp_indie_studio/include
//
// Made by myallaen
// Login   <myallaen@epitech.net>
//
// Started on  Sun Jun 18 13:23:16 2017 myallaen
// Last update Sun Jun 18 13:39:44 2017 myallaen
//

#ifndef _BOMB_HPP_
# define _BOMB_HPP_

# include "SFML/System.hpp"

namespace	IS
{
  class			Bomb
  {
  protected:
    unsigned int		_x;
    unsigned int		_y;
    unsigned int		_power;
    float			_val;
    sf::Clock			_time;

  public:			// tor
				Bomb(const unsigned int&, const unsigned int&, const unsigned int&);
    virtual			~Bomb();

  public:			// getters
    const unsigned int&		getX()const;
    const unsigned int&		getY()const;
    const unsigned int&		getPower()const;

  public:			// methods
    int				getBombVal();

  };			// Bomb
};		// IS

#endif /* !_BOMB_HPP_ */
