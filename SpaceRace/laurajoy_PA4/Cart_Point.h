#ifndef CART_POINTER
#define CART_POINTER

#include "Cart_Vector.h"

class Cart_Point
{
public:
  double x;
  double y;

  Cart_Point();
  Cart_Point(double x, double y);

};

double cart_distance(Cart_Point p1, Cart_Point p2);

Cart_Point operator+(Cart_Point& p1, Cart_Vector& v1);

Cart_Vector operator-(Cart_Point& p1, Cart_Point& p2);

std::ostream& operator<<(std::ostream& os, const Cart_Point& cp);

#endif
