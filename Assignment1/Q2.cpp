#include <iostream>
#include <iomanip>
using namespace std;

double result;

// Function that converts from cups to other measurements
void cupsconv(double cups, int to){
  // Sets fractional digits to 3
  cout << fixed << setprecision(3);
  switch (to){
    case 2:
      result=cups*8;
      cout << cups << " cups is " << result << " ounces." << endl;
      break;
    case 3:
      result=cups*16;
      cout << cups << " cups is " << result << " tablespoons." << endl;
      break;
    case 4:
      result=cups*48;
      cout << cups << " cups is " << result << " teaspoons." << endl;
      break;
  }
}

// Function that converts from ounces to other measurements
void ouncesconv(double ounces, int to){
  // Sets fractional digits to 3
  cout << fixed << setprecision(3);
  switch (to){
    case 1:
      result=ounces/8;
      cout << ounces << " ounces is " << result << " cups." << endl;
      break;
    case 3:
      result=ounces*2;
      cout << ounces << " ounces is " << result << " tablespoons." << endl;
      break;
    case 4:
      result=ounces*6;
      cout << ounces << " ounces is " << result << " teaspoons." << endl;
      break;
  }

}

// Function that converts from tablespoons to other measurements
void tableconv(double table, int to){
  //Sets fractional digits to 3
  cout << fixed << setprecision(3);
  switch (to){
    case 1:
      result=table/16;
      cout << table << " tablespoons is " << result << " cups." << endl;
      break;
    case 2:
      result=table/2;
      cout << table << " tablespoons is " << result << " ounces." << endl;
      break;
    case 4:
      result=table*3;
      cout << table << " tablespoons is " << result << " teaspoons." << endl;
      break;
  }
}

// Function that converts from teaspoons to other measurements
void teaconv(double tea, int to){
  // Sets fractional digits to 3
  cout << fixed << setprecision(3);
  switch (to){
    case 1:
      result=tea/48;
      cout << tea << " teaspoons is " << result << " cups." << endl;
      break;
    case 2:
      result=tea/6;
      cout << tea << " teaspoons is " << result << " ounces." << endl;
      break;
    case 3:
      result=tea/3;
      cout << tea << " teaspoons is " << result << " tablespoons." << endl;
      break;
  }
}

int main(){

// Initialize variables
int from;
int to;
double cups;
double ounces;
double table;
double tea;

cout << "Cups = 1, Ounces = 2, Tablespoons = 3, Teaspoons = 4" << endl;
cout << "Conversion From: ";
cin >> from;
// Checks that user input is equal to 1,2,3, or 4
while (((from != 1 && from != 2) && (from != 3 && from != 4))){
  cout << "Please enter a number 1-4." << endl;
  cout << "Conversion From: ";
  cin >> from;
}
cout << "Conversion To: ";
cin >> to;

// Checks that user input is equal to 1,2,3, or 4 and that it is not the same number as from
while (((from != 1 && from != 2) && (from != 3 && from != 4)) || to == from){
  cout << "Please enter a number 1-4 different from your first response." << endl;
  cout << "Conversion To: ";
  cin >> to;
}

switch (from) {
  // Cups
  case 1:
    cout << "Enter the amount in cups: ";
    cin >> cups;
    // Error checks that the value entered is greater than 0
    while (cups < 0){
      cout << "Please enter a non-negative value." << endl;
      cout << "Enter the amount in cups: ";
      cin >> cups;
    }
    // Converts cups and prints output
    cupsconv(cups, to);
    break;

  // Ounces
  case 2:
    cout << "Enter amount in ounces: ";
    cin >> ounces;
    // Error checks that the value entered is greater than 0
    while (ounces < 0){
      cout << "Please enter a non-negative value." << endl;
      cout << "Enter the amount in ounces: ";
      cin >> ounces;
    }
    // Converts ounces and prints output
    ouncesconv(ounces, to);
    break;

  // Tablespoons
  case 3:
    cout << "Enter amount in tablespoons: ";
    cin >> table;
    // Error checks that the value entered is greater than 0
    while (table < 0){
      cout << "Please enter a non-negative value." << endl;
      cout << "Enter the amount in tablespoons: ";
      cin >> table;
    }
    // Converts tablespoons and prints output
    tableconv(table, to);
    break;

  // Teaspoons
  case 4:
    cout << "Enter amount in teaspoons: ";
    cin >> tea;
    // Error checks that the value entered is greater than 0
    while (tea < 0){
      cout << "Please enter a non-negative value." << endl;
      cout << "Enter the amount in teaspoons: ";
      cin >> tea;
    }
    // Converts teaspoons and prints output
    teaconv(tea, to);
    break;
}
return 0;
}
