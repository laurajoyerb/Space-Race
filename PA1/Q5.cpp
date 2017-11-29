#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main() {
  string both;
  cout << "Enter char, operation: ";
  cin >> both;

  // Checks for length
  if (both.length()!=2) {
    cout << "Error. Enter only a letter and an operation, no spaces." << endl;

  } else if (both[1]!='1' && both[1]!='2' && both[1]!='3') { // Checks for valid operation value
    cout << "Illegal operation"<< endl;

  } else if ( both[0]<65 || both[0]>122 || (both[0]>90 && both[0]<97) ) { // Checks for valid character input
    cout << "Illegal char" << endl;

  } else { // Executes only if all conditions pass

    // Switch case based on operations
    switch (both[1]){

      case '1': // Changes case
        // If the letter is uppercase, it is changed to lowercase, and vice versa
        if (isupper(both[0])) {
          both[0]=tolower(both[0]);
          cout << "Result: " << both[0] << endl;
        } else {
          both[0]=toupper(both[0]);
          cout << "Result: " << both[0] << endl;
        }
        break;

      case '2': // Changes case and reverses letter
        // If the initial letter is lowercase
        if (islower(both[0])) {
          // Takes distance from 'a' (97) to letter
          int diff=both[0]-'a';
          // Finds letter that distance from uppercase 'Z'
          char newchar='Z'-diff;
          cout << "Result: " << newchar << endl;
        } else { // If the initial letter is uppercase
          // Takes distance from 'A'
          int diff=both[0]-'A';
          // Finds letter that distance from lowercase 'z'
          char newchar='z'-diff;
          cout << "Result: " << newchar << endl;
        }
        break;

      case '3': // Encrypts letter by changing it six letters "ahead"
        char newchar;
        // Executes for letters between A and T inclusive
        if (both[0] < 85) {
          // Adds 6 to ASCII value and moves the letter 6 ahead
          newchar=both[0]+6;
          cout << "Result: " << newchar << endl;

        } else if (both[0] <= 90){ // Executes for letters U to Z
          newchar=both[0]+12; // +12 because it jumps to the lowercase values
          cout << "Result: " << newchar << endl;

        } else if (both[0] < 117) { // Executes for letters a to t
          // Adds 6 to ASCII and moves letters ahead by 6
          newchar=both[0]+6;
          cout << "Result: " << newchar << endl;

        } else { // Executes for letters u to z
          newchar=both[0]-52; // Goes back to lowercase letters
          cout << "Result: " << newchar << endl;
        }
    }
  }
}
