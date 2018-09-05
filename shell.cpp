#include "shell.h"
#include <sstream>

void Shell::run_shell()
{
    // While the user has not requested to terminate 
    // shell excecution continue
    while(!this->finished)
    {
        string flag;
        cout << dir.get_cwd() << "  ";
        
        getline(cin, command);
        istringstream iss(command);
        iss >> command >> flag;

        if(command == "quit")
        {
            finished = true;
            continue;
        }
        // command to list the files and folders in directory
        else if(command == "ls")
        {
            // user wants to see the permissions
            if( flag == "-l" )
                dir.print_dir_contents_with_permissions();
            // user does not want to see permissions
            else if ( flag == "")
                dir.print_dir_contents_without_permissions();
            else 
                cout << "INVALID COMMAND"<< endl;
        }
        // display the current working directory
        else if ( command == "pwd" )
        {
            dir.print_dir_path();
        }
        // change directory
        else if ( command == "cd" )
        {
            if (flag == "~")
                dir.change_to_home_dir();
            else
                dir.change_dir(flag);
        }
        // make directory
        else if ( command == "mkdir" )
        {
            dir.make_dir(flag);
        }
        // make file
        else if ( command == "touch" )
        {
            dir.make_file(flag);
            
        }

        // not a valid command
        else
        {
            cout << "INVALID COMMAND" << endl;
        }
        

    }
}