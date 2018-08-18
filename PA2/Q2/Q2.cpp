#include <iostream>
#include <cstdlib>
#include "FileFunctions.h"
#include "Statistics.h"

using namespace std;


int * DoubleAndReverse (int *list, int size)
{
  int * newArr = new int[size*2]; // Creates on the heap so the pointer can be returned by the function
  for (int i = 0; i < size; i++)
  {
    *(newArr+i) = *(list+i); // Sets first "size" elements equivalent to list
  }
  for (int i = 0; i < size; i++)
  {
    *(newArr + size + i) = *(list + size -1 - i); // Counts forward for newArr and backwards for list to reverse order
  }
  return newArr;
}

int main()
{
  // Arbitrary values for variables
  char filename[1000] = "data.txt";
  int N = 6;
  int M = 20;

  // Writes random values into file
  WriteRandomData(N, M, filename);
  cout << "Writing File: " << filename << endl;

  // Reads values into an array
  int size;
  int myArray[1000];
  ReadData(filename, size, myArray);
  cout << "Reading File: " << filename << endl;
  cout << "Array size is: " << size << endl;

  // DoubleAndReversed array is calculated and printed
  int* doubleArr = DoubleAndReverse(myArray, size);

  cout << "Doubled and Reversed is: [";
  for (int i = 0; i < (size*2)-1; i++)
  {
    cout << doubleArr[i] << " ";
  }
  cout << doubleArr[size*2-1] << "]" << endl;

  // Finds and prints median and largest value
  cout << "Median is: " << getMedian(myArray, size) << endl;
  cout << "Largest is: " << getLargest(myArray, size) << endl;

  return 0;
}
