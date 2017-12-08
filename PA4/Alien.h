#ifndef ALIEN
#define ALIEN

#include "Game_Object.h"
#include "Person.h"


class Alien : public Game_Object
{
private:
  int attack_strength;
  Person* target;
  Cart_Point destination;
  Cart_Vector delta;
  double speed;
  double range;

public:
  Alien();
  Alien(int in_id, Cart_Point in_loc);
  void start_attack(Person* in_target);
  bool update();
  void show_status();
  void start_moving(Cart_Point);
  void stop();
  bool update_location();
  void setup_destination(Cart_Point);

  double get_speed();
  double get_range();
  void change_speed(double in_speed);
  bool compMode;
};

#endif
