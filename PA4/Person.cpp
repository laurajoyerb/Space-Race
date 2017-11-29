#include <iostream>
#include "Person.h"
#include <math.h>

using namespace std;

Person::Person() : Game_Object('x')
{
  speed = 5;
  health = 5;
  cout << "Person default constructed." << endl;
}

Person::Person(char in_code) : Game_Object(in_code)
{
  speed = 5;
  health = 5;
  state = 's';
  cout << "Person constructed." << endl;
}

Person::Person(Cart_Point in_loc, int in_id, char in_code) : Game_Object(in_loc, in_id, in_code)
{
  speed = 5;
  health = 5;
  cout << "Person constructed." << endl;
}

Person::~Person()
{
  cout << "Person destructed." << endl;
}

void Person::start_moving(Cart_Point dest)
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

void Person::stop()
{
  state = 's';
  cout << display_code << id_num << ": Stopped." << endl;
}

void Person::show_status()
{
  Game_Object::show_status(); // prints info like location and display code and id
  if (state == 'm' || state == 'i' || state == 'o' || state == 'd' || state == 'g') // if in a state of movement, prints info like delta, destination, and speed because Astronaut does not have access to these private members
  {
    cout << " moving at speed " << speed << " to " << destination << " at each step of " << delta;
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
    cout << "Gasp!" << endl;
    state = 'x';
  }
  else
  {
    cout << "Ouch!" << endl;
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

void Person::setup_destination(Cart_Point dest)
{
  destination = dest;
  Cart_Vector cv = destination - location;
  delta = cv / ((cart_distance(destination, location) / speed)); // different formula from document, still works though I promise
}
