#include <iostream>
#include "Game_Command.h"
#include "Model.h"
#include "View.h"
#include "Input_Handling.h"

using namespace std;

int main()
{
  // Intro statements
  cout << "EC327: Introduction to Software Engineering" << endl;
  cout << "Fall 2017" << endl;
  cout << "Programming Assignment 4" << endl;

  // command holds first char in user input to determine next action
  char command;

  // Initializes m to hold all game information (note does not use copy constructor!)
  Model m;

  View v = View();

  // Begins game with statuses of all objects and the initial display and time
  m.show_status();
  m.display(v);


  while (true) // runs until broken by an exit(0)
  {
    bool show; // stores whether or not a command shows the display after the command

    cout << "Enter a command: ";

    try
    {
      cin >> command; // first command is taken here, all others are taken inside Game_Command functions

      switch (command)
      {
        case 'm':
        {
          do_move_command(m);
          show = false;
          break;
        }
        case 'w':
        {
          do_work_command(m);
          show = false;
          break;
        }
        case 'd':
        {
          do_deposit_command(m);
          show = false;
          break;
        }
        case 's':
        {
          do_stop_command(m);
          show = false;
          break;
        }
        case 'l':
        {
          do_lock_command(m);
          show = false;
          break;
        }
        case 'g':
        {
          do_go_command(m);
          show = true;
          break;
        }
        case 'r':
        {
          do_run_command(m);
          show = true;
          break;
        }
        case 'a':
        {
          do_attack_command(m);
          show = false;
          break;
        }
        case 'q':
        {
          do_quit_command(m);
          break;
        }
        default: // Executes for invalid command codes
        {
          cout << "ERROR: Please enter a valid command!" << endl;
          show = false; // invalid flag
          break;
        }
      }
    }
    catch(Invalid_Input& except)
    {
      cout << "Invalid input - " << except.msg_ptr << endl;
    }
    if (show)
    {
      m.display(v); // only displays if command was valid; displays after every command is executed
    }
  }
  return 0;
}
