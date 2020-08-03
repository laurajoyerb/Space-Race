#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

  double user;
  cout << "Choose Rock (0), Paper (1), or Scissors (2): ";
  cin >> user;
  // Checks that user input is valid
  while (user !=0 && user != 1 && user !=2) {
    cout << "You have to pick either a 0, a 1, or a 2. Try again: ";
    cin >> user;
  }

  // Seed for rand function. This ensures that the program will generate a new random number each time it is run
  srand((int) time(0));

  // %3 gives random integers from 0 to 2
  int com=rand()%3;
  cout << "Computer chooses: ";

  // Prints computer's choice
  if (com==0){
    cout << "Rock" << endl;
  } else if (com ==1){
    cout << "Paper" << endl;
  } else if (com ==2){
    cout << "Scissors" << endl;
  }

  // Manually checks each possibility if the user chooses scissors (2)
  if (user==2) {
    if(com==0) {
      cout << "You lose!" << endl;
    } else if (com == 2) {
      cout << "You tie!" << endl;
    } else if (com == 1) {
      cout << "You win!" << endl;
    }
  } else if(com == 2) { // Manually checks each possibility if computer chooses scissors(2)
    if(user==0) {
      cout << "You win!" << endl;
    } else if (user == 2) {
      cout << "You tie!" << endl;
    } else if (user == 1) {
      cout << "You lose!" << endl;
    }
  } else { // If the user did not select scissors, then the numerical value of the computer's choice decides winner
    // As long as the value is higher than the users, the computer wins
    if (com > user) {
      cout << "You lose!" << endl;
    } else if (com == user) {
      cout << "You tie!" << endl;
    } else {
      cout << "You win!" << endl;
    }
  }

}
