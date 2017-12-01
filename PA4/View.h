#ifndef VIEW
#define VIEW

#include "Astronaut.h"
#include "Alien.h"

const int view_maxsize = 20;

class View
{
private:
  int size;
  double scale;
  Cart_Point origin;
  char grid[view_maxsize][view_maxsize][2];
  bool get_subscripts(int &ix, int &iy, Cart_Point location);

public:
  View();
  void clear();
  void plot(Game_Object* ptr);
  void draw();
};

#endif
