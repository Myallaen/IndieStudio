//
// Splash.cpp for Splash in /home/myallaen/Work/epitech/CPP/cpp_indie_studio
//
// Made by myallaen
// Login   <myallaen@epitech.eu>
//
// Started on  Fri Jun 16 20:13:42 2017 myallaen
// Last update Sun Jun 18 13:16:47 2017 myallaen
//

#include "Menus/Splash.hpp"

IS::Splash::Splash():_rect(sf::Vector2f(2,2))
{
  _val = 0;
  _tex_logo.loadFromFile("assets/logo.png");

  _logo.setTexture(_tex_logo);
  _logo.setOrigin(240, 240);
  _logo.setPosition(960, -240);

  _rect.setFillColor(sf::Color::Black);
  _rect.setOrigin(1,1);
  _rect.setPosition(960, 540);

  _text.setString("Press any button to start");
  _text.setCharacterSize(45);
}

IS::Splash::~Splash()
{}

void IS::Splash::setTextFont(const sf::Font& font)
{
  _text.setFont(font);
  sf::FloatRect text_rect = _text.getLocalBounds();
  _text.setOrigin(text_rect.width / 2.f, text_rect.height / 2.f);
  _text.setPosition(960, 810);
  //  _text.setFillColor(sf::Color::Black);
}

void IS::Splash::gereEvents(const sf::Event& evnt)
{
  if (evnt.type == sf::Event::KeyPressed)
    {
      if (evnt.key.code == sf::Keyboard::Escape)
	_val = 150;
      if (_val == 50)
	++_val;
    }
}

void IS::Splash::gereData(IS::GameState& _state)
{
  if (_val < 50)
    _logo.setPosition(960, ((++_val) * 15) - 240);
  if (_val > 50)
    {
      _rect.setScale(((_val) - 50) * 10, (_val - 50) * 10);
      ++_val;
    }
  if (_val >= 150)
    _state = IS::MENU;
}

void IS::Splash::gereDisplay(sf::RenderWindow& _win)
{
  _win.clear(sf::Color::Red);
  _win.draw(_logo);
  if (_val >= 50)
    _win.draw(_text);
  if (_val >= 51)
    _win.draw(_rect);
  _win.display();
}
