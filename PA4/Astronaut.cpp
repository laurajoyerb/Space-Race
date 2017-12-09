#include <iostream>
#include "Astronaut.h"

using namespace std;

Astronaut::Astronaut() : Person('A')
{
  amount_moonstones = 0;
  amount_oxygen = 20;
  there = false; // see explanation in update() under state 'l'
  depot = NULL;
  home = NULL;
  cout << "Astronaut default constructed." << endl;
}

Astronaut::Astronaut(int in_id, Cart_Point in_loc) : Person(in_loc, in_id, 'A')
{
  amount_moonstones = 0;
  amount_oxygen = 20;
  there = false; // see explanation in update() under state 'l'
  depot = NULL;
  home = NULL;
  cout << "Astronaut constructed." << endl;
}

Astronaut::~Astronaut()
{
  cout << "Astronaut destructed." << endl;
}

bool Astronaut::update()
{
  bool arrive; // checks if object has arrived at location
  double extract; // amount extracted and received by astronaut
  if (state == 'x')
  {
    return false;
  }
  else
  {
    if (health < 3)
    {
      display_code = tolower(display_code);
    }
    switch (state)
    {
      case 's':
      {
        return false; // Nothing changes, nothing arrives, so return false
        break;
      }
      case 'm':
      {
        arrive = Person::update_location(); // updates location of moving astronaut and advances one step
        if (arrive) // once it arrives, the state changes to stopped
        {
          state = 's';
          return true;
        }
        else
        {
          amount_oxygen--; // if it hasn't arrived yet, oxygen decreases
          if (amount_oxygen <= 0) // if the astronaut runs out of oxygen, it is locked
          {
            state = 'x';
            cout << "I'm out of oxygen. I'm dying!" << endl;
            return true;
          }
          else
          {
            amount_moonstones++; // otherwise, moonstones increments
          }
          return false;
        }
        break;
      }
      case 'o':
      {
        arrive = Person::update_location(); // updates astronaut's progress towards oxygen depot
        if (arrive)
        {
          state = 'g';
          return true;
        }
        else
        {
          amount_oxygen--;

          if (amount_oxygen <= 0)
          {
            state = 'x';
            cout << "I'm out of oxygen. I'm dying!" << endl;
            return true;
          }
          else
          {
            amount_moonstones++;
          }
          return false;
        }
        break;
      }
      case 'g':
      {
        extract = depot -> extract_oxygen();
        amount_oxygen += extract;
        cout << display_code << id_num << ": Got " << extract << " more oxygen." << endl;
        state = 's';
        return true;
        break;
      }
      case 'i':
      {
        arrive = Person::update_location();
        if (arrive)
        {
          state = 'd';
          return true;
        }
        else
        {
          amount_oxygen--;
          if (amount_oxygen <= 0)
          {
            state = 'x';
            cout << "I'm out of oxygen. I'm dying!" << endl;
            return true;
          }
          else
          {
            amount_moonstones++;
          }
          return false;
        }
        break;
      }
      case 'd':
      {
        cout << display_code << id_num << ": Deposit " << amount_moonstones << " moon stones." << endl;
        home -> deposit_moonstones(amount_moonstones);
        amount_moonstones = 0;
        state = 's';
        return true;
        break;
      }
      case 'a': // EXTRA CREDIT: Astronauts now attack aliens too
      {
        Cart_Point AstroLoc = get_location();
        Cart_Point AlienLoc = target -> get_location();
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
            cout << display_code << id_num << ": I win." << endl;
            state = 's';
            return true;
          }
        }
      }
      case 'l':
      {
        if (amount_oxygen <= 0)
        {
          return false; // if it is out of oxygen, nothing happens
        }
        else
        {
          Cart_Point dest = home -> get_location();
          arrive = Person::update_location();

          // Initial idea was to check if astronaut's location was already at destination of Space station, and if so, there's no need to update location or add astronauts because the astronaut would've already done so when it first arrived. However, this idea fails if the astronaut is already at the station (say, just having finished depositing moonstones), and THEN the lock command is called. This changes the state to 'l', and the destination and space station's location are the same. There is no way to differentiate between an astronaut that has just "arrived" at a space station ready to lock in or one tht has been locked in at that station for several turns. Both cases have a state of 'l' and the same location, and update_location() returns true for both as well. So, the additional member "there" provides the difference we need to differentiate between treatment of the first "arrival" versus just being at the station.

          // It is initially set to false because the astronaut is NOT there (at the station) and is not locked in. Once the astronaut locks in, this bool is set to true, so the following calls to update will not add more astronauts even though there is only one waiting and locked in.

          if (arrive && !there)
          {
            home -> add_astronaut(); // if astronaut has arrived, the astronaut is locked in to the space station
            there = true;
            return true;
          }
          else
          {
            return false;
          }
        }
        break;
      }
      default:
      {
        return false;
      }
    }
  }
}

void Astronaut::start_supplying(Oxygen_Depot* inputDepot)
{
  if (state == 'x')
  {
    cout << "I can't move, I'm dead." << endl;
  }
  else
  {
    depot = inputDepot; // assigns pointer
    Person::setup_destination(inputDepot -> get_location());
    state = 'o';
    cout << "Astronaut " << get_id() << " supplying from Oxygen Depot " << inputDepot -> get_id() << endl;
    cout << display_code << get_id() << ": Yes, my lord." << endl;
  }
}

void Astronaut::start_depositing(Space_Station* inputStation)
{
  if (state == 'x')
  {
    cout << "I can't move, I'm dead." << endl;
  }
  else
  {
    home = inputStation; // assigns pointer
    Person::setup_destination(inputStation -> get_location());
    state = 'i';
    cout << "Astronaut " << get_id() << " depositing to Space Station " << inputStation -> get_id() << endl;
    cout << display_code << get_id() << ": Yes, my lord." << endl;
  }
}

void Astronaut::go_to_station(Space_Station* inputStation)
{
  if (state == 'x')
  {
    cout << "I can't move, I'm dead." << endl;
  }
  else
  {
    home = inputStation; // assigns pointer
    state = 'l';
    Person::setup_destination(inputStation -> get_location());
    cout << "Astronaut " << get_id() << " locking in at Space Station " << inputStation -> get_id() << endl;
  }
}

void Astronaut::show_status()
{
  cout << "Astronaut status: ";
  Person::show_status(); // calls Person show_status to call Game_Object show_status() and to print person info like destination, delta and speed if necessary
  switch (state)
  {
    case 's':
    {
      cout << " stopped with " << amount_oxygen << " oxygen and " << amount_moonstones << " moon stones." << endl;
      break;
    }
    case 'm':
    {
      cout << endl; // all info is printed by Person show_status()
      break;
    }
    case 'o':
    {
      cout << " is outbound to a Depot with " << amount_oxygen << " oxygen and " << amount_moonstones << " moon stones." << endl;
      break;
    }
    case 'g':
    {
      cout << " is getting oxygen from the depot" << endl;
      break;
    }
    case 'i':
    {
      cout << " is inbound to home with load: " << amount_moonstones << " moon stones and " << amount_oxygen << " oxygen" << endl;
      break;
    }
    case 'd':
    {
      cout << " depositing " << amount_moonstones << " moon stones" << endl;
      break;
    }
    case 'l':
    {
      cout << " is locked at Space Station." << endl;
      break;
    }
    case 'a': // EXTRA CREDIT
    {
      cout << " attacking alien X" << target -> get_id();
    }
    case 'x':
    {
      cout << endl;
      break;
    }
  }
}
