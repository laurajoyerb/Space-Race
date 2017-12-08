#include <iostream>
#include "Oxygen_Depot.h"

using namespace std;

Oxygen_Depot::Oxygen_Depot() : Game_Object('O')
{
  state = 'f';
  cout << "Oxygen_Depot default constructed." << endl;
}

Oxygen_Depot::Oxygen_Depot(Cart_Point inputLoc, int inputId) : Game_Object(inputLoc, inputId, 'O')
{
  amount_oxygen = 50;
  state = 'f';
  cout << "Oxygen_Depot constructed." << endl;
}

Oxygen_Depot::~Oxygen_Depot()
{
  cout << "Oxygen_Depot destructed." << endl;
}

bool Oxygen_Depot::isempty()
{
  if (amount_oxygen)
  {
    return false;
  }
  else
  {
    return true;
  }
}

double Oxygen_Depot::extract_oxygen(double amount_to_extract)
{
  if (amount_oxygen >= amount_to_extract) // If there is sufficient oxygen to give, amount requested is returned and subtracted from total amount remaining
  {
    amount_oxygen -= amount_to_extract;
    return amount_to_extract;
  }
  else // Otherwise, remaining is returned and total is set to zero
  {
    double tempO = amount_oxygen;
    amount_oxygen = 0;
    return tempO;
  }
}

bool Oxygen_Depot::update()
{
  if (isempty() && state != 'e') // executes if it hasn't already been set to empty
  {
    state = 'e';
    cout << "Oxygen Depot " << id_num << " has been depleted." << endl;
    display_code = 'o';
    return true;
  }
  else
  {
    return false;
  }
}

void Oxygen_Depot::show_status()
{
  cout << "Oxygen Depot status: ";
  Game_Object::show_status();
  cout << " contains " << amount_oxygen << endl;
}
