#include "Functions.h"

using namespace std;


int main()
{

  // Initializes variables
  bool run = true;
  char code;
  int num, res, intf, intl, currnum;
  double first, last, delta;
  char file[1000];
  int currentr = 0;
  ofstream* writefile = NULL; // Creates two pointers to ofstream/ifstream variables
  ifstream* readfile = NULL; // Targets will be assigned by the readDataFromFile and writeDataToFile functions

  // Displays program intro text
  initialize();

  runcode(); // Executes main function that handles commands, inputsm and outputs

  // Once runcode has completed, the user has inputted a q and wishes to exit the program

  // Closes readfile and writefile if they were opened by the user during runcode()
  if (readfile)
  {
    readfile -> close();
  }

  if (writefile)
  {
    writefile -> close();
  }

  return 0;
}
