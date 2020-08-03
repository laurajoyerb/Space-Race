#include <iostream>
#include <string>

using namespace std;

int main(){

  int dec1;
  int dec2;
  // Reads two integers in from user
  cout << "Enter two positive integers: ";
  cin >> dec1 >> dec2;
  // Checks that user input is not negative
  while (dec1 <= 0 || dec2 <=0){
    cout << "Please enter two positive integer values: ";
    cin >> dec1 >> dec2;
  }

  // Initializes character array to hold hex string 1
  char hex1[100];
  int var;

  int quotient=dec1;
  int i=0;

  //Converts decimal value to hex
  while(quotient){
    // Var holds the remainder from quotient/16, or the value of the hex
    var=quotient%16;
    // Converts the numerical values to the equivalent ASCII values for hex
    // If the numerical value is greater than 9, it must be increased by 55 to reach the values A-F
    if (var > 9){
      var+=55;
    } else {
      // If the numerical value is less than 9, it is only increased to its numerical value in ASCII
      var+=48;
    }
    // Stores this hex value into the character array hex
    hex1[i]=var;
    // Increments i to the next value for hex[i]
    i++;
    // Resets quotient to the new quotient. Quotient is an int var, so it automatically disregards the remainder here
    quotient/=16;
  }

  // Clears the rest of the hex1 array
  for (int m=i; m <=100; m++) {
    hex1[m]=0;
  }

  // Initializes second hex character array
  char hex2[100];

  quotient=dec2;
  int j=0;

  // Converts second decimal value to hex; Same process as above
  while(quotient){
    var=quotient%16;
    if (var > 9){
      var+=55;
    } else {
      var+=48;
    }
    hex2[j]=var;
    j++;
    quotient/=16;
  }

  // Clear rest of hex array
  for (int n=j; n <=100; n++) {
    hex2[n]=0;
  }

  // Flips first hex string
  for (int n=0; n < j/2; n++) {
    char temp=hex2[n];
    hex2[n]=hex2[j-n-1];
    hex2[j-n-1]=temp;
  }

  // Flips second hex string
  for (int m=0; m < i/2; m++) {
    char temp=hex1[m];
    hex1[m]=hex1[i-m-1];
    hex1[i-m-1]=temp;
  }


  int dist=0;

  // Checks every position in hex arrays for differences; any difference increments counter dist
  for (int k=0; k<100; k++) {
    if (hex1[k]!=hex2[k]) {
      dist++;
    }
}

  // Prints results
  cout << "Hamming distance between " << dec1 << " and " << dec2 << " when numbers are in hex format is " << dist << endl;

  return 0;
}
