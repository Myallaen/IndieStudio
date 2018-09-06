//
// Game.cpp for indieStudio in /home/myallaen/Work/epitech/CPP/cpp_indie_studio/src
//
// Made by myallaen
// Login   <myallaen@epitech.net>
//
// Started on  Thu Jun 15 12:14:28 2017 myallaen
// Last update Sun Jun 18 21:16:26 2017 myallaen
//

#include "Bomberman.hpp"

void IS::Bomberman::game_init()
{}

void IS::Bomberman::game_destroy()
{}

void IS::Bomberman::game_start(int map_bg, int map_id)
{
  _map.create(map_bg, map_id);
}

void IS::Bomberman::game_events()
{
  if (_event.type == sf::Event::KeyPressed)
    {
      switch (_event.key.code)
	{
	case sf::Keyboard::Escape :
	  _state = PAUSE;
	  break;
	default :
	  break;
	}
      for (int i = 1; i < 5; ++i)
	{
	  if ((_players[i]) && (_players[i]->isLiving()))
	    {
	      if (_players[i]->getType() == IS::IPlayer::PLAYER)
		{
		  if (_event.key.code == static_cast<IS::Player*>(_players[i])->_controller._up)
		    if (_map.getCell(_players[i]->getX(), _players[i]->getY() - 1)->isWalkable())
		      _players[i]->move(DIR_UP);
		  if (_event.key.code == static_cast<IS::Player*>(_players[i])->_controller._down)
		    if (_map.getCell(_players[i]->getX(), _players[i]->getY() + 1)->isWalkable())
		      _players[i]->move(DIR_DOWN);
		  if (_event.key.code == static_cast<IS::Player*>(_players[i])->_controller._left)
		    if (_map.getCell(_players[i]->getX() - 1, _players[i]->getY())->isWalkable())
		      _players[i]->move(DIR_LEFT);
		  if (_event.key.code == static_cast<IS::Player*>(_players[i])->_controller._right)
		    if (_map.getCell(_players[i]->getX() + 1, _players[i]->getY())->isWalkable())
		      _players[i]->move(DIR_RIGHT);
		  if (_event.key.code == static_cast<IS::Player*>(_players[i])->_controller._act1)
		    if (_players[i]->hasBomb() && (!(_map.getCell(_players[i]->getY(), _players[i]->getX())->isBomb())))
		      _map.placeBomb(_players[i]);
		  if (_event.key.code == static_cast<IS::Player*>(_players[i])->_controller._act2)
		    if (_players[i]->hasBloc())
		      _map.placeBloc(_players[i]);
		}

	    }
	}
    }
}

void IS::Bomberman::game_data()
{
  for (int i = 1; i < 5; ++i)
    if ((_players[i]) && (_players[i]->isLiving()) && (_players[i]->getType() == IS::IPlayer::AI))
      {
	IS::AI::Action action = static_cast<IS::AI*>(_players[i])->getAction();
	switch (action)
	  {
	  case IS::AI::MOVE_UP :
	    if (_map.getCell(_players[i]->getX(), _players[i]->getY() - 1)->isWalkable())
	      _players[i]->move(DIR_UP);
	    break;
	  case IS::AI::MOVE_DOWN :
	    if (_map.getCell(_players[i]->getX(), _players[i]->getY() + 1)->isWalkable())
	      _players[i]->move(DIR_DOWN);
	    break;
	  case IS::AI::MOVE_LEFT :
	    if (_map.getCell(_players[i]->getX() - 1, _players[i]->getY())->isWalkable())
	      _players[i]->move(DIR_LEFT);
	    break;
	  case IS::AI::MOVE_RIGHT :
	    if (_map.getCell(_players[i]->getX() + 1, _players[i]->getY())->isWalkable())
	      _players[i]->move(DIR_RIGHT);
	    break;
	  case IS::AI::ACT1 :
	    if (_players[i]->hasBomb() && (!(_map.getCell(_players[i]->getY(), _players[i]->getX())->isBomb())))
	      _map.placeBomb(_players[i]);
	    break;
	  case IS::AI::ACT2 :
	    if (_players[i]->hasBloc())
	      _map.placeBloc(_players[i]);
	    break;
	  case IS::AI::SLEEP :
	    break;
	  default :
	    throw new std::invalid_argument("AI action unknown");
	  }
      }
  _map.checkMap();
  _map.checkBombs(_players);
  _map.checkPlayer(_players);
  _map.checkEntities();
  int nb_char = 0;
  int nb_player = 0;
  for (int i = 1; i < 5; ++i)
    if ((_players[i]) && (_players[i]->isLiving()))
      {
	++nb_char;
	if (_players[i]->getType() == IS::IPlayer::PLAYER)
	  ++nb_player;
      }
  if (nb_player == 0 || nb_char == 1)
    _state = IS::END_GAME;
}

void IS::Bomberman::game_display()
{
  _win.clear(sf::Color::Black);
  _map.draw(_win);
  for (int i = 1; i < 5; ++i)
    if (_players[i])
      {
	if (_players[i]->isLiving())
	  _players[i]->draw(_win);
	_players[i]->drawOverlay(_win);
      }
  _win.display();
}
