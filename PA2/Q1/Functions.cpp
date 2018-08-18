#include "Functions.h"

using namespace std;


// Global variables
bool run = true;
char code;
int num, res, intf, intl, currnum;
double first, last, delta;
char file[1000];
int currentr = 0;
ofstream* writefile = NULL; // Creates two pointers to ofstream/ifstream variables
ifstream* readfile = NULL; // Targets will be assigned by the readDataFromFile and writeDataToFile functions


void initialize()
{
  cout << "EC327: Introduction to Software Engineering" << endl;
  cout << "Fall 2017" << endl;
  cout << "Programming Assignment 2" << endl;
  cout << "Value of Entries is: " << ENTRIES << endl;
}

void runcode() // In charge of handling the run while loop and the switch statement for all codes
{
  while (run)
  {
    // Command Menu
    cout << endl;
    cout << "Commands:" << endl;
    cout << "f - Calculates factorial" << endl;
    cout << "r - Calculates square root" << endl;
    cout << "d - Calculates odd numbers" << endl;
    cout << "l - Calculates natural log" << endl;
    cout << "r - Calculates square root" << endl;
    cout << "d - Calculates odd numbers" << endl;
    cout << "l - Calculates natural log" << endl;
    cout << "q - Quits program" << endl;

    // Receives input for command code and converts it to lowercase
    cout << "Please enter a command code: ";
    if (readfile && ! (readfile -> eof()))
    // Checks that the readfile pointer has been assigned --> means that the user has already called the i command
    // Also checks that the end of the input file has not been reached
    {
      *readfile >> code; // *readfile dreferences the pointer and access the file itself
      if (readfile -> eof()) // As is, the function will execute the last command in the file twice, so this serves to make sure that this won't happen
      {
        cin >> code; // Asks for user input instead of from input file
      }
      else
      {
        cout << code << endl;
      }
    }
    else
    {
      cin >> code;
    }

    if (writefile) // Checks that the writefile pointer has been assigned (checks that the user has called the o command)
    // If writefile has been assigned, then every cout statement must also be printed to the output file
    {
      *writefile << "Please enter a command code: ";
      *writefile << code << endl;
    }

    code = tolower(code);

    if (!checkCode(code)) // Checks for valid code input
    {
      cout << "Invalid command code" << endl;
      if (writefile)
      {
        *writefile << "Invalid command code" << endl;
      }
    }
    else if (code == 'q') // Quits program
    {
      run = false;
    }
    else
    {
      cout << "Please enter command parameters: ";
      if (writefile)
      {
        *writefile << "Please enter command parameters: ";
      }

      // Executes code for each case
      switch (code)
      {
        case 'f':
        {
          if (readfile && ! (readfile -> eof()))
          {
            *readfile >> num;
            cout << num << endl;
          }
          else
          {
            cin >> num;
          }
          res = factorial(num);
          cout << "factorial(" << num << ") = " << res << endl;
          if (writefile)
          {
            *writefile << num << endl;
            *writefile << "factorial(" << num << ") = " << res << endl;
          }
          break;
        }

        case 'b':
        {
          if (readfile && ! (readfile -> eof()))
          {
            *readfile >> num;
            cout << num << endl;
          }
          else
          {
            cin >> num;
          }
          res = fibonacci(num);
          cout << "fibonacci(" << num << ") = " << res << endl;
          if (writefile)
          {
            *writefile << num << endl;
            *writefile << "fibonacci(" << num << ") = " << res << endl;
          }
          break;
        }

        case 'r':
        {
          currentr = 0;
          if (readfile && ! (readfile -> eof()))
          {
            *readfile >> first >> last >> delta;
            cout << first << " " << last << " " << delta << endl;
          }
          else
          {
            cin >> first >> last >> delta;
          }
          if (writefile)
          {
            *writefile << first << " " << last << " " << delta << endl;
          }
          if (first > last || delta <= 0) // Checks for valid parameter entries
          {
            cout << "No computation needed" << endl;
            if (writefile)
            {
              *writefile << "No computation needed" << endl;
            }
          }
          else
          {
            cout << fixed;
            if (writefile)
            {
              *writefile << fixed;
            }
            for (double i = first; i <= last && currentr < ENTRIES; i=i+delta)
            {
              if (floor(i) == i) // Checks if i is an integer and prints appropriate number of decimals
              {
                cout << "squareroot(" << setprecision(0) << i << ") = ";
                if (writefile)
                {
                  *writefile << "squareroot(" << setprecision(0) << i << ") = ";
                }
                if (floor (findSqrtValue(i)) == findSqrtValue(i)) // Checks for integer and prints appropriate number of decimals
                {
                  cout << setprecision(0) << findSqrtValue(i) << endl;
                  if (writefile)
                  {
                    *writefile << setprecision(0) << findSqrtValue(i) << endl;
                  }
                }
                else
                {
                  cout << setprecision(4) << findSqrtValue(i) << endl;
                  if (writefile)
                  {
                    *writefile << setprecision(4) << findSqrtValue(i) << endl;
                  }
                }
              }
              else
              {
                cout << "squareroot(" << setprecision(4) << i << ") = " << findSqrtValue(i) << endl;
                if (writefile)
                {
                  *writefile << "squareroot(" << setprecision(4) << i << ") = " << findSqrtValue(i) << endl;
                }
              }
              currentr++; // Increments currentr values to keep track of number of calculations
              if (i + delta > last && i < last) // Executes for last value given by user (even if delta is too large)
              {
                if (floor(last) == last)
                {
                  cout << "squareroot(" << setprecision(0) << last << ") = ";
                  if (writefile)
                  {
                    *writefile << "squareroot(" << setprecision(0) << last << ") = ";
                  }
                  if (floor(findSqrtValue(last)) == findSqrtValue(last))
                  {
                    cout << setprecision(0) << findSqrtValue(last) << endl;
                    if (writefile)
                    {
                      *writefile << setprecision(0) << findSqrtValue(last) << endl;
                    }
                  }
                  else
                  {
                    cout << setprecision(4) << findSqrtValue(last) << endl;
                    if (writefile)
                    {
                      *writefile << setprecision(4) << findSqrtValue(last) << endl;
                    }
                  }
                }
                else
                {
                  cout << "squareroot(" << setprecision(4) << last << ") = " << findSqrtValue(last) << endl;
                  if (writefile)
                  {
                    *writefile << "squareroot(" << setprecision(4) << last << ") = " << findSqrtValue(last) << endl;
                  }
                }
                currentr++;
              }
            }
          }
          break;
        }

        case 'd':
        {
          currentr = 0;
          if (readfile && ! (readfile -> eof()))
          {
            *readfile >> intf >> intl;
            cout << intf << " " << intl << endl;
          }
          else
          {
            cin >> intf >> intl;
          }
          if (writefile)
          {
            *writefile << intf << " " << intl << endl;
          }
          if (intf >= intl)
          {
            cout << "No computation needed" << endl;
            if (writefile)
            {
              *writefile << "No computation needed" << endl;
            }
          }
          else
          {
            currnum = intf;

            if (intf % 2)
            {
              cout << intf << ", "; // Prints first input if input was odd
              if (writefile)
              {
                *writefile << intf << ", ";
              }
              currentr++;
            }

            while ((currnum <= (intl-4)) && (currentr < ENTRIES-1))
            {
              currnum=findNextOddValue(currnum);
              cout << currnum << ", ";
              if (writefile)
              {
                *writefile << currnum << ", ";
              }
              currentr++;
            }
              cout << findNextOddValue(currnum) << endl;
              if (writefile)
              {
                *writefile << findNextOddValue(currnum) << endl;
              }
          }
          break;
        }

        case 'l':
        {
          currentr = 0;
          if (readfile && ! (readfile -> eof()))
          {
            *readfile >> first >> last >> delta;
            cout << first << " " << last << " " << delta << endl;
          }
          else
          {
            cin >> first >> last >> delta;
          }
          if (writefile)
          {
            *writefile << first << " " << last << " " << delta << endl;
          }
          if (first > last || delta <= 0)
          {
            cout << "No computation needed" << endl;
            if (writefile)
            {
              *writefile << "No computation needed" << endl;
            }
          }
          else
          {
            cout << fixed;
            if (writefile)
            {
              *writefile << fixed;
            }
            for (double i = first; i <= last && currentr < ENTRIES; i=i+delta)
            {
              if (floor(i) == i) // Checks for integer values and prints appropriate number of decimals
              {
                cout << "ln(" << setprecision(0) << i << ") = ";
                if (writefile)
                {
                  *writefile << "ln(" << setprecision(0) << i << ") = ";
                }
                if (floor (naturalLog(i)) == naturalLog(i) )
                {
                  cout << setprecision(0) << naturalLog(i) << endl;
                  if (writefile)
                  {
                    *writefile << setprecision(0) << naturalLog(i) << endl;
                  }
                }
                else
                {
                  cout << setprecision(4) << naturalLog(i) << endl;
                  if (writefile)
                  {
                    *writefile << setprecision(4) << naturalLog(i) << endl;
                  }
                }
              }
              else
              {
                cout << "ln(" << setprecision(4) << i << ") = " << naturalLog(i) << endl;
                if (writefile)
                {
                  *writefile << "ln(" << setprecision(4) << i << ") = " << naturalLog(i) << endl;
                }
              }
              currentr++;
              if (i + delta > last && i < last)
              {
                if (floor(last) == last)
                {
                  cout << "ln(" << setprecision(0) << last << ") = ";
                  if (writefile)
                  {
                    *writefile << "ln(" << setprecision(0) << last << ") = ";
                  }
                  if (floor (naturalLog(last)) == naturalLog(last) )
                  {
                    cout << setprecision(0) << naturalLog(last) << endl;
                    if (writefile)
                    {
                      *writefile << setprecision(0) << naturalLog(last) << endl;
                    }
                  }
                  else
                  {
                    cout << setprecision(4) << naturalLog(last) << endl;
                    if (writefile)
                    {
                      *writefile << setprecision(4) << naturalLog(last) << endl;
                    }
                  }
                }
                else
                {
                  cout << "ln(" << setprecision(4) << last << ") = " << naturalLog(last) << endl;
                  if (writefile)
                  {
                    *writefile << "ln(" << setprecision(4) << last << ") = " << naturalLog(last) << endl;
                  }
                }
                currentr++;
              }
            }
          }
          break;
        }

        case 'n':
        {
          currentr = 0;
          if (readfile && ! (readfile -> eof()))
          {
            *readfile >> first >> last >> delta;
            cout << first << " " << last << " " << delta << endl;
          }
          else
          {
            cin >> first >> last >> delta;
          }
          if (writefile)
          {
            *writefile << first << " " << last << " " << delta << endl;
          }
          if (first > last || delta <= 0)
          {
            cout << "No computation needed" << endl;
            if (writefile)
            {
              *writefile << "No computation needed" << endl;
            }
          }
          else
          {
            cout << fixed;
            cout << setprecision(4); // All values for findNyanCatValue function use 4 decimal places as shown in sample output
            if (writefile)
            {
              *writefile << fixed;
              *writefile << setprecision(4);
            }
            for (double i = first; i <= last && currentr < ENTRIES; i=i+delta)
            {
              cout << "NyanCat value of " << i << " = " << findNyanCatValue(i) << endl;
              if (writefile)
              {
                *writefile << "NyanCat value of " << i << " = " << findNyanCatValue(i) << endl;
              }
              currentr++;
              if (i + delta > last && i < last)
              {
                cout << "NyanCat value of " << last << " = " << findNyanCatValue(last) << endl;
                if (writefile)
                {
                  *writefile << "NyanCat value of " << last << " = " << findNyanCatValue(last) << endl;
                }
                currentr++;
              }
            }
          }
          break;
        }

        case 'i':
        {
          cin >> file;
          if (writefile)
          {
            *writefile << file << endl;
          }
          readDataFromFile(file);
          break;
        }

        case 'o':
        {
          if (readfile && ! (readfile -> eof()))
          {
            *readfile >> file;
            cout << file << endl;
          }
          else
          {
            cin >> file;
          }
          writeDataToFile(file);
          break;
        }
      }
    }
  }
}

bool checkCode(char input)
{
  bool check;
  switch (input) // Checks all valid command codes
  {
    case 'f':
      check = true;
      break;
    case 'b':
      check = true;
      break;
    case 'r':
      check = true;
      break;
    case 'd':
      check = true;
      break;
    case 'l':
      check = true;
      break;
    case 'n':
      check = true;
      break;
    case 'i':
      check = true;
      break;
    case 'o':
      check = true;
      break;
    case 'q':
      check = true;
      break;
    default:
      check = false;
  }
  return check;
}

void writeDataToFile(const char* file)
{
  writefile = new ofstream(); // Creates a space on the heap for an ofstream variable for writefile (assigns writefile pointer)
  writefile -> open(file); // Opens writefile file
}

void readDataFromFile(const char* file)
{
  readfile = new ifstream(); // Creates a space on the heap for an ifstream variable for readfile (assigns readfile pointer)
  readfile -> open(file); // Opens readfile
}

double findNyanCatValue(double myNum)
{
  double catval;
  catval = (2 * myNum) + (myNum * pow(6,myNum));
  return catval;
}

int factorial(int num)
{
  if(num <= 1) // Base Case
  {
    return 1;
  }
  else
  {
    return num*factorial(num-1); // Recursive function (num-1 is simpler)
  }
}

int fibonacci(int fib)
{
  if(fib <= 2) // Base Case
  {
    return 1;
  }
  else
  {
    return fibonacci(fib-1)+fibonacci(fib-2); // Recursive function
  }
}

double findSqrtValue(double rad)
{
  return sqrt(rad);
}

double naturalLog(double arg)
{
  return log(arg);
}

int findNextOddValue(int start)
{
  if (start % 2) // If start is odd, function returns next off number by simply adding 2
  {
    return start + 2;
  }
  else // Otherwise, the next odd value is start + 1
  {
    return start+1;
  }
}
