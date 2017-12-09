#include <iostream>
#include "Alien.h"
#include <math.h>

using namespace std;

Alien::Alien() : Game_Object('X')
{
  attack_strength = 2;
  range = 2.0;
  health = 5.0; // EXTRA CREDIT
  target = NULL;
  speed = 5;
  cout << "Default Alien constructed" << endl;
}

Alien::Alien(int in_id, Cart_Point in_loc) : Game_Object(in_loc, in_id, 'X')
{
  attack_strength = 2;
  range = 2.0;
  health = 5.0; // EXTRA CREDIT
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
    if (state == 'a') // If already in attack mode, the code executes without an interruption in attacking; ie. still calls take_hit() and attacks alien
    {
      cout << display_code << id_num << ": Take that!" << endl;
      in_target -> take_hit(attack_strength);
    }
    else
    {
      cout << display_code << id_num << ": Smash!" << endl; // First start_attack does not actually cause damage to astronaut
      target = in_target;
      state = 'a';
    }
  }

  if (!compMode && dist > range) // If in computer-controlled mode, no output is necessary
  {
    cout << display_code << id_num << ": Target is out of range" << endl;
  }
}

bool Alien::update()
{
  bool arrive;
  if (state == 'x') // EXTRA CREDIT
  {
    return false;
  }
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
        if(!compMode) // Only prints for user commands to alien
        {
          cout << display_code << id_num << ": Target is out of range" << endl;
        }
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
          cout << display_code << id_num << ": I win." << endl;
          state = 's';
          return true;
        }
      }
    }
    default:
    {
      cout << "Something messed up!" << endl; // Should never execute!
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
      cout << " attacking astronaut A" << target -> get_id() << endl;
      break;
    case 'x': // EXTRA CREDIT
      cout << " is dead." << endl;
  }
}

void Alien::start_moving(Cart_Point dest)
{
  if (state == 'x' && !compMode) // EXTRA CREDIT
  {
    cout << "I can't move, I'm dead." << endl;
  }
  else
  {
    if (dest.x == location.x && dest.y == location.y && !compMode) // If already at location, nothing happens besides an "error" message
    {
      cout << "I'm already there. see?" << endl;
    }
    else
    {
      setup_destination(dest);
      state = 'm';
      if (!compMode) // Response for user commands
      {
        cout << "Moving " << id_num << " to " << dest << endl;
        cout << display_code << id_num << ": On my way." << endl;
      }
    }
  }
}

void Alien::stop()
{
  if (state == 'x' && !compMode) // EXTRA CREDIT
  {
    cout << "I can't move, I'm dead." << endl;
  }
  else if (!compMode)
  {
    state = 's';
    cout << display_code << id_num << ": Stopped." << endl;
  }
}

bool Alien::update_location()
{
  setup_destination(destination);
  if(delta.x == 0 && delta.y == 0) // This means you are there!
  {
    return true;
  }
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

bool Alien::is_alive() // EXTRA CREDIT
{
  if (state == 'x')
    return false;
  else
    return true;
}

void Alien::take_hit(int Pattack_strength) // EXTRA CREDIT: Aliens can be damaged now
{
  health -= Pattack_strength;
  if (health <= 0)
  {
    cout << display_code << id_num << ": Gasp! I'm dying..." << endl;
    state = 'x';
  }
  else if (health < 3) // Same protocol as with Person
  {
    display_code = tolower(display_code);
    cout << display_code << id_num << ": Ouch!" << endl;
  }
  else
  {
    cout << display_code << id_num << ": Ouch!" << endl;
  }
}


double Alien::get_speed() // EXTRA CREDIT
{
  return speed;
}

double Alien::get_range() // EXTRA CREDIT
{
  return range;
}

void Alien::change_speed(double in_speed) // EXTRA CREDIT
{
  speed = in_speed;
}
