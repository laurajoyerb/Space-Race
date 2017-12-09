#include <iostream>
#include "Person.h"
#include <math.h>

using namespace std;

Person::Person() : Game_Object('x')
{
  speed = 5;
  health = 5;
  attack_strength = 2; // EXTRA CREDIT
  range = 2.0; // EXTRA CREDIT
  target = NULL; // EXTRA CREDIT
  cout << "Person default constructed." << endl;
}

Person::Person(char in_code) : Game_Object(in_code)
{
  speed = 5;
  health = 5;
  range = 2.0; // EXTRA CREDIT
  attack_strength = 2; // EXTRA CREDIT
  target = NULL; // EXTRA CREDIT
  state = 's';
  cout << "Person constructed." << endl;
}

Person::Person(Cart_Point in_loc, int in_id, char in_code) : Game_Object(in_loc, in_id, in_code)
{
  speed = 5;
  health = 5;
  range = 2.0; // EXTRA CREDIT
  attack_strength = 2;// EXTRA CREDIT
  target = NULL; // EXTRA CREDIT
  cout << "Person constructed." << endl;
}

Person::~Person()
{
  cout << "Person destructed." << endl;
}

void Person::start_moving(Cart_Point dest)
{
  if (state == 'x')
  {
    cout << "I can't move, I'm dead." << endl;
  }
  else
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
}

void Person::stop()
{
  if (state == 'x')
  {
    cout << "I can't move, I'm dead." << endl;
  }
  else
  {
    state = 's';
    cout << display_code << id_num << ": Stopped." << endl;
  }
}

void Person::show_status()
{
  Game_Object::show_status(); // prints info like location and display code and id
  if (state == 'm' || state == 'i' || state == 'o' || state == 'd' || state == 'g') // if in a state of movement, prints info like delta, destination, and speed because Astronaut does not have access to these private members
  {
    cout << " moving at speed " << speed << " to " << destination << " at each step of " << delta;
  }
  if (state =='x')
  {
    cout << " is dead.";
  }
}

bool Person::is_alive()
{
  if (state == 'x')
    return false;
  else
    return true;
}

void Person::take_hit(int attack_strength)
{
  health -= attack_strength;
  if (health <= 0)
  {
    cout << display_code << id_num << ": Gasp! I'm dying..." << endl;
    state = 'x';
  }
  else if (health < 3)
  {
    display_code = tolower(display_code);
    cout << display_code << id_num << ": Ouch!" << endl;
  }
  else
  {
    cout << display_code << id_num << ": Ouch!" << endl;
  }
}

void Person::start_supplying(Oxygen_Depot*)
{
  cout << "Sorry, I can't work a depot" << endl;
}

void Person::start_depositing(Space_Station*)
{
  cout << "Sorry, I can't work a station" << endl;
}

void Person::go_to_station(Space_Station*)
{
  cout << "Sorry, I can't lock into a station" << endl;
}

bool Person::update_location()
{
  setup_destination(destination);
  if(delta.x == 0 && delta.y == 0)
  {
    return true;
  }
  Cart_Vector newdist = destination - location;
  newdist.x = fabs(newdist.x);
  newdist.y = fabs(newdist.y); // fabs gets distance from destination
  if(newdist.x != 0 || newdist.y != 0)
  {
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
  return true;
}

void Person::setup_destination(Cart_Point dest)
{
  destination = dest;
  Cart_Vector cv = destination - location;
  delta = cv / ((cart_distance(destination, location) / speed)); // different formula from document, still works though I promise
}

void Person::start_attack(Alien* in_target) // EXTRA CREDIT: Astronaut Attack!
{
  Cart_Point AstroLoc = get_location();
  Cart_Point AlienLoc = in_target -> get_location();
  double dist = cart_distance(AlienLoc, AstroLoc);

  if (dist <= range)
  {
    if (state == 'a')
    {
      cout << display_code << id_num << ": Take that!" << endl;
      in_target -> take_hit(attack_strength);
    }
    else
    {
      cout << display_code << id_num << ": Smash!" << endl;
      target = in_target;
      state = 'a';
    }
  }

  if (dist > range)
  {
    cout << display_code << id_num << ": Target is out of range" << endl;
  }
}

double Person::get_speed()
{
  return speed;
}

void Person::change_speed(double in_speed)
{
  speed = in_speed;
}

Cart_Point Person::get_destination()
{
  return destination;
}
