#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void WriteRandomData(int N, int M, const char *filename)
{
  ofstream myfile(filename); // Opens file
  srand(time(0)); // Sets seed for the rand function so it is truly random
  if (myfile.is_open())
  {
    for (int i = 0; i < N-1; i++)
    {
      myfile << rand() % (M+1) << endl; // Prints N-1 integers between [0, M] inclusive into myfile
    }
    myfile << rand() % (M+1); // Prints Nth integer
    myfile.close();
  }
  else
  {
    cout << "Error. File could not be opened" << endl;
  }
}

void ReadData(const char *filename, int &size, int myArray[])
{
  ifstream myfile(filename);
  if (myfile.is_open())
  {
    int i = 0;
    while (!myfile.eof())
    {
      myfile >> myArray[i]; // Stores each line in the file into myArray
      i++;
    }
    size = i; // Sets size equal to the i counter
    myfile.close();
  }
  else
  {
    cout << "Error. File could not be opened" << endl;
  }
}
