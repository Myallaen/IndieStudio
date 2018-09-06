//
// Pause.cpp for indieStudio in /home/myallaen/Work/epitech/CPP/cpp_indie_studio/src
//
// Made by myallaen
// Login   <myallaen@epitech.net>
//
// Started on  Thu Jun 15 12:19:50 2017 myallaen
// Last update Sun Jun 18 01:42:47 2017 myallaen
//

#include "Bomberman.hpp"

void IS::Bomberman::pause_init()
{
  _pause_val = 0;

  _texts["pause_big"] = new sf::Text("PAUSE", _font, 400);
  _texts["pause_big"]->setPosition(300, 150);

  _texts["pause_1_on"] = new sf::Text("RESUME", _font, 35);
  _texts["pause_2_on"] = new sf::Text("LEAVE", _font, 35);
  _texts["pause_1_off"] = new sf::Text("RESUME", _font, 30);
  _texts["pause_2_off"] = new sf::Text("LEAVE", _font, 30);
  _texts["pause_1_on"]->setStyle(sf::Text::Bold | sf::Text::Underlined);
  _texts["pause_2_on"]->setStyle(sf::Text::Bold | sf::Text::Underlined);
  _texts["pause_1_on"]->setPosition(900, (55 * 1) + 750);
  _texts["pause_2_on"]->setPosition(900, (55 * 2) + 750);
  _texts["pause_1_off"]->setPosition(900, (55 * 1) + 755);
  _texts["pause_2_off"]->setPosition(900, (55 * 2) + 755);

}

void IS::Bomberman::pause_destroy()
{
  _texts.erase(_texts.find("pause_big"));
  _texts.erase(_texts.find("pause_1_on"));
  _texts.erase(_texts.find("pause_2_on"));
  _texts.erase(_texts.find("pause_1_off"));
  _texts.erase(_texts.find("pause_2_off"));
}

void IS::Bomberman::pause_events()
{
  if (_event.type == sf::Event::KeyPressed)
    {
      switch (_event.key.code)
	{
	case sf::Keyboard::Escape:
	  _win.close();
	  break;
	default:
	  break;
	}
      for (int i = 1; i < 5; ++i)
	if ((_players[i]) && (_players[i]->getType() == IS::IPlayer::PLAYER))
	  {
	    if (_event.key.code == static_cast<IS::Player*>(_players[i])->_controller._up || _event.key.code == static_cast<IS::Player*>(_players[i])->_controller._down)
	      _pause_val = (_pause_val + 1) % 2;
	    if (_event.key.code == static_cast<IS::Player*>(_players[i])->_controller._act1)
	      pause_select();
	  }
    }
}

void IS::Bomberman::pause_select()
{
  switch (_pause_val)
    {
    case 0:
      _state = GAME;
      break;
    case 1:
      _state = END_GAME;
      break;
    default:
      break;
    }
}

void IS::Bomberman::pause_data()
{}

void IS::Bomberman::pause_display()
{
  _win.clear(sf::Color::Black);
  _win.draw(*(_texts["pause_big"]));

  if (_pause_val == 0)
    {
      _win.draw(*(_texts["pause_1_on"]));
      _win.draw(*(_texts["pause_2_off"]));
    }
  else
    {
      _win.draw(*(_texts["pause_1_off"]));
      _win.draw(*(_texts["pause_2_on"]));
    }
  _win.display();
}
