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

  char mode;

  COMP:try
  {
    cout << "Would you like to play in Normal Mode (n) or in Computer Mode (c)? ";
    cin >> mode;
    if(mode != 'n' && mode != 'c')
    {
      throw Invalid_Input("Enter 'n' for Normal Mode or 'c' for Computer Mode.");
    }
  }
  catch(Invalid_Input& except)
  {
    cout << "ERROR: " << except.msg_ptr << endl;
    cin.clear();
    cin.ignore(256, '\n');
    goto COMP;
  }

  if (mode == 'n')
  {
    m.compMode = false;
  }
  else if (mode == 'c')
  {
    m.compMode = true;
  }

  // Begins game with statuses of all objects and the initial display and time
  m.show_status();
  m.display(v);


  while (true) // runs until broken by an exit(0)
  {
    bool show; // stores whether or not a command shows the display after the command

    cout << "Enter a command: ";

    try
    {
      cin >> command;
      if(cin.fail())
      {
        throw Invalid_Input("Please enter one character as the command.");
      }
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
        case 'n':
        {
          do_new_command(m);
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
          cin.clear();
          cin.ignore(256, '\n');
          show = false;
          break;
        }
      }

      if (show)
      {
        m.display(v); // only displays if command was valid; displays after every command is executed
      }
    }
    catch(Invalid_Input& except)
    {
      cout << "ERROR: " << except.msg_ptr << endl;
      cin.clear();
      cin.ignore(256, '\n');
    }
  }
  return 0;
}
