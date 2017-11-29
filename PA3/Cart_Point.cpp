#include <iostream>
#include <cmath>
#include "Cart_Point.h"

using namespace std;

Cart_Point::Cart_Point()
{
  x = 0.0;
  y = 0.0;
}

Cart_Point::Cart_Point(double inputx, double inputy)
{
  x = inputx;
  y = inputy;
}

double cart_distance(Cart_Point p1, Cart_Point p2)
{
  double dist = sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
  return dist;
}

ostream& operator << (ostream &os, const Cart_Point &cp)
{
    os << "(" << cp.x << ", " << cp.y << ")";
    return os;
}

Cart_Point operator+(Cart_Point& p1, Cart_Vector& v1)
{
  Cart_Point newcp = Cart_Point();
  newcp.x = p1.x + v1.x;
  newcp.y = p1.y + v1.y;
  return newcp;
}

Cart_Vector operator-(Cart_Point& p1, Cart_Point& p2)
{
  Cart_Vector newcv = Cart_Vector();
  newcv.x = p1.x - p2.x;
  newcv.y = p1.y - p2.y;
  return newcv;
}
