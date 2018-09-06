#include "shell.h"
#include <sstream>

void Shell::run_shell()
{
    // While the user has not requested to terminate 
    // shell excecution continue
    while(!this->finished)
    {
        string flag;
        cout << this->cwd;
        
        getline(cin, command);
        istringstream iss(command);
        iss >> command >> flag;

        if(command == "quit")
        {
            finished = true;
            continue;
        }
        // command to list the files and folders in directory
        if(command == "ls")
        {
            // user wants to see the permissions
            if( flag == "-l" )
                dir.print_dir_contents_with_permissions();
            // user does not want to see permissions
            else 
                dir.print_dir_contents_without_permissions();
        }
        // display the current working directory
        else if ( command == "pwd" )
        {
            dir.print_dir_path();
        }
        // change directory
        else if ( command == "cd" )
        {
            dir.change_dir(flag);
        }
        else if ( command == "mkdir")
        {
            dir.make_dir(flag);
        }
        else if 
        else
        {
            cout << "INVALID COMMAND" << endl;
        }
        

    }
}