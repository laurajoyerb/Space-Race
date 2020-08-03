#include <iostream>
#include "Model.h"

using namespace std;

Model::Model()
{
  time = 0;
  count_down = 10;

  num_objects = 6;
  num_persons = 2;
  num_depots = 2;
  num_station = 2;

  Cart_Point pt1 = Cart_Point(5,1);
  Cart_Point pt2 = Cart_Point(10,1);
  Cart_Point pt3 = Cart_Point(1,20);
  Cart_Point pt4 = Cart_Point(10,20);
  Cart_Point pt5 = Cart_Point(5,5);

  Astronaut* ptrA1 = new Astronaut(1,pt1);
  Astronaut* ptrA2 = new Astronaut(2, pt2);

  Oxygen_Depot* ptrD1 = new Oxygen_Depot(pt3, 1);
  Oxygen_Depot* ptrD2 = new Oxygen_Depot(pt4, 2);

  Space_Station* ptrS1 = new Space_Station();
  Space_Station* ptrS2 = new Space_Station(pt5, 2);

  object_ptrs[0] = ptrA1;
  object_ptrs[1] = ptrA2;
  object_ptrs[2] = ptrD1;
  object_ptrs[3] = ptrD2;
  object_ptrs[4] = ptrS1;
  object_ptrs[5] = ptrS2;

  person_ptrs[0] = ptrA1;
  person_ptrs[1] = ptrA2;

  depot_ptrs[0] = ptrD1;
  depot_ptrs[1] = ptrD2;

  station_ptrs[0] = ptrS1;
  station_ptrs[1] = ptrS2;

  cout << "Model default constructed" << endl;
}

Model::~Model()
{
  for (int i = 0; i < num_objects; i++)
  {
    delete object_ptrs[i]; // object_ptrs holds all ptrs, so only this must be deleted (not other pointer arrays like person_ptrs)
  }
  cout << "Model destructed." << endl;
}

Person* Model::get_Person_ptr(int id)
{
  for (int i = 0; i < num_persons; i++)
  {
    if(person_ptrs[i] -> get_id() == id)
    {
      return person_ptrs[i];
    }
  }
  return 0;
}

Oxygen_Depot* Model::get_Oxygen_Depot_ptr(int id)
{
  for (int i = 0; i < num_depots; i++)
  {
    if(depot_ptrs[i] -> get_id() == id)
    {
      return depot_ptrs[i];
    }
  }
  return 0;
}

Space_Station* Model::get_Space_Station_ptr(int id)
{
  for (int i = 0; i < num_station; i++)
  {
    if(station_ptrs[i] -> get_id() == id)
    {
      return station_ptrs[i];
    }
  }
  return 0;
}

bool Model::update()
{
  time++; // Increments time always

  bool upgraded = true; // Checks if ALL stations are upgraded

  for (int i = 0; i < num_station && upgraded; i++)
  {
    if (station_ptrs[i] -> get_state() == 'u') continue; // if ALL stations are upgraded, bool remains true
    else
    {
      upgraded = false; // if ANY station is not upgraded, this bool is set to false and for loop stops
    }
  }

  bool atStation = true; // Checks that all astronauts are at a station
  bool tempStation = false; // Temporary check used for atStation
  for (int i = 0; i < num_persons && atStation; i++)
  {
    for (int j = 0; j < num_station && atStation; j++)
    {
      // Each person loops through each station before looping to next person
      Cart_Point personloc = person_ptrs[i] -> get_location();
      Cart_Point stationloc = station_ptrs[j] -> get_location();

      if((personloc.x == stationloc.x) && (personloc.y == stationloc.y) && (person_ptrs[i] -> get_state() == 'l'))
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
  for (int i = 0; i < num_station; i++)
  {
    if (station_ptrs[i] -> get_astronauts() >= 1) continue;
    else
    {
      allAstro = false; // if ANY station does not have at least one astronaut, allAstro is false
      missing++; // increments to show that aother station is missing an astronaut
    }
  }

  bool check = false; // return value for whole update function

  if(!upgraded) // Case 1: Space Stations are not upgraded yet
  { // Executes "normally"; all objects are updated, and if any update function returns true, Model::update returns true as well
    bool temp;
    for (int i = 0; i < num_objects; i++)
    {
      temp = object_ptrs[i] -> update();
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
    for (int i = 0; i < num_objects; i++)
    {
      temp = object_ptrs[i] -> update();
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
  for (int i = 0; i < num_objects; i++)
  {
    object_ptrs[i] -> show_status();
  }
}

void Model::display(View& view)
{
  view.clear();

  for (int i = 0; i < num_objects; i++)
  {
    view.plot(object_ptrs[i]); // plots each object on display
  }

  view.draw();
}
