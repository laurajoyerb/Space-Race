#include <iostream>
#include "Alien.h"
#include <math.h>

using namespace std;

Alien::Alien() : Game_Object('X')
{
  attack_strength = 2;
  range = 2.0;
  target = NULL;
  speed = 5;
  cout << "Default Alien constructed" << endl;
}

Alien::Alien(int in_id, Cart_Point in_loc) : Game_Object(in_loc, in_id, 'X')
{
  attack_strength = 2;
  range = 2.0;
  target = NULL;
  speed = 5;
  cout << "Alien constructed" << endl;
}

void Alien::start_attack(Person* in_target)
{
  Cart_Point AlienLoc = get_location();
  Cart_Point AstroLoc = in_target -> get_location();
  double dist = cart_distance(AlienLoc, AstroLoc);

  if (dist <= range)
  {
    cout << display_code << id_num << ": Smash!" << endl;
    target = in_target;
    state = 'a';
  }
  else
  {
    cout << display_code << id_num << ": Target is out of range" << endl;
  }
}

bool Alien::update()
{
  bool arrive;
  switch(state)
  {
    case 's':
    {
      return false;
    }
    case 'm':
    {
      arrive = Alien::update_location(); // updates location of moving alien and advances one step
      if (arrive) // once it arrives, the state changes to stopped
      {
        state = 's';
        return true;
      }
      else
      {
        return false;
      }
    }
    case 'a':
    {
      Cart_Point AlienLoc = get_location();
      Cart_Point AstroLoc = target -> get_location();
      double dist = cart_distance(AlienLoc, AstroLoc);
      if (dist > range)
      {
        cout << display_code << id_num << ": Target is out of range" << endl;
        cout << display_code << id_num << ": Chaaaaarge." << endl;
        state = 's';
        return true;
      }
      else
      {
        if (target -> is_alive())
        {
          cout << display_code << id_num << ": Take that!" << endl;
          target -> take_hit(attack_strength);
          return false;
        }
        else
        {
          cout << display_code << id_num << ": I triumph!" << endl;
          state = 's';
          return true;
        }
      }
    }
    default:
    {
      cout << "Something messed up!" << endl;
      return false;
    }
  }
}

void Alien::show_status()
{
  cout << "Alien status: ";
  Game_Object::show_status(); // prints info like location and display code and id
  switch (state)
  {
    case 'm':
      cout << " moving at speed " << speed << " to " << destination << " at each step of " << delta << endl;
      break;
    case 's':
      cout << " is stopped." << endl;
      break;
    case 'a':
      cout << " attacking astronaut " << target -> get_id() << endl;
      break;
  }
}


void Alien::start_moving(Cart_Point dest)
{
  if (dest.x == location.x && dest.y == location.y) // If already at location, nothing happens besides an "error" message
  {
    cout << "I'm already there. see?" << endl;
  }
  else
  {
    setup_destination(dest);
    state = 'm';
    cout << "Moving " << id_num << " to " << dest << endl;
    cout << display_code << id_num << ": On my way." << endl;
  }
}

void Alien::stop()
{
  state = 's';
  cout << display_code << id_num << ": Stopped." << endl;
}

bool Alien::update_location()
{
  Cart_Vector newdist = destination - location;
  newdist.x = fabs(newdist.x);
  newdist.y = fabs(newdist.y); // fabs gets distance from destination

  if (newdist.x <= fabs(delta.x) && newdist.y <= fabs(delta.y)) // if distance is less than delta, you have arrived!
  {
    location = destination;
    cout << display_code << id_num << ": I'm there!" << endl;
    return true;
  }
  else
  { // otherwise, add delta and continue
    location = location + delta;
    cout << display_code << id_num << ": step..." << endl;
    return false;
  }
}

void Alien::setup_destination(Cart_Point dest)
{
  destination = dest;
  Cart_Vector cv = destination - location;
  delta = cv / ((cart_distance(destination, location) / speed)); // different formula from document, still works though I promise
}
