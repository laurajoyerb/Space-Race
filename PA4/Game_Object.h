#ifndef GAME_OBJECT
#define GAME_OBJECT

#include "Cart_Point.h"

class Game_Object
{
protected:
  Cart_Point location;
  int id_num;
  char display_code;
  char state;

private:
  Game_Object(); // Game_Object default constructor is not used, so set to private

public:
  Game_Object(char in_code);
  Game_Object(Cart_Point in_loc, int in_id, char in_code);
  virtual ~Game_Object();
  void drawself(char* ptr);
  virtual bool update();
  Cart_Point get_location();
  int get_id();
  char get_state();
  virtual void show_status();
  virtual bool is_alive();

};

#endif
