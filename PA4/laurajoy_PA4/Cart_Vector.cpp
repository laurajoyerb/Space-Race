#include <iostream>
#include "Cart_Vector.h"

using namespace std;

Cart_Vector::Cart_Vector()
{
  x = 0.0;
  y = 0.0;
}

Cart_Vector::Cart_Vector(double inputx, double inputy)
{
  x = inputx;
  y = inputy;
}

ostream& operator<<(std::ostream& os, const Cart_Vector& cv)
{
    os << "<" << cv.x << ", " << cv.y << ">";
    return os;
}

Cart_Vector operator*(Cart_Vector& v1, double d)
{
  Cart_Vector newcv = Cart_Vector();
  newcv.x = v1.x * d;
  newcv.y = v1.y * d;
  return newcv;
}

Cart_Vector operator/(Cart_Vector& v1, double d)
{
  if (d)
  {
    Cart_Vector newcv = Cart_Vector();
    newcv.x = v1.x / d;
    newcv.y = v1.y / d;
    return newcv;
  }
  else
  {
    return v1;
  }
}
