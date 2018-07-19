// EXTRA CREDIT STEP 7: Astronauts now attack aliens; game can implement computer-controlled aliens

#ifndef MODEL
#define MODEL

#include "View.h"
#include "Alien.h"
#include "Input_Handling.h"
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class Model
{
private:
  Model(const Model& m); // private copy constructor so it cannot be used

  int timer;
  int count_down;
  int alive; // tracks how many astronauts are alive

  // Lists instead of arrays
  list <Game_Object*> object_ptrs;
  list <Game_Object*> active_ptrs;
  list <Person*> person_ptrs;
  list <Alien*> alien_ptrs;
  list <Oxygen_Depot*> depot_ptrs;
  list <Space_Station*> station_ptrs;

public:
  Model();
  ~Model();

  Person* get_Person_ptr(int id);
  Alien* get_Alien_ptr(int id);
  Oxygen_Depot* get_Oxygen_Depot_ptr(int id);
  Space_Station * get_Space_Station_ptr(int id);
  bool update();
  void display(View &view);
  void show_status();

  void handle_new_command();

  bool compMode; // Tracks whether or not the program aliens are run by the computer or by the user
};

#endif
