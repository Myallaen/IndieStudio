//
// APlayer.hpp for APlayer in /home/myallaen/Work/epitech/CPP/cpp_indie_studio
//
// Made by myallaen
// Login   <myallaen@epitech.eu>
//
// Started on  Sat Jun 17 19:21:23 2017 myallaen
// Last update Sun Jun 18 15:13:31 2017 myallaen
//

#ifndef _A_PLAYER_HPP_
# define _A_PLAYER_HPP_

# include <iostream>
# include <string>

# include "Players/IPlayer.hpp"

# define DIR_UP 0
# define DIR_RIGHT 1
# define DIR_DOWN 2
# define DIR_LEFT 3

namespace	IS
{
  class			APlayer: public IS::IPlayer
  {
  public:			// public vals
    std::vector<IS::Bomb>	_bombs;

  protected:			// debug vals
    unsigned int		_id;

  protected:			// IPlayer vals
    IS::IPlayer::Type		_type;

  protected:			// data vals
    unsigned int		_x;
    unsigned int		_y;
    unsigned int		_dir;
    unsigned int		_life;
    unsigned int		_bomb_power;
    unsigned int		_blocs;
    unsigned int		_max_bombs;
    sf::Clock			_invulnerability;

  protected:			// map display vals
    sf::Texture			_char_tex;
    sf::Sprite			_char_sprite;
    unsigned int		_char_state;

  protected:			// overlay display vals
    unsigned int		_overlay_x;
    unsigned int		_overlay_y;
    std::string			_name;
    std::map<std::string, sf::Text*>	_texts;


    /*\
C===| ============================================>
    \*/

  protected:			// protected ctor
				APlayer(const unsigned int&, const IS::IPlayer::Type&);
  public:			// dtor
    virtual			~APlayer();

  public:			// getters
    const std::vector<IS::Bomb>&	getBombs()const;
    const IS::IPlayer::Type&	getType()const;
    const unsigned int&		getX()const;
    const unsigned int&		getY()const;
    const unsigned int&		getDir()const;
    const unsigned int&		getLife()const;
    const unsigned int&		getBombPower()const;
    const unsigned int&		getBlocs()const;
    const unsigned int&		getMaxBombs()const;
    const unsigned int&		getId()const;

  public:			// bool checkers
    bool			hasBomb()const;
    bool			hasBloc()const;
    bool			isLiving()const;

  public:			// actions methods
    void			move(const int&);
    void			addBomb(const unsigned int&, const unsigned int&);
    void			addBloc();
    void			takeDamage();

    void			incrementMaxBombs();
    void			incrementPower();
    void			incrementBlocs();
    void			incrementLife();

  public:			// graphic methods
    void			loadChar(const int&, const int&, sf::Font&);
    void			draw(sf::RenderWindow&);
    void			drawOverlay(sf::RenderWindow&);
  };			// APlayer
};	     // IS

#endif /* !_A_PLAYER_HPP_ */
