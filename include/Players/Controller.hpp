//
// Controller.hpp for indieStudio in /home/myallaen/Work/epitech/CPP/cpp_indie_studio/include
//
// Made by myallaen
// Login   <myallaen@epitech.net>
//
// Started on  Sun Jun 18 13:29:26 2017 myallaen
// Last update Sun Jun 18 13:36:46 2017 myallaen
//

#ifndef _CONTROLLER_HPP_
# define _CONTROLLER_HPP_

# include "SFML/Window.hpp"

namespace	IS
{
  class			Controller
  {
  public:			// public vals
    sf::Keyboard::Key		_up;
    sf::Keyboard::Key		_down;
    sf::Keyboard::Key		_left;
    sf::Keyboard::Key		_right;
    sf::Keyboard::Key		_act1;
    sf::Keyboard::Key		_act2;

  public:			// tor
				Controller();
				Controller(const unsigned int&);
    virtual			~Controller();

  public:			// getters
    const sf::Keyboard::Key&	getUp()const;
    const sf::Keyboard::Key&	getDown()const;
    const sf::Keyboard::Key&	getLeft()const;
    const sf::Keyboard::Key&	getRight()const;
    const sf::Keyboard::Key&	getAct1()const;
    const sf::Keyboard::Key&	getAct2()const;

  public:			// setters
    void			setUp(const sf::Keyboard::Key&);
    void			setDown(const sf::Keyboard::Key&);
    void			setLeft(const sf::Keyboard::Key&);
    void			setRight(const sf::Keyboard::Key&);
    void			setAct1(const sf::Keyboard::Key&);
    void			setAct2(const sf::Keyboard::Key&);

  };			// Controller
};		// IS

#endif /* !_CONTROLLER_HPP_ */
