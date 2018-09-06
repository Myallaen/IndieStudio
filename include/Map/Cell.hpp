//
// Cell.hpp for Cell in /home/myallaen/Work/epitech/CPP/cpp_indie_studio
//
// Made by myallaen
// Login   <myallaen@epitech.eu>
//
// Started on  Fri Jun 16 21:02:47 2017 myallaen
// Last update Sun Jun 18 21:00:09 2017 myallaen
//

#ifndef _CELL_HPP_
# define _CELL_HPP_

# include <iostream>
# include <string>
# include <vector>
# include <map>

# include "Players/APlayer.hpp"
# include "Players/Bomb.hpp"

namespace	IS
{
  class			Cell
  {
  public:
    enum Type
      {
	UNDEFINED = -1,
	PATH,
	BREAKABLE_OBSTACLE,
	OBSTACLE,
	INVISIBLE_OBSTACLE,
	BOMB,
	EXPLODING_BOMB,
	EXPLOSION,
      };

  protected:			// protected vals
    IS::Cell::Type		_type;
    int				_val;
    unsigned int		_x;
    unsigned int		_y;
    int				_megumin_counter;

  public:			// tor
				Cell();
				Cell(const int&, const unsigned int&, const unsigned int&);
    virtual			~Cell();

  public:			// getters
    const IS::Cell::Type&	getType() const;
    const int&			getVal() const;
    const unsigned int&		getX() const;
    const unsigned int&		getY() const;
    bool			isDrawable();
    bool			isWalkable();
    bool			isWall();
    bool			isBreakableWall();
    bool			isBomb();
    bool			isBombExploding();
    bool			isExplosion();

  public:			// setters
    void			setVal(const int&);
    void			incrementBomb(std::map<int,IS::IPlayer*>);
    void			explodeBomb();
    void			incrementExplosion();
  };		// Cell
};

#endif /* !_CELL_HPP_ */
