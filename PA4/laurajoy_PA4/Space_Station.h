#ifndef SPACE_STATION
#define SPACE_STATION

#include "Game_Object.h"

class Space_Station : public Game_Object
{
private:
  double amount_moonstones;
  int number_astronauts;

public:
  Space_Station();
  Space_Station(Cart_Point, int);
  ~Space_Station();

  void deposit_moonstones(double);
  bool add_astronaut();
  int get_astronauts();
  bool update();
  void show_status();
};

#endif
