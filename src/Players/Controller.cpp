//
// Controller.cpp for Controller in /home/myallaen/Work/epitech/CPP/cpp_indie_studio
//
// Made by myallaen
// Login   <myallaen@epitech.eu>
//
// Started on  Wed Jun 14 22:47:10 2017 myallaen
// Last update Sun Jun 18 13:35:43 2017 myallaen
//

#include "Players/Controller.hpp"

IS::Controller::Controller()
{}

IS::Controller::Controller(const unsigned int& id)
{
  switch (id)
    {
    case 1:
      _up = sf::Keyboard::W;
      _down = sf::Keyboard::S;
      _left = sf::Keyboard::A;
      _right = sf::Keyboard::D;
      _act1 = sf::Keyboard::Q;
      _act2 = sf::Keyboard::E;
      break;
    case 2:
      _up = sf::Keyboard::Y;
      _down = sf::Keyboard::H;
      _left = sf::Keyboard::G;
      _right = sf::Keyboard::J;
      _act1 = sf::Keyboard::T;
      _act2 = sf::Keyboard::U;
      break;
    case 3:
      _up = sf::Keyboard::P;
      _down = sf::Keyboard::SemiColon;
      _left = sf::Keyboard::L;
      _right = sf::Keyboard::Quote;
      _act1 = sf::Keyboard::O;
      _act2 = sf::Keyboard::LBracket;
      break;
    case 4:
      _up = sf::Keyboard::Up;
      _down = sf::Keyboard::Down;
      _left = sf::Keyboard::Left;
      _right = sf::Keyboard::Right;
      _act1 = sf::Keyboard::RControl;
      _act2 = sf::Keyboard::RShift;
      break;
    default:
      break;
    }
}

IS::Controller::~Controller()
{}

const sf::Keyboard::Key& IS::Controller::getUp() const
{
  return _up;
}

const sf::Keyboard::Key& IS::Controller::getDown() const
{
  return _down;
}

const sf::Keyboard::Key& IS::Controller::getLeft() const
{
  return _left;
}

const sf::Keyboard::Key& IS::Controller::getRight() const
{
  return _right;
}

const sf::Keyboard::Key& IS::Controller::getAct1() const
{
  return _act1;
}

const sf::Keyboard::Key& IS::Controller::getAct2() const
{
  return _act2;
}

void IS::Controller::setUp(const sf::Keyboard::Key& up)
{
  _up = up;
  return;
}

void IS::Controller::setDown(const sf::Keyboard::Key& down)
{
  _down = down;
  return;
}

void IS::Controller::setLeft(const sf::Keyboard::Key& left)
{
  _left = left;
  return;
}

void IS::Controller::setRight(const sf::Keyboard::Key& right)
{
  _right = right;
  return;
}

void IS::Controller::setAct1(const sf::Keyboard::Key& act1)
{
  _act1 = act1;
  return;
}

void IS::Controller::setAct2(const sf::Keyboard::Key& act2)
{
  _act2 = act2;
  return;
}
