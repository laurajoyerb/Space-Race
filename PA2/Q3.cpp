#include <iostream>

using namespace std;

int counter; // Global variable

void PrintRhombus(int num)
{
  int spaces = 9 - counter; // Counts how many spaces will be needed on a given line
  for (int i = 0; i < spaces; i++) // Prints spaces
  {
    cout << " ";
  }
  for (int i = 1; i < counter; i++) // Prints the ascending numeric values for that line
  {
    cout << i;
  }
  for (int i = counter; i > 0; i--) // Prints the descending numeric values for that line
  {
    cout << i;
  }
  cout << endl; // Moves to next line

  if (counter < num) // If counter is less than num, the function calls itself again with counter + 1 and repeats the process
  {
    counter += 1;
    PrintRhombus(num);
  }

  // Once counter >= num, this code executes for each previous call of the function (counts back down)
  counter -= 1; // Decrements counter to avoid printing the longest line twice
  for (int i = 0; i <= spaces; i++) // Prints spaces for that line
  {
    cout << " ";
  }
  for (int i = 1; i < counter; i++) // Prints ascending numeric values for that line
  {
    cout << i;
  }
  for (int i = counter; i > 0; i--) // Prints descending numeric values for that line
  {
    cout << i;
  }
  cout << endl; // Moves to next line
}

int main()
{
  cout << "Enter a number [1-9]: ";
  int x;
  cin >> x;
  while (x < 1 || x > 9) // Error checks for valid input in correct range
  {
    cout << "Error. Enter a number between 1 and 9 inclusive: ";
    cin >> x;
  }
  counter = 1; // Sets initial value of counter to 1

  PrintRhombus(x); // Calls recursive function

  return 0;
}
