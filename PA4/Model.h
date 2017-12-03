#ifndef MODEL
#define MODEL

#include "View.h"
#include "Alien.h"
#include <stdio.h>
#include <stdlib.h>

class Model
{
private:
  Model(const Model& m); // private copy constructor so it cannot be used

  int time;
  int count_down;
  int alive; // tracks how many astronauts are alive

  Game_Object* object_ptrs[10];
  int num_objects;
  Person* person_ptrs[10];
  int num_persons;
  Alien* alien_ptrs[10];
  int num_aliens;
  Oxygen_Depot* depot_ptrs[10];
  int num_depots;
  Space_Station* station_ptrs[10];
  int num_station;

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
};

#endif
