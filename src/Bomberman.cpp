//
// Bomberman.cpp for Bomberman in /home/myallaen/Work/epitech/CPP/cpp_indie_studio
//
// Made by myallaen
// Login   <myallaen@epitech.eu>
//
// Started on  Tue Jun 13 12:55:08 2017 myallaen
// Last update Sun Jun 18 21:58:29 2017 myallaen
//

#include "Bomberman.hpp"

IS::Bomberman::Bomberman():_win(sf::VideoMode(1920, 1080), "IndieBomber", sf::Style::Fullscreen),_state(IS::SPLASH)
{
  _win.setFramerateLimit(30);
  _font.loadFromFile("assets/fonts/Minecraft.ttf");
  _splash.setTextFont(_font);
  menu_init();
  solo_init();
  game_init();
  pause_init();
}

IS::Bomberman::~Bomberman()
{
  menu_destroy();
  solo_destroy();
  game_destroy();
  pause_destroy();
}

void IS::Bomberman::start()
{
  loop();
}

void IS::Bomberman::loop()
{
  while (_win.isOpen())
    {
      gere_events();
      gere_data();
      gere_display();
    }
}

void IS::Bomberman::gere_events()
{
  while (_win.isOpen() && _win.pollEvent(_event))
    {
      if (_event.type == sf::Event::Closed)
	_win.close();
      else
	switch (_state)
	  {
	  case IS::SPLASH :
	    _splash.gereEvents(_event);
	    break;
	  case IS::MENU :
	    menu_events();
	    break;
	  case IS::MENU_SOLO :
	    solo_events();
	    break;
	  case IS::GAME :
	    game_events();
	    break;
	  case IS::PAUSE :
	    pause_events();
	    break;
	    /* case IS::MENU_SOLO :
	     * break;
	     * case IS::MENU_MULTI :
	     * break;
	     * case IS::LEADERBOARD :
	     * break;
	     * case IS::END_GAME :
	     * break;
	     */
	  default :
	    if ((_event.type == sf::Event::KeyPressed) && (_event.key.code == sf::Keyboard::Escape))
	      _win.close();
	}
    }
}

void IS::Bomberman::gere_data()
{
  switch (_state)
    {
    case IS::SPLASH :
      _splash.gereData(_state);
      break;
    case IS::MENU :
      menu_data();
      break;
    case IS::MENU_SOLO :
      solo_data();
      break;
    case IS::MENU_MULTI :
      game_start(1, 1);
      for (unsigned int i = 1; i < 5; ++i)
	{
	  if (_players[i] == NULL)
	    _players[i] = new IS::AI(i);
	  _players[i]->loadChar(i, 1, _font);
	}
      _state = IS::GAME;
      break;
    case IS::GAME :
      game_data();
      break;
    case IS::PAUSE :
      pause_data();
      break;
      /* case IS::MENU_SOLO :
       * break;
       * break;
       * case IS::LEADERBOARD :
       * break;
       * case IS::END_GAME :
       * break;
       */
    default :
      break;
    }
}

void IS::Bomberman::gere_display()
{
  switch (_state)
    {
    case IS::SPLASH :
      _splash.gereDisplay(_win);
      break;
    case IS::MENU :
      menu_display();
      break;
    case IS::MENU_SOLO :
      solo_display();
      break;
    case IS::GAME :
      game_display();
      break;
    case IS::PAUSE :
      pause_display();
      break;
      /* case IS::MENU_SOLO :
       * break;
       * case IS::MENU_MULTI :
       * break;
       * case IS::LEADERBOARD :
       * break;
       * case IS::END_GAME :
       * break;
       */
    default :
      _win.clear(sf::Color::Black);
      _win.display();
    }
}
