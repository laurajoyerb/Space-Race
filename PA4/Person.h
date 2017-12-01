#ifndef PERSON
#define PERSON

#include "Space_Station.h"
#include "Oxygen_Depot.h"
#include <stdio.h>
#include <ctype.h>

class Person : public Game_Object
{
public:
  Person();
  Person (char);
  Person(Cart_Point, int, char);
  virtual ~Person();

  void start_moving(Cart_Point);
  void stop();
  void show_status();
  bool is_alive();
  void take_hit(int attack_strength);

  virtual void start_supplying(Oxygen_Depot*);
  virtual void start_depositing(Space_Station*);
  virtual void go_to_station(Space_Station*);

protected:
  bool update_location();
  void setup_destination(Cart_Point);

  int health;

private:
  double speed;
  Cart_Point destination;
  Cart_Vector delta;
};

#endif
