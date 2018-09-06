
#include "indieStudio.hpp"

int main()
{
  try
    {
      IS::IGame* game = new IS::Bomberman();
      game->start();
    }
  catch (std::exception *e)
    {
      std::cerr << e->what() << std::endl;
      return 84;
    }
  return 0;
}
