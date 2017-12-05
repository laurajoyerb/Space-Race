#include <iostream>
#include "Game_Object.h"

using namespace std;

Game_Object::Game_Object(char in_code)
{
  display_code = in_code;
  id_num = 1;
  state = 's';
  cout << "Game_Object constructed." << endl;
}

Game_Object::Game_Object(Cart_Point in_loc, int in_id, char in_code)
{
  display_code = in_code;
  id_num = in_id;
  location = in_loc;
  state = 's';
  cout << "Game_Object constructed." << endl;
}

Game_Object::~Game_Object()
{
  cout << "Game_Object destructed." << endl;
}

Cart_Point Game_Object::get_location()
{
  return location;
}

bool Game_Object::is_alive()
{
  return true;
}

int Game_Object::get_id()
{
  return id_num;
}

char Game_Object::get_state()
{
  return state;
}

void Game_Object::show_status()
{
  cout << display_code << id_num << " at " << location;
}

void Game_Object::drawself(char* ptr)
{
  *ptr = display_code;
  if (id_num > 9)
  {
    *(ptr+1) = '*'; // for id numbers with two digits
  }
  else
  {
    *(ptr+1) = '0' + id_num; // '0' + id_num converts id_num to char to store in ptr
  }
}

bool Game_Object::update()
{
  return false; // virtual function, so other functions should be called instead of this one
}
