#include <iostream>
using namespace std;

int main(){

// Declares variables
int x1;
int x2;
int y1;
int y2;
int l1;
int l2;
int h1;
int h2;

// Gathers data for rectangles
cout << "Enter the information for the first rectangle:" << endl;

cout << "X-coordinate: ";
cin >> x1;
// Error checks for negative numbers or 0
while (x1 < 0){
  cout << "Error. Please enter a non-negative integer value." << endl;
  cout << "X-coordinate: ";
  cin >> x1;
}

cout << "Y-coordinate: ";
cin >> y1;
// Error checks for negative numbers or 0
while (y1 < 0){
  cout << "Error. Please enter a non-negative integer value." << endl;
  cout << "Y-coordinate: ";
  cin >> y1;
}

cout << "Length: ";
cin >> l1;
// Error checks for negative numbers or 0
while (l1 < 0){
  cout << "Error. Please enter a non-negative integer value." << endl;
  cout << "Length: ";
  cin >> l1;
}

cout << "Height: ";
cin >> h1;
// Error checks for negative numbers or 0
while (h1 < 0){
  cout << "Error. Please enter a non-negative integer value." << endl;
  cout << "Height: ";
  cin >> h1;
}

cout << "Enter the information for the second rectangle:" << endl;
cout << "X-coordinate: ";
cin >> x2;
// Error checks for negative numbers or 0
while (x2 < 0){
  cout << "Error. Please enter a non-negative integer value." << endl;
  cout << "X-coordinate: ";
  cin >> x2;
}

cout << "Y-coordinate: ";
cin >> y2;
// Error checks for negative numbers or 0
while (y2 < 0){
  cout << "Error. Please enter a non-negative integer value." << endl;
  cout << "Y-coordinate: ";
  cin >> y2;
}

cout << "Length: ";
cin >> l2;
// Error checks for negative numbers or 0
while (l2 < 0){
  cout << "Error. Please enter a non-negative integer value." << endl;
  cout << "Length: ";
  cin >> l2;
}

cout << "Height: ";
cin >> h2;
// Error checks for negative numbers or 0
while (h2 < 0){
  cout << "Error. Please enter a non-negative integer value." << endl;
  cout << "Height: ";
  cin >> h2;
}

// Starts with assumption that rectangles will not intersect
bool varx=false;
bool vary=false;

// Checks if x values will intersect
if (x1<=x2){
  if(x1+l1 >= x2)
    {varx = true;}
  }
else {
  if(x2+l2 >= x1)
    {varx = true;}
}

// Checks if y values will intersect
if (y1 <= y2){
  if( y1+ h1 >= y2)
    {vary=true;}
  }
else {
  if(y2+h2 >= y1)
    {vary=true;}
}

// If BOTH x and y values intersect, then the rectangles intersect
if (varx && vary) {
  cout << "The rectangles intersect!" << endl;
} else {
  cout << "The rectangles do NOT intersect!" << endl;
}

return 0;
}
