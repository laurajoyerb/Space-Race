#ifndef CART_VECTOR
#define CART_VECTOR

class Cart_Vector
{
  public:
    double x;
    double y;
    Cart_Vector();
    Cart_Vector(double x, double y);

};

Cart_Vector operator*(Cart_Vector& v1, double d);

Cart_Vector operator/(Cart_Vector& v1, double d);

std::ostream& operator<<(std::ostream& os, const Cart_Vector& cv);

#endif
