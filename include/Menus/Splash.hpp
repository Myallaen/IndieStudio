//
// Splash.hpp for Splash in /home/myallaen/Work/epitech/CPP/cpp_indie_studio
//
// Made by myallaen
// Login   <myallaen@epitech.eu>
//
// Started on  Fri Jun 16 20:13:42 2017 myallaen
// Last update Fri Jun 16 20:52:35 2017 myallaen
//

#ifndef _SPLASH_HPP_
# define _SPLASH_HPP_

# include <iostream>
# include <string>

# include "SFML/Graphics.hpp"

# include "GameState.hpp"

namespace IS
{
  class		Splash
  {
  protected:		// protected vals
    sf::Texture			_tex_logo;
    sf::Sprite			_logo;
    sf::RectangleShape		_rect;
    sf::Text			_text;
    unsigned int		_val;

  public:			// tor
				Splash();
    virtual			~Splash();

  public:			// methods
    void			setTextFont(const sf::Font&);
    void			gereEvents(const sf::Event&);
    void			gereData(IS::GameState&);
    void			gereDisplay(sf::RenderWindow&);

  };		// Splash
};

#endif /* !_SPLASH_HPP_ */
