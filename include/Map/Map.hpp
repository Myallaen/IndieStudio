//
// Map.hpp for Map in /home/myallaen/Work/epitech/CPP/cpp_indie_studio
//
// Made by myallaen
// Login   <myallaen@epitech.eu>
//
// Started on  Fri Jun 16 22:06:03 2017 myallaen
// Last update Sun Jun 18 21:04:54 2017 myallaen
//

#ifndef _MAP_HPP_
# define _MAP_HPP_

# include <iostream>
# include <iomanip>
# include <fstream>
# include <sstream>
# include <string>
# include <exception>
# include <stdexcept>
# include <vector>
# include <map>

# include <cstdlib>
# include <ctime>

# include "SFML/Graphics.hpp"
# include "SFML/Window.hpp"

# include "Map/Cell.hpp"
# include "Players/APlayer.hpp"
# include "Entities/IEntity.hpp"

namespace IS
{
  class		Map
  {
  protected:		// protected vals
    sf::Texture			_tex_map_bg;
    sf::Sprite			_map_bg;
    sf::Texture			_tex_sprite_sheet;
    sf::Sprite			_sprite_sheet;
    std::vector<IS::IEntity*>	_entities;
    std::vector<std::vector<IS::Cell> >			_map;

  public:			// tor
				Map();
    virtual			~Map();

  public:			// getter
    IS::Cell*			getCell(const unsigned int&, const unsigned int&);

  public:			// methods
    void			placeBomb(IS::IPlayer*);
    void			placeBloc(IS::IPlayer*);
    void			createEntity(const unsigned int&, const unsigned int&);
    void			checkMap();
    void			checkBombs(std::map<int,IS::IPlayer*>);
    void			explodeBomb(std::map<int,IS::IPlayer*>, const unsigned int&, const unsigned int&);
    int				setCellExplosion(std::map<int,IS::IPlayer*>, const unsigned int&, const unsigned int&, const int&);
    void			checkPlayer(std::map<int,IS::IPlayer*>);
    void			checkEntities();

  public:
    void			create(const int&, const int&);
    void			draw(sf::RenderWindow&);
  public:
    void			debug();
  };		// Map
};

#endif /* !_MAP_HPP_ */
