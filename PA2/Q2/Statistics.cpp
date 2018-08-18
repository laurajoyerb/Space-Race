#include <iostream>
#include <algorithm>

using namespace std;

double getMedian(int * arr, int size)
{
  sort (arr, arr + size); // Sorts arr in ascending order
  double med;
  if (!(size % 2)) // If arr has an even size, then the median is the average of the two innermost values
  {
    double first = *(arr + (size / 2) - 1); // Gets first of the two innermost values
    double second = *(arr + (size / 2)); // Gets second of the two innermost values
    med = (first + second) / 2; // Gets average
  }
  else
  {
    med = *(arr + size/2); // Otherwise, the median is the element in the middle of the array
  }
  return med;
}

int getLargest(int * arr, int size)
{
  sort(arr, arr + size); // Sorts arr in ascending order
  int big = *(arr + (size-1)); // Grabs last element in arr
  return big;
}
