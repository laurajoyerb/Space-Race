#ifndef OXYGEN_DEPOT
#define OXYGEN_DEPOT

#include "Game_Object.h"

class Oxygen_Depot : public Game_Object
{
private:
  double amount_oxygen;

public:
  Oxygen_Depot();
  Oxygen_Depot(Cart_Point, int);
  ~Oxygen_Depot();

  bool isempty();
  double extract_oxygen(double amount_to_extract = 20.0);
  bool update();
  void show_status();
};

#endif
