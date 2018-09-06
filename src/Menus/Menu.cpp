//
// Menu.cpp for indieStudio in /home/myallaen/Work/epitech/CPP/cpp_indie_studio/src
//
// Made by myallaen
// Login   <myallaen@epitech.net>
//
// Started on  Wed Jun 14 20:50:24 2017 myallaen
// Last update Sat Jun 17 20:56:05 2017 myallaen
//

#include "Bomberman.hpp"

void IS::Bomberman::menu_init()
{
  _menu_val = 0;

  _players[1] = NULL;
  _players[2] = NULL;
  _players[3] = NULL;
  _players[4] = NULL;

  _shapes["p1_shape"] = new sf::RectangleShape(sf::Vector2f(300, 50));
  _shapes["p2_shape"] = new sf::RectangleShape(sf::Vector2f(300, 50));
  _shapes["p3_shape"] = new sf::RectangleShape(sf::Vector2f(300, 50));
  _shapes["p4_shape"] = new sf::RectangleShape(sf::Vector2f(300, 50));
  _shapes["p1_shape"]->setPosition((384 * 1) - 150, 1000);
  _shapes["p2_shape"]->setPosition((384 * 2) - 150, 1000);
  _shapes["p3_shape"]->setPosition((384 * 3) - 150, 1000);
  _shapes["p4_shape"]->setPosition((384 * 4) - 150, 1000);
  _shapes["p1_shape"]->setOutlineThickness(2);
  _shapes["p2_shape"]->setOutlineThickness(2);
  _shapes["p3_shape"]->setOutlineThickness(2);
  _shapes["p4_shape"]->setOutlineThickness(2);
  _shapes["p1_shape"]->setFillColor(sf::Color::Black);
  _shapes["p2_shape"]->setFillColor(sf::Color::Black);
  _shapes["p3_shape"]->setFillColor(sf::Color::Black);
  _shapes["p4_shape"]->setFillColor(sf::Color::Black);
  _shapes["p1_shape"]->setOutlineColor(sf::Color::White);
  _shapes["p2_shape"]->setOutlineColor(sf::Color::White);
  _shapes["p3_shape"]->setOutlineColor(sf::Color::White);
  _shapes["p4_shape"]->setOutlineColor(sf::Color::White);

  _texts["p1_join_text"] = new sf::Text("1 to join", _font, 30);
  _texts["p2_join_text"] = new sf::Text("2 to join", _font, 30);
  _texts["p3_join_text"] = new sf::Text("3 to join", _font, 30);
  _texts["p4_join_text"] = new sf::Text("4 to join", _font, 30);
  _texts["p1_on_text"] = new sf::Text("Player 1", _font, 30);
  _texts["p2_on_text"] = new sf::Text("Player 2", _font, 30);
  _texts["p3_on_text"] = new sf::Text("Player 3", _font, 30);
  _texts["p4_on_text"] = new sf::Text("Player 4", _font, 30);
  _texts["p1_join_text"]->setPosition((384 * 1) - 60, 1005);
  _texts["p2_join_text"]->setPosition((384 * 2) - 60, 1005);
  _texts["p3_join_text"]->setPosition((384 * 3) - 60, 1005);
  _texts["p4_join_text"]->setPosition((384 * 4) - 60, 1005);
  _texts["p1_on_text"]->setPosition((384 * 1) - 60, 1005);
  _texts["p2_on_text"]->setPosition((384 * 2) - 60, 1005);
  _texts["p3_on_text"]->setPosition((384 * 3) - 60, 1005);
  _texts["p4_on_text"]->setPosition((384 * 4) - 60, 1005);

  _texts["menu_1_off"] = new sf::Text("SOLO GAME", _font, 30);
  _texts["menu_2_off"] = new sf::Text("MULTIPLAYER", _font, 30);
  _texts["menu_3_off"] = new sf::Text("LEADERBOARD", _font, 30);
  _texts["menu_4_off"] = new sf::Text("CONTROLS", _font, 30);
  _texts["menu_5_off"] = new sf::Text("EXIT GAME", _font, 30);
  _texts["menu_1_on"] = new sf::Text("SOLO GAME", _font, 35);
  _texts["menu_2_on"] = new sf::Text("MULTIPLAYER", _font, 35);
  _texts["menu_3_on"] = new sf::Text("LEADERBOARD", _font, 35);
  _texts["menu_4_on"] = new sf::Text("CONTROLS", _font, 35);
  _texts["menu_5_on"] = new sf::Text("EXIT GAME", _font, 35);
  _texts["menu_1_on"]->setStyle(sf::Text::Bold | sf::Text::Underlined);
  _texts["menu_2_on"]->setStyle(sf::Text::Bold | sf::Text::Underlined);
  _texts["menu_3_on"]->setStyle(sf::Text::Bold | sf::Text::Underlined);
  _texts["menu_4_on"]->setStyle(sf::Text::Bold | sf::Text::Underlined);
  _texts["menu_5_on"]->setStyle(sf::Text::Bold | sf::Text::Underlined);
  _texts["menu_1_off"]->setPosition(200, (55 * 1) + 540);
  _texts["menu_2_off"]->setPosition(200, (55 * 2) + 540);
  _texts["menu_3_off"]->setPosition(200, (55 * 3) + 540);
  _texts["menu_4_off"]->setPosition(200, (55 * 4) + 540);
  _texts["menu_5_off"]->setPosition(200, (55 * 5) + 540);
  _texts["menu_1_on"]->setPosition(200, (55 * 1) + 540);
  _texts["menu_2_on"]->setPosition(200, (55 * 2) + 540);
  _texts["menu_3_on"]->setPosition(200, (55 * 3) + 540);
  _texts["menu_4_on"]->setPosition(200, (55 * 4) + 540);
  _texts["menu_5_on"]->setPosition(200, (55 * 5) + 540);
}

void IS::Bomberman::menu_destroy()
{
  _shapes.erase(_shapes.find("p1_shape"));
  _shapes.erase(_shapes.find("p2_shape"));
  _shapes.erase(_shapes.find("p3_shape"));
  _shapes.erase(_shapes.find("p4_shape"));

  _texts.erase(_texts.find("p1_join_text"));
  _texts.erase(_texts.find("p1_on_text"));
  _texts.erase(_texts.find("p2_join_text"));
  _texts.erase(_texts.find("p2_on_text"));
  _texts.erase(_texts.find("p3_join_text"));
  _texts.erase(_texts.find("p3_on_text"));
  _texts.erase(_texts.find("p4_join_text"));
  _texts.erase(_texts.find("p4_on_text"));

  _texts.erase(_texts.find("menu_1_off"));
  _texts.erase(_texts.find("menu_1_on"));
  _texts.erase(_texts.find("menu_2_off"));
  _texts.erase(_texts.find("menu_2_on"));
  _texts.erase(_texts.find("menu_3_off"));
  _texts.erase(_texts.find("menu_3_on"));
  _texts.erase(_texts.find("menu_4_off"));
  _texts.erase(_texts.find("menu_4_on"));
  _texts.erase(_texts.find("menu_5_off"));
  _texts.erase(_texts.find("menu_5_on"));
}

void IS::Bomberman::menu_events()
{
  if (_event.type == sf::Event::KeyPressed)
    {
      switch (_event.key.code)
	{
	case sf::Keyboard::Escape :
	  _win.close();
	  break;
	case sf::Keyboard::Num1 :
	  _players[1] = ((_players[1]) ? NULL : new IS::Player(1));
	  break;
	case sf::Keyboard::Num2 :
	  _players[2] = ((_players[2]) ? NULL : new IS::Player(2));
	  break;
	case sf::Keyboard::Num3 :
	  _players[3] = ((_players[3]) ? NULL : new IS::Player(3));
	  break;
	case sf::Keyboard::Num4 :
	  _players[4] = ((_players[4]) ? NULL : new IS::Player(4));
	  break;
	default :
	  break;
	}
      for (int i = 1; i < 5; ++i)
	if ((_players[i]) && (_players[i]->getType() == IS::IPlayer::PLAYER))
	  {
	    if (_event.key.code == static_cast<IS::Player*>(_players[i])->_controller._up)
	      _menu_val = (_menu_val + 4) % 5;
	    if (_event.key.code == static_cast<IS::Player*>(_players[i])->_controller._down)
	      _menu_val = (_menu_val + 1) % 5;
	    if (_event.key.code == static_cast<IS::Player*>(_players[i])->_controller._act1)
	      menu_select();
	  }
    }
}

void IS::Bomberman::menu_select()
{
  int nb_players = 0;

  for (int i = 1 ; i < 5; ++i)
    if (_players[i])
      ++nb_players;
  if (!(nb_players))
    return;
  switch (_menu_val)
    {
    case 0:
      if (nb_players == 1)
	_state = MENU_SOLO;
      break;
    case 1:
      _state = MENU_MULTI;
      break;
    case 2:
      _state = LEADERBOARD;
      break;
    case 3:
      _state = CONTROLS;
      break;
    case 4:
      _win.close();
      break;
    default:
      break;
    }
}

void IS::Bomberman::menu_data()
{}

void IS::Bomberman::menu_display()
{
  _win.clear(sf::Color::Black);
  _win.draw(*(_shapes["p1_shape"]));
  _win.draw(*(_shapes["p2_shape"]));
  _win.draw(*(_shapes["p3_shape"]));
  _win.draw(*(_shapes["p4_shape"]));

  if (_players[1])
    _win.draw(*(_texts["p1_on_text"]));
  else
    _win.draw(*(_texts["p1_join_text"]));
  if (_players[2])
    _win.draw(*(_texts["p2_on_text"]));
  else
    _win.draw(*(_texts["p2_join_text"]));
  if (_players[3])
    _win.draw(*(_texts["p3_on_text"]));
  else
    _win.draw(*(_texts["p3_join_text"]));
  if (_players[4])
    _win.draw(*(_texts["p4_on_text"]));
  else
    _win.draw(*(_texts["p4_join_text"]));

  if (_menu_val == 0)
    _win.draw(*(_texts["menu_1_on"]));
  else
    _win.draw(*(_texts["menu_1_off"]));
  if (_menu_val == 1)
    _win.draw(*(_texts["menu_2_on"]));
  else
    _win.draw(*(_texts["menu_2_off"]));
  if (_menu_val == 2)
    _win.draw(*(_texts["menu_3_on"]));
  else
    _win.draw(*(_texts["menu_3_off"]));
  if (_menu_val == 3)
    _win.draw(*(_texts["menu_4_on"]));
  else
    _win.draw(*(_texts["menu_4_off"]));
  if (_menu_val == 4)
    _win.draw(*(_texts["menu_5_on"]));
  else
    _win.draw(*(_texts["menu_5_off"]));

  _win.display();
}
