#ifndef PERSON
#define PERSON

#include "Space_Station.h"
#include "Oxygen_Depot.h"
#include "Alien.h"
#include <stdio.h>
#include <ctype.h>

class Alien; // Forward declaration of Alien class
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

  double get_speed();
  Cart_Point get_destination(); // EXTRA CREDIT: added getter for alien chase
  void change_speed(double in_speed); // EXTRA CREDIT: change speed due to gravity changes

  void start_attack(Alien* in_target); // EXTRA CREDIT: Astronaut can now attack

protected:
  bool update_location();
  void setup_destination(Cart_Point);
  double speed;
  double range; // EXTRA CREDIT: Astronaut fights back
  double attack_strength; // EXTRA CREDIT
  Alien* target; // EXTRA CREDIT
  int health;

private:
  Cart_Point destination;
  Cart_Vector delta;
};

#endif
