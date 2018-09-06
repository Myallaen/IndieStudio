//
// Bomberman.hpp for Bomberman in /home/myallaen/Work/epitech/CPP/cpp_indie_studio
//
// Made by myallaen
// Login   <myallaen@epitech.eu>
//
// Started on  Tue Jun 13 12:55:08 2017 myallaen
// Last update Sun Jun 18 21:58:48 2017 myallaen
//

#ifndef _BOMBERMAN_HPP_
# define _BOMBERMAN_HPP_

# include <iostream>
# include <fstream>
# include <sstream>
# include <exception>
# include <stdexcept>
# include <string>
# include <vector>
# include <map>

# include "SFML/Audio.hpp"
# include "SFML/Graphics.hpp"
# include "SFML/Network.hpp"
# include "SFML/System.hpp"
# include "SFML/Window.hpp"

# include "IGame.hpp"
# include "GameState.hpp"

# include "Menus/Splash.hpp"

# include "Map/Map.hpp"
# include "Players/Player.hpp"
# include "Players/AI.hpp"
# include "Players/Bomb.hpp"

namespace	IS
{
  class			Bomberman: public IGame
  {
  protected:			// protected vals
    sf::RenderWindow		_win;
    sf::Event			_event;
    sf::Font			_font;
    IS::GameState		_state;
    std::map<int, IS::IPlayer*>		_players;
    std::map<std::string, sf::Texture*>	_textures;
    std::map<std::string, sf::Sprite*>	_sprites;
    std::map<std::string, sf::Shape*>	_shapes;
    std::map<std::string, sf::Text*>	_texts;

  protected:
    IS::Splash			_splash;
    IS::Map			_map;
    int				_menu_val;
    int				_solo_val;
    int				_menu_map;
    int				_menu_bg;
    int				_pause_val;

  public:			// tor
				Bomberman();
    virtual			~Bomberman();

  public:			// methods
    void			start();
  protected:			// Bomberman.cpp
    void			loop();
    void			gere_events();
    void			gere_data();
    void			gere_display();

  protected:			// Menu.cpp
    void			menu_init();
    void			menu_destroy();
    void			menu_events();
    void			menu_data();
    void			menu_display();
    void			menu_select();

  protected:			// Solo.cpp
    void			solo_init();
    void			solo_destroy();
    void			solo_events();
    void			solo_data();
    void			solo_display();
    void			solo_select();

  protected:			// Game.cpp
    void			game_init();
    void			game_destroy();
    void			game_start(int, int);
    void			game_events();
    void			game_data();
    void			game_display();

  protected:			// Pause.cpp
    void			pause_init();
    void			pause_destroy();
    void			pause_events();
    void			pause_data();
    void			pause_display();
    void		        pause_select();

  };			// Bomberman
}
#endif /* !_BOMBERMAN_HPP_ */
