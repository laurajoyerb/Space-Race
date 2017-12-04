#include <iostream>
#include "View.h"

using namespace std;

View::View()
{
  size = 11;
  scale = 2;
  origin = Cart_Point();
}

bool View::get_subscripts(int &ix, int &iy, Cart_Point location)
{
  Cart_Vector sub = (location - origin);
  sub = sub/scale;
  sub.x = (int) sub.x; // truncates values to integer values
  sub.y = (int) sub.y;

  if (sub.x <= size*scale && sub.y <= size*scale) // if subscripts are within the bounds of the graph
  {
    ix = sub.x; // returns x and y subscripts
    iy = sub.y;
    return true;
  }
  else
  {
    cout << "An object is outside the display" << endl;
    return false;
  }
}

void View::clear()
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      grid[i][j][0] = '.';
      grid[i][j][1] = ' '; // for spacing
    }
  }
}

void View::plot(Game_Object* ptr)
{
  int x, y;
  bool valid = get_subscripts(x, y, ptr -> get_location());

  if (valid) // only plots valid subscripts
  {
    if( grid[x][y][0] != '.' ) // executes if there's already an object there
    {
      grid[x][y][0] = '*';
      grid[x][y][1] = ' ';
    }
    else
    {
      char* chardisp = new char; // creates new char pointer on heap
      ptr -> drawself(chardisp);
      grid[x][y][0] = *chardisp;
      grid[x][y][1] = *(chardisp+1);
      delete chardisp; // gets rid of new pointer
    }
  }
}

void View::draw()
{
  for (int y = size - 1; y >= 0; y--) // loops for every row printed
  {
    if(!(y % 2)) // prints y axis value for every other line
    {
      if (y*scale < 10) // if less than 10, print number then a space!
      {
        cout << y * scale << " ";
      }
      else
      {
        cout << y * scale;
      }
    }
    else // if not a line with a number, print two spaces instead to keep uniform layout
    {
      cout << "  ";
    }
    for (int x = 0; x < size; x++)
    {
      cout << grid[x][y][0] << grid[x][y][1]; // prints dots and objects for that row
    }
    cout << endl;
  }


  // prints x axes values on bottom
  cout << "  "; // starts at the grid not at beginning of line
  for (int x = 0; x < size; x++)
  {
    if (!(x % 2)) // prints for every other line
    {
      if (x*scale < 10) // if less than 10, print number then a space!
      {
        cout << x * scale << " ";
      }
      else
      {
        cout << x * scale;
      }
    }
    else
    {
      cout << "  "; // if not a line with a number, print two spaces instead to keep uniform layout
    }
  }

  cout << endl; // moves to newline after printing everything for display
}
