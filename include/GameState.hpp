//
// GameState.hpp for indieStudio in /home/myallaen/Work/epitech/CPP/cpp_indie_studio/include
//
// Made by myallaen
// Login   <myallaen@epitech.net>
//
// Started on  Fri Jun 16 20:49:28 2017 myallaen
// Last update Fri Jun 16 20:51:00 2017 myallaen
//

#ifndef _GAME_STATE_HPP_
# define _GAME_STATE_HPP_

namespace IS
{
  enum		GameState
    {
      UNDEFINED = -1,
      SPLASH,
      MENU,
      MENU_SOLO,
      MENU_MULTI,
      LEADERBOARD,
      CONTROLS,
      GAME,
      PAUSE,
      END_GAME,
    };
};

#endif /* !_GAME_STATE_HPP_ */
