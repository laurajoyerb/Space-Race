#include <iostream>
#include "Model.h"

using namespace std;

Model::Model()
{
  time = 0;
  count_down = 10;

  alive = 2;

  Cart_Point pt1 = Cart_Point(5,1);
  Cart_Point pt2 = Cart_Point(10,1);
  Cart_Point pt3 = Cart_Point(1,20);
  Cart_Point pt4 = Cart_Point(10,20);
  Cart_Point pt5 = Cart_Point(5,5);
  Cart_Point pt6 = Cart_Point(7,14);
  Cart_Point pt7 = Cart_Point(7, 5);

  Astronaut* ptrA1 = new Astronaut(1,pt1);
  Astronaut* ptrA2 = new Astronaut(2, pt2);

  Alien* ptrX1 = new Alien(1, pt6);
  Alien* ptrX2 = new Alien(2, pt7);

  Oxygen_Depot* ptrD1 = new Oxygen_Depot(pt3, 1);
  Oxygen_Depot* ptrD2 = new Oxygen_Depot(pt4, 2);

  Space_Station* ptrS1 = new Space_Station();
  Space_Station* ptrS2 = new Space_Station(pt5, 2);

  object_ptrs.push_back(ptrA1);
  object_ptrs.push_back(ptrA2);
  object_ptrs.push_back(ptrD1);
  object_ptrs.push_back(ptrD2);
  object_ptrs.push_back(ptrS1);
  object_ptrs.push_back(ptrS2);
  object_ptrs.push_back(ptrX1);
  object_ptrs.push_back(ptrX2);

  active_ptrs.push_back(ptrA1);
  active_ptrs.push_back(ptrA2);
  active_ptrs.push_back(ptrD1);
  active_ptrs.push_back(ptrD2);
  active_ptrs.push_back(ptrS1);
  active_ptrs.push_back(ptrS2);
  active_ptrs.push_back(ptrX1);
  active_ptrs.push_back(ptrX2);

  person_ptrs.push_back(ptrA1);
  person_ptrs.push_back(ptrA2);

  depot_ptrs.push_back(ptrD1);
  depot_ptrs.push_back(ptrD2);

  station_ptrs.push_back(ptrS1);
  station_ptrs.push_back(ptrS2);

  alien_ptrs.push_back(ptrX1);
  alien_ptrs.push_back(ptrX2);

  cout << "Model default constructed" << endl;
}

Model::~Model()
{
  for (list <Game_Object*>::iterator it = object_ptrs.begin(); it != object_ptrs.end(); ++it)
  {
    delete *it; // object_ptrs holds all ptrs, so only this must be deleted (not other pointer arrays like person_ptrs)
  }
  cout << "Model destructed." << endl;
}

Person* Model::get_Person_ptr(int id)
{
  for (list <Person*>::iterator it = person_ptrs.begin(); it != person_ptrs.end(); ++it)
  {
    if((*it) -> get_id() == id)
    {
      return *it;
    }
  }
  return 0;
}

Alien* Model::get_Alien_ptr(int id)
{
  for (list <Alien*>::iterator it = alien_ptrs.begin(); it != alien_ptrs.end(); ++it)
  {
    if((*it) -> get_id() == id)
    {
      return *it;
    }
  }
  return 0;
}

Oxygen_Depot* Model::get_Oxygen_Depot_ptr(int id)
{
  for (list <Oxygen_Depot*>::iterator it = depot_ptrs.begin(); it != depot_ptrs.end(); ++it)
  {
    if((*it) -> get_id() == id)
    {
      return *it;
    }
  }
  return 0;
}

Space_Station* Model::get_Space_Station_ptr(int id)
{
  for (list <Space_Station*>::iterator it = station_ptrs.begin(); it != station_ptrs.end(); ++it)
  {
    if((*it) -> get_id() == id)
    {
      return *it;
    }
  }
  return 0;
}

bool Model::update()
{
  time++; // Increments time always

  alive = 0;

  for (list <Game_Object*>::iterator it = active_ptrs.begin(); it != active_ptrs.end(); ++it)
  {
    if ((*it) -> get_state() == 'x')
    {
      active_ptrs.erase(it);
    }
  }

  for (list <Person*>::iterator it = person_ptrs.begin(); it != person_ptrs.end(); ++it)
  {
    if ((*it) -> is_alive())
    {
      alive++;
    }
  }

  bool upgraded = true; // Checks if ALL stations are upgraded

  for (list <Space_Station*>::iterator it = station_ptrs.begin(); it != station_ptrs.end() && upgraded; ++it)
  {
    if ((*it) -> get_state() != 'u') // if ALL stations are upgraded, bool remains true
    {
      upgraded = false; // if ANY station is not upgraded, this bool is set to false and for loop stops
    }
  }

  bool atStation = true; // Checks that all astronauts are at a station
  bool tempStation = false; // Temporary check used for atStation
  for (list <Person*>::iterator it = person_ptrs.begin(); it != person_ptrs.end(); ++it)
  {
    for (list <Space_Station*>::iterator it2 = station_ptrs.begin(); it2 != station_ptrs.end() && atStation; ++it2)
    {
      // Each person loops through each station before looping to next person
      Cart_Point personloc = (*it) -> get_location();
      Cart_Point stationloc = (*it2) -> get_location();

      if((personloc.x == stationloc.x) && (personloc.y == stationloc.y) && ((*it) -> get_state() == 'l'))
      {
        tempStation = true; // if astronaut is at same location as the station AND is locked there, temp is set to true
      } // If the astronaut is not at any of the station locations, temp stays false
    }
    if (!tempStation) // if temp is false (one or more astronauts are not at a station), atStation is false
    {
      atStation = false;
    }
    // If after looping through every person temp is never false, then atStation remains true
  }

  bool allAstro = true; // Checks that every station has at least one astronaut
  int missing = 0; // Counts number of astronauts that are missing (as in how many space stations are missing an astronaut)
  for (list <Space_Station*>::iterator it = station_ptrs.begin(); it != station_ptrs.end(); ++it)
  {
    if ((*it) -> get_astronauts() < 1)
    {
      allAstro = false; // if ANY station does not have at least one astronaut, allAstro is false
      missing++; // increments to show that aother station is missing an astronaut
    }
  }

  bool check = false; // return value for whole update function

  if(!upgraded) // Case 1: Space Stations are not upgraded yet
  { // Executes "normally"; all objects are updated, and if any update function returns true, Model::update returns true as well
    bool temp;
    for (list <Game_Object*>::iterator it = active_ptrs.begin(); it != active_ptrs.end(); ++it)
    {
      temp = (*it) -> update();
      if (temp)
      {
        check = true;
      }
    }
  }
  else if (!allAstro || !atStation || missing) // Case 2: Stations are upgraded, but astronauts are not in the right places yet
  {
    cout << "Ready for takeoff? " << count_down << "..." << endl;
    cout << "Missing " << missing << " astronauts!" << endl;
    count_down--; // countdown begins

    if (count_down <= 0) // If take off happened / count down ended, you lose
    {
      cout << "Unmanned takeoff...you lose!" << endl;
      exit(0);
    }

    // Updates all objects because astronauts are still moving around!
    bool temp;
    for (list <Game_Object*>::iterator it = active_ptrs.begin(); it != active_ptrs.end(); ++it)
    {
      temp = (*it) -> update();
      if (temp)
      {
        check = true;
      }
    }
  }
  else // Case 3: Everything is upgraded, in place, and ready for takeoff before the end of countdown --> You win!
  {
    cout << "Ready for takeoff? " << count_down << "..." << endl;
    cout << "Blast Off! You Win!" << endl;
    exit(0);
  }

  return check;
}

void Model::show_status()
{
  cout << "Time: " << time << endl;
  for (list <Game_Object*>::iterator it = object_ptrs.begin(); it != object_ptrs.end(); ++it)
  {
    (*it) -> show_status();
  }
}

void Model::display(View& view)
{
  view.clear();

  for (list <Game_Object*>::iterator it = active_ptrs.begin(); it != active_ptrs.end(); ++it)
  {
      view.plot((*it)); // plots each object on display
  }

  view.draw();
}
