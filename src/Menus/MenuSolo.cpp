//
// Menu.cpp for indieStudio in /home/myallaen/Work/epitech/CPP/cpp_indie_studio/src
//
// Made by myallaen
// Login   <myallaen@epitech.net>
//
// Started on  Wed Jun 14 20:50:24 2017 myallaen
// Last update Sun Jun 18 22:06:59 2017 myallaen
//

#include "Bomberman.hpp"

void IS::Bomberman::solo_init()
{
  _solo_val = 0;
  _menu_map = 0;
  _menu_bg = 0;

  _shapes["solo_p1_shape"] = new sf::RectangleShape(sf::Vector2f(300, 50));
  _shapes["solo_p2_shape"] = new sf::RectangleShape(sf::Vector2f(300, 50));
  _shapes["solo_p3_shape"] = new sf::RectangleShape(sf::Vector2f(300, 50));
  _shapes["solo_p4_shape"] = new sf::RectangleShape(sf::Vector2f(300, 50));
  _shapes["solo_p1_shape"]->setPosition((384 * 1) - 150, 1000);
  _shapes["solo_p2_shape"]->setPosition((384 * 2) - 150, 1000);
  _shapes["solo_p3_shape"]->setPosition((384 * 3) - 150, 1000);
  _shapes["solo_p4_shape"]->setPosition((384 * 4) - 150, 1000);
  _shapes["solo_p1_shape"]->setOutlineThickness(2);
  _shapes["solo_p2_shape"]->setOutlineThickness(2);
  _shapes["solo_p3_shape"]->setOutlineThickness(2);
  _shapes["solo_p4_shape"]->setOutlineThickness(2);
  _shapes["solo_p1_shape"]->setFillColor(sf::Color::Black);
  _shapes["solo_p2_shape"]->setFillColor(sf::Color::Black);
  _shapes["solo_p3_shape"]->setFillColor(sf::Color::Black);
  _shapes["solo_p4_shape"]->setFillColor(sf::Color::Black);
  _shapes["solo_p1_shape"]->setOutlineColor(sf::Color::White);
  _shapes["solo_p2_shape"]->setOutlineColor(sf::Color::White);
  _shapes["solo_p3_shape"]->setOutlineColor(sf::Color::White);
  _shapes["solo_p4_shape"]->setOutlineColor(sf::Color::White);

  _texts["solo_p1_ia_text"] = new sf::Text(" AI   1", _font, 30);
  _texts["solo_p2_ia_text"] = new sf::Text(" AI   2", _font, 30);
  _texts["solo_p3_ia_text"] = new sf::Text(" AI   3", _font, 30);
  _texts["solo_p4_ia_text"] = new sf::Text(" AI   4", _font, 30);
  _texts["solo_p1_on_text"] = new sf::Text("Player 1", _font, 30);
  _texts["solo_p2_on_text"] = new sf::Text("Player 2", _font, 30);
  _texts["solo_p3_on_text"] = new sf::Text("Player 3", _font, 30);
  _texts["solo_p4_on_text"] = new sf::Text("Player 4", _font, 30);
  _texts["solo_p1_ia_text"]->setPosition((384 * 1) - 60, 1005);
  _texts["solo_p2_ia_text"]->setPosition((384 * 2) - 60, 1005);
  _texts["solo_p3_ia_text"]->setPosition((384 * 3) - 60, 1005);
  _texts["solo_p4_ia_text"]->setPosition((384 * 4) - 60, 1005);
  _texts["solo_p1_on_text"]->setPosition((384 * 1) - 60, 1005);
  _texts["solo_p2_on_text"]->setPosition((384 * 2) - 60, 1005);
  _texts["solo_p3_on_text"]->setPosition((384 * 3) - 60, 1005);
  _texts["solo_p4_on_text"]->setPosition((384 * 4) - 60, 1005);

  _texts["solo_1_1_off"] = new sf::Text("LEVEL", _font, 30);
  _texts["solo_1_2_off"] = new sf::Text("", _font, 30);
  _texts["solo_2_1_off"] = new sf::Text(" MAP ", _font, 30);
  _texts["solo_2_2_off"] = new sf::Text("", _font, 30);
  _texts["solo_1_1_on"] = new sf::Text("LEVEL", _font, 35);
  _texts["solo_1_2_on"] = new sf::Text("", _font, 35);
  _texts["solo_2_1_on"] = new sf::Text(" MAP ", _font, 35);
  _texts["solo_2_2_on"] = new sf::Text("", _font, 35);
  _texts["solo_1_1_on"]->setStyle(sf::Text::Bold | sf::Text::Underlined);
  _texts["solo_2_1_on"]->setStyle(sf::Text::Bold | sf::Text::Underlined);
  _texts["solo_1_1_off"]->setPosition(900, (55 * 1) + 340);
  _texts["solo_1_2_off"]->setPosition(900, (55 * 2) + 340);
  _texts["solo_2_1_off"]->setPosition(900, (55 * 3) + 340);
  _texts["solo_2_2_off"]->setPosition(900, (55 * 4) + 340);
  _texts["solo_1_1_on"]->setPosition(900, (55 * 1) + 340);
  _texts["solo_1_2_on"]->setPosition(900, (55 * 2) + 340);
  _texts["solo_2_1_on"]->setPosition(900, (55 * 3) + 340);
  _texts["solo_2_2_on"]->setPosition(900, (55 * 4) + 340);
}

void IS::Bomberman::solo_destroy()
{
  _shapes.erase(_shapes.find("solo_p1_shape"));
  _shapes.erase(_shapes.find("solo_p2_shape"));
  _shapes.erase(_shapes.find("solo_p3_shape"));
  _shapes.erase(_shapes.find("solo_p4_shape"));

  _texts.erase(_texts.find("solo_p1_ia_text"));
  _texts.erase(_texts.find("solo_p1_on_text"));
  _texts.erase(_texts.find("solo_p2_ia_text"));
  _texts.erase(_texts.find("solo_p2_on_text"));
  _texts.erase(_texts.find("solo_p3_ia_text"));
  _texts.erase(_texts.find("solo_p3_on_text"));
  _texts.erase(_texts.find("solo_p4_ia_text"));
  _texts.erase(_texts.find("solo_p4_on_text"));

  _texts.erase(_texts.find("solo_1_1_off"));
  _texts.erase(_texts.find("solo_1_1_on"));
  _texts.erase(_texts.find("solo_1_2_off"));
  _texts.erase(_texts.find("solo_1_2_on"));
  _texts.erase(_texts.find("solo_2_1_off"));
  _texts.erase(_texts.find("solo_2_1_on"));
  _texts.erase(_texts.find("solo_2_2_off"));
  _texts.erase(_texts.find("solo_2_2_on"));
}

void IS::Bomberman::solo_events()
{
  if (_event.type == sf::Event::KeyPressed)
    {
      switch (_event.key.code)
	{
	case sf::Keyboard::Escape :
	  _state = MENU;
	  break;
	default :
	  break;
	}
      for (int i = 1; i < 5; ++i)
	if ((_players[i]) && (_players[i]->getType() == IS::IPlayer::PLAYER))
	  {
	    if (_event.key.code == static_cast<IS::Player*>(_players[i])->_controller._up)
	      _solo_val = (_solo_val + 1) % 2;
	    if (_event.key.code == static_cast<IS::Player*>(_players[i])->_controller._down)
	      _solo_val = (_solo_val + 1) % 2;
	    if (_event.key.code == static_cast<IS::Player*>(_players[i])->_controller._left)
	      {
		if (_solo_val == 0)
		  _menu_map = ((_menu_map + 4) % 5);
		if (_solo_val == 1)
		  _menu_bg = ((_menu_bg + 1) % 2);
	      }
	    if (_event.key.code == static_cast<IS::Player*>(_players[i])->_controller._right)
	      {
		if (_solo_val == 0)
		  _menu_map = ((_menu_map + 1) % 5);
		if (_solo_val == 1)
		  _menu_bg = ((_menu_bg + 1) % 2);
	      }
	    if (_event.key.code == static_cast<IS::Player*>(_players[i])->_controller._act1)
	      solo_select();
	    if (_event.key.code == static_cast<IS::Player*>(_players[i])->_controller._act1)
	      _state = MENU;

	  }
    }
}

void IS::Bomberman::solo_select()
{
  game_start(_menu_map + 1, _menu_bg + 1);
  for (unsigned int i = 1; i < 5; ++i)
    {
      if (_players[i] == NULL)
	_players[i] = new IS::AI(i);
      _players[i]->loadChar(i, 1, _font);
    }
  _state = GAME;
}

void IS::Bomberman::solo_data()
{}

void IS::Bomberman::solo_display()
{
  _win.clear(sf::Color::Black);
  _win.draw(*(_shapes["solo_p1_shape"]));
  _win.draw(*(_shapes["solo_p2_shape"]));
  _win.draw(*(_shapes["solo_p3_shape"]));
  _win.draw(*(_shapes["solo_p4_shape"]));

  if (_players[1])
    _win.draw(*(_texts["solo_p1_on_text"]));
  else
    _win.draw(*(_texts["solo_p1_ia_text"]));
  if (_players[2])
    _win.draw(*(_texts["solo_p2_on_text"]));
  else
    _win.draw(*(_texts["solo_p2_ia_text"]));
  if (_players[3])
    _win.draw(*(_texts["solo_p3_on_text"]));
  else
    _win.draw(*(_texts["solo_p3_ia_text"]));
  if (_players[4])
    _win.draw(*(_texts["solo_p4_on_text"]));
  else
    _win.draw(*(_texts["solo_p4_ia_text"]));

  std::string text_1 = "< " + std::to_string(_menu_map + 1) + " >";
  std::string text_2 = "< " + std::to_string(_menu_bg + 1) + " >";

  _texts["solo_1_2_on"]->setString(text_1);
  _texts["solo_2_2_on"]->setString(text_2);
  _texts["solo_1_2_off"]->setString(text_1);
  _texts["solo_2_2_off"]->setString(text_2);

  if (_solo_val == 0)
    {
      _win.draw(*(_texts["solo_1_1_on"]));
      _win.draw(*(_texts["solo_1_2_on"]));
      _win.draw(*(_texts["solo_2_1_off"]));
      _win.draw(*(_texts["solo_2_2_off"]));
    }
  else
    {
      _win.draw(*(_texts["solo_1_1_off"]));
      _win.draw(*(_texts["solo_1_2_off"]));
      _win.draw(*(_texts["solo_2_1_on"]));
      _win.draw(*(_texts["solo_2_2_on"]));
    }

  _win.display();
}
