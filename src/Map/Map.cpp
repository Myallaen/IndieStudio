//
// Map.cpp for Map in /home/myallaen/Work/epitech/CPP/cpp_indie_studio
//
// Made by myallaen
// Login   <myallaen@epitech.eu>
//
// Started on  Fri Jun 16 22:06:03 2017 myallaen
// Last update Sun Jun 18 21:17:19 2017 myallaen
//

#include "Map/Map.hpp"

IS::Map::Map()
{
  srand(time(NULL));
}

IS::Map::~Map()
{}

IS::Cell* IS::Map::getCell(const unsigned int& x, const unsigned int& y)
{
  //std::cout << "Map::getCell(" << x << ", " << y << ")" << std::endl;

  if (y < _map.size())
    if (x < _map[y].size())
      return &(_map[y][x]);
  return new IS::Cell();
}

void IS::Map::placeBomb(IS::IPlayer* player)
{
  //std::cout << "Map::placeBomb(player)" << std::endl;

  unsigned int x = player->getX();
  unsigned int y = player->getY();

  player->addBomb(x, y);
  _map[y][x].setVal(8);
}

void IS::Map::placeBloc(IS::IPlayer* player)
{
  //std::cout << "Map::placeBloc(player)" << std::endl;

  unsigned int x = player->getX();
  unsigned int y = player->getY();

  player->addBloc();
  if (rand() % 10)
    _map[y][x].setVal(2);
  else
    _map[y][x].setVal(3);
}

void IS::Map::createEntity(const unsigned int& x, const unsigned int& y)
{
  IS::IEntity* entity = NULL;

  if (_map[y][x].getVal() == 3)
    entity = newRandomEntity(x, y);
  if (_map[y][x].getVal() == 2)
    if ((rand() % 4) == 0)
    entity = newRandomEntity(x, y);
  if (entity)
    _entities.push_back(entity);
}

void IS::Map::checkMap()
{
  //std::cout << "Map::checkMap()" << std::endl;

  for (unsigned int y = 0; y < _map.size(); ++y)
    for (unsigned int x = 0; x < _map[y].size(); ++x)
      if (_map[y][x].isExplosion())
	_map[y][x].incrementExplosion();
}

void IS::Map::checkBombs(std::map<int,IS::IPlayer*> players)
{
  //std::cout << "Map::checkBombs(std::map<int,IS::IPlayer*> players) << std::endl;

  for (unsigned int i = 0; i < 5; ++i)
    if ((players[i]) && (static_cast<IS::APlayer*>(players[i])->_bombs.size()))
      {
	std::vector<IS::Bomb> bombs = static_cast<IS::APlayer*>(players[i])->getBombs();
	for (unsigned int j = 0; j < bombs.size(); ++j)
	  {
	    if (_map[bombs[j].getY()][bombs[j].getX()].isBomb())
	      _map[bombs[j].getY()][bombs[j].getX()].incrementBomb(players);
	    if (_map[bombs[j].getY()][bombs[j].getX()].isBombExploding())
	      {
		explodeBomb(players, bombs[j].getX(), bombs[j].getY());
		j = 0;
	      }
	  }
      }
}

void IS::Map::explodeBomb(std::map<int,IS::IPlayer*> players, const unsigned int& x, const unsigned int& y)
{
  //std::cout << "Map::explodeBomb()" << std::endl;

  for (unsigned int i = 0; i < 5; ++i)
    if ((players[i]) && (static_cast<IS::APlayer*>(players[i])->_bombs.size()))
      for (unsigned int j = 0; j < static_cast<IS::APlayer*>(players[i])->_bombs.size(); ++j)
	if ((static_cast<IS::APlayer*>(players[i])->_bombs[j].getX() == x) &&
	    (static_cast<IS::APlayer*>(players[i])->_bombs[j].getY() == y))
	  {
	    IS::Bomb bomb = static_cast<IS::APlayer*>(players[i])->_bombs[j];

	    _map[y][x].setVal(22);
	    for (unsigned int i = 1; i <= bomb.getPower(); ++i)
	      if  (setCellExplosion(players, x + i, y, (i == bomb.getPower())? 16 : 20))
		break;
	    for (unsigned int i = 1; i <= bomb.getPower(); ++i)
	      if  (setCellExplosion(players, x - i, y, (i == bomb.getPower())? 17 : 20))
		break;
	    for (unsigned int i = 1; i <= bomb.getPower(); ++i)
	      if  (setCellExplosion(players, x, y - i, (i == bomb.getPower())? 18 : 21))
		break;
	    for (unsigned int i = 1; i <= bomb.getPower(); ++i)
	      if  (setCellExplosion(players, x, y + i, (i == bomb.getPower())? 19 : 21))
		break;
	    static_cast<IS::APlayer*>(players[i])->_bombs.erase(static_cast<IS::APlayer*>(players[i])->_bombs.begin() + j);
	  }
}

int	IS::Map::setCellExplosion(std::map<int, IS::IPlayer*> players, const unsigned int& x, const unsigned int& y,const int& val)
{
  if (_map[y][x].isBomb())
    {
      _map[y][x].explodeBomb();
      explodeBomb(players, x, y);
      return 0;
    }
  if (_map[y][x].isWall())
    {
      if (_map[y][x].isBreakableWall())
	{
	  createEntity(x, y);
	  _map[y][x].setVal(val);
	}
      return 1;
    }
  if (_map[y][x].isExplosion())
    {
      int tmp_val = _map[y][x].getVal();
      switch (tmp_val)
	{
	case 16:
	  if (val == 17)
	    _map[y][x].setVal(20);
	  else if (val == 18 || val == 19 || val == 21)
	    _map[y][x].setVal(22);
	  break;
	case 17:
	  if (val == 16)
	    _map[y][x].setVal(20);
	  else if (val == 18 || val == 19 || val == 21)
	    _map[y][x].setVal(22);
	    ;
	  break;
	case 18:
	  if (val == 19)
	    _map[y][x].setVal(21);
	  else if (val == 16 || val == 17 || val == 20)
	    _map[y][x].setVal(22);
	    ;
	  break;
	case 19:
	  if (val == 18)
	    _map[y][x].setVal(21);
	  else if (val == 16 || val == 17 || val == 20)
	    _map[y][x].setVal(22);
	    ;
	  break;
	case 20:
	  if (val == 19 || val == 19 || val == 21)
	    _map[y][x].setVal(22);
	  break;
	case 21:
	  if (val == 16 || val == 17 || val == 20)
	    _map[y][x].setVal(22);
	  break;
	}
      return 0;
    }
  _map[y][x].setVal(val);
  return 0;
}


void IS::Map::checkPlayer(std::map<int,IS::IPlayer*> players)
{
  //std::cout << "Map::checkExplosionDamage(player)" << std::endl;
  for (unsigned int i = 1; i < 5; ++i)
    if ((players[i]) && (players[i]->isLiving()))
      {
	if (_map[players[i]->getY()][players[i]->getX()].isExplosion())
	  players[i]->takeDamage();
	for (unsigned int j = 0; j < _entities.size(); ++j)
	  if ((players[i]->getX() == _entities[j]->getX()) && (players[i]->getY() == _entities[j]->getY()))
	    _entities[j]->pickedUp(players[i]);
      }
}

void IS::Map::checkEntities()
{
  //std::cout << "Map::checkEntities() = " << _entities.size() << std::endl;
  for (unsigned int i = 0; i < _entities.size(); ++i)
    {
      if (_map[_entities[i]->getY()][_entities[i]->getX()].isExplosion())
	_entities[i]->takeDamage();
      if (_entities[i]->isUsed())
	_entities.erase(_entities.begin() + i);
    }
}

void IS::Map::create(const int& id_bg, const int& id_map)
{
  //std::cout << "Map::create(int " << id_bg << " ,int " << id_map << ")" << std::endl;

  std::string bg_file = "assets/bg/map_bg_" + std::to_string(id_bg) + ".png";
  std::string sprite_sheet_file = "assets/sprites/sprite_sheet_" + std::to_string(id_bg) + ".png";

  _tex_map_bg.loadFromFile(bg_file);
  _map_bg.setTexture(_tex_map_bg);
  _map_bg.setPosition(416, 0);

  _tex_sprite_sheet.loadFromFile(sprite_sheet_file);
  _sprite_sheet.setTexture(_tex_sprite_sheet);
  _sprite_sheet.setTextureRect(sf::IntRect(0,0,64,64));

  std::string map_file = "maps/map_" + std::to_string(id_map) + ".csv";
  std::ifstream map_stream(map_file);
  if (!(map_stream.is_open()))
    throw new std::invalid_argument("map file doesn't exists");
  std::string line("");

  int y = 0;
  while (std::getline(map_stream, line))
    {
      std::stringstream lineStream(line);
      std::string cell_val;
      std::vector<IS::Cell> row;

      int x = 0;
      while (std::getline(lineStream, cell_val, ','))
	{
	  IS::Cell cell(std::stoi(cell_val), x, y);
	  row.push_back(cell);
	  ++x;
	}
      _map.push_back(row);
      ++y;
    }
}

void IS::Map::draw(sf::RenderWindow& _win)
{
  //std::cout << "Map::draw(_win)" << std::endl;

  _win.draw(_map_bg);
  for (unsigned int i = 0; i < _entities.size(); ++i)
    if (!(_entities[i]->isUsed()))
      _entities[i]->draw(_win);
  for (size_t y = 0; y < _map.size(); ++y)
    for (size_t x = 0; x < _map[y].size(); ++x)
      if (_map[y][x].isDrawable())
	{
	  _sprite_sheet.setTextureRect(sf::IntRect(((_map[y][x].getVal()) % 8) * 64, ((_map[y][x].getVal()) / 8) * 64, 64, 64));
	  _sprite_sheet.setPosition((64 * x) + 416, (64 * y));
	  _win.draw(_sprite_sheet);
	}
}


void IS::Map::debug()
{
  for (size_t y = 0; y < _map.size(); ++y)
    {
      for (size_t x = 0; x < _map[y].size(); ++x)
	std::cout << _map[y][x].getVal() << "\t";
      std::cout << std::endl;
    }
  std::cout << std::endl;
}
