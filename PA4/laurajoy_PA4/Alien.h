// EXTRA CREDIT STEP 7: Aliens now can be attacked by astronauts; they can also be computer-controlled; their speed changes with gravity

#ifndef ALIEN
#define ALIEN

#include "Game_Object.h"
#include "Person.h"

class Person; // EXTRA CREDIT: forward declaration of Person class
class Alien : public Game_Object
{
private:
  int attack_strength;
  Person* target;
  Cart_Point destination;
  Cart_Vector delta;
  double speed;
  double range;
  int health; // EXTRA CREDIT: added member variable health so now aliens can be killed by astronauts

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

  // EXTRA CREDIT: Added "victim" functions to Alien so it can be attacked
  bool is_alive();
  void take_hit(int Pattack_strength);

  // EXTRA CREDIT: Added getters for speed and range
  double get_speed();
  double get_range();
  void change_speed(double in_speed);

  // EXTRA CREDIT: Tracks whether game is running with computer-controlled aliens or user-controlled
  bool compMode;
};

#endif
