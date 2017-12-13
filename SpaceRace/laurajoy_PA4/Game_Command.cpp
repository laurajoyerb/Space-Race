#include <iostream>
#include "Game_Command.h"

using namespace std;

void do_move_command(Model& model)
{
  int id;
  double x, y;
  char ax;

  cin >> id >> x >> y;
  if (cin.fail())
  {
    throw Invalid_Input("Please enter a command (char), an id number (int), and an x and y coordinate (int).");
  }

  Cart_Point pt = Cart_Point(x,y);

  if(model.compMode)
  {
    ax = 'a'; // If computer-control is on, then the user can only command astronauts to move
  }
  else
  {
    cout << "Move Astronaut (enter 'a') or Alien (enter 'x'): ";
    cin >> ax;

    if(ax != 'x' && ax != 'a')
    {
      throw Invalid_Input("You must enter an 'a' for an Astronaut or an 'x' for an Alien");
    }
  }

  if (ax == 'a')
  {
    Person* p = model.get_Person_ptr(id);
    if (p == 0)
    {
      throw Invalid_Input("Invalid ID number.");
    }
    p -> start_moving(pt);
  }
  else if (ax == 'x')
  {
    Alien* x = model.get_Alien_ptr(id);
    if (x == 0)
    {
      throw Invalid_Input("Invalid ID number.");
    }
    x -> start_moving(pt);
  }
}

void do_work_command(Model& model)
{
  int id1, id2;

  cin >> id1 >> id2;
  if (cin.fail())
  {
    throw Invalid_Input("Please enter an integer for ID number.");
  }

  Person* p = model.get_Person_ptr(id1);
  if (p == 0)
  {
    throw Invalid_Input("Invalid ID number.");
  }

  Oxygen_Depot* od = model.get_Oxygen_Depot_ptr(id2);
  if (od == 0)
  {
    throw Invalid_Input("Invalid ID number.");
  }

  p -> start_supplying(od);
}

void do_deposit_command(Model& model)
{
  int id1, id2;

  cin >> id1 >> id2;
  if (cin.fail())
  {
    throw Invalid_Input("Please enter an integer for ID number.");
  }

  Person* p = model.get_Person_ptr(id1);
  if (p == 0)
  {
    throw Invalid_Input("Invalid ID number.");
  }

  Space_Station* ss = model.get_Space_Station_ptr(id2);
  if (ss == 0)
  {
    throw Invalid_Input("Invalid ID number.");
  }

  p -> start_depositing(ss);
}

void do_stop_command(Model& model)
{
  int id;
  char ax;

  cin >> id;
  if (cin.fail())
  {
    throw Invalid_Input("Please enter an integer for ID number.");
  }

  if(model.compMode) // If computer-control is on, then the user can only command astronauts to move
  {
    ax = 'a';
  }
  else
  {
    cout << "Stop Astronaut (enter 'a') or Alien (enter 'x'): ";
    cin >> ax;

    if(ax != 'x' && ax != 'a')
    {
      throw Invalid_Input("You must enter an 'a' for an Astronaut or an 'x' for an Alien");
    }
  }

  if (ax == 'a')
  {
    Person* p = model.get_Person_ptr(id);
    if (p == 0)
    {
      throw Invalid_Input("Invalid ID number.");
    }
    p -> stop();
  }
  else if (ax == 'x')
  {
    Alien* x = model.get_Alien_ptr(id);
    if (x == 0)
    {
      throw Invalid_Input("Invalid ID number.");
    }
    x -> stop();
  }
}

void do_lock_command(Model& model)
{
  int id1, id2;

  cin >> id1 >> id2;
  if (cin.fail())
  {
    throw Invalid_Input("Please enter an integer for ID number.");
  }

  Person* p = model.get_Person_ptr(id1);
  if (p == 0)
  {
    throw Invalid_Input("Invalid ID number.");
  }

  Space_Station* ss = model.get_Space_Station_ptr(id2);
  if (ss == 0)
  {
    throw Invalid_Input("Invalid ID number.");
  }

  p -> go_to_station(ss);
}

void do_go_command(Model& model)
{
  cout << "Advancing one tick." << endl;
  model.update();
  model.show_status();
}

void do_run_command(Model& model)
{
  cout << "Advancing to next event." << endl;
  bool var = model.update(); // calls update at least once
  int counter = 0;
  while (!var && counter < 4) // allows this loop to run 4 times because 5th time is outside of loop
  {
    var = model.update();
    counter++;
  }
  model.show_status();
}

void do_attack_command(Model& model)
{
  int id1, id2;
  char ax;

  cin >> id1 >> id2;
  if (cin.fail())
  {
    throw Invalid_Input("Please enter an integer for ID number.");
  }

  if(model.compMode) // If computer-control is on, then the user can only command astronauts to move
  {
    ax = 'a';
  }
  else
  {
    cout << "Astronaut attacker (enter 'a') or Alien attacker (enter 'x'): ";
    cin >> ax;

    if(ax != 'x' && ax != 'a')
    {
      throw Invalid_Input("You must enter an 'a' for an Astronaut or an 'x' for an Alien");
    }
  }

  if(ax == 'a')
  {
    // If input is 'a', then the first id is for the astronaut, and the second id is for the alien
    Person* p = model.get_Person_ptr(id1);
    if (p == 0)
    {
      throw Invalid_Input("Invalid ID number.");
    }

    Alien* x = model.get_Alien_ptr(id2);
    if (x == 0)
    {
      throw Invalid_Input("Invalid ID number.");
    }

    p -> start_attack(x); // EXTRA CREDIT: Person attacks alien
  }
  else
  {
    Person* p = model.get_Person_ptr(id2);
    if (p == 0)
    {
      throw Invalid_Input("Invalid ID number.");
    }

    Alien* x = model.get_Alien_ptr(id1);
    if (x == 0)
    {
      throw Invalid_Input("Invalid ID number.");
    }

    x -> start_attack(p);
  }
}

void do_new_command(Model& model)
{
  model.handle_new_command();
}

void do_quit_command(Model& model)
{
  cout << "Terminating program." << endl;
  model.~Model();
  exit(0);
}
